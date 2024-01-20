#include <Arduino.h>
#include <WiFi.h>
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include <ESPmDNS.h>
#include <ArduinoJson.h> //https://github.com/bblanchon/ArduinoJson
#include "SPIFFS.h"
#include <HTTPClient.h>
#include <TaskScheduler.h>
#include <music.h>
#include <html.h>

// Define GPIO pins
const int relayPin = 12;      // GPIO pin number connected to relay IN
const int buzzerPin = 15;     // GPIO pin number connected to buzzer
const int waterSensorPin = 4; // GPIO pin number connected to water
const int builtInLEDPin = 2;  // GPIO pin number connected to on board LED

int waterFrequency = 30;
int waterDuration = 3000;
bool mDNSFailed = false;

bool shouldWater()
{
  bool canWater = true;
  if (digitalRead(waterSensorPin) == LOW)
  {
    // If the pin is HIGH, water is detected
    canWater = false;
  }
  return canWater;
}

void water(int delayMs)
{
  if (shouldWater())
  {
    Serial.println("Watering...");
    digitalWrite(relayPin, HIGH); // Turn on the relay
    delay(delayMs);               // Wait for 10 second
    digitalWrite(relayPin, LOW);  // Turn off the relay
    Serial.println("Done Watering...");
  }
  else
  {
    Serial.println("Water detected, skipping watering...");
  }
}

void waterTaskCallback()
{
  if (shouldWater())
  {
    water(waterDuration);

    // Get current time
    time_t now;
    struct tm timeinfo;
    time(&now);
    localtime_r(&now, &timeinfo);

    // Check if current time is between 6:30 AM and 6:30 PM
    if ((timeinfo.tm_hour > 6 || (timeinfo.tm_hour == 6 && timeinfo.tm_min >= 30)) &&
        (timeinfo.tm_hour < 18 || (timeinfo.tm_hour == 18 && timeinfo.tm_min <= 30)))
    {
      playRandom(buzzerPin);
    }
  }
}

Task tWaterTask(waterFrequency *TASK_MINUTE, TASK_FOREVER, &waterTaskCallback);

// Define states
enum WiFiState
{
  ACCESS_POINT,
  STATION_MODE,
};

// Variable to keep track of WiFi state
WiFiState currentState;
WebServer server(80);
Scheduler ts;

void updateWaterTaskFrequency(int newFrequency)
{
  Serial.println("Updating task frequency");
  tWaterTask.disable();                               // Disable the task
  tWaterTask.setInterval(newFrequency * TASK_MINUTE); // Update the interval
  tWaterTask.enableDelayed();                         // Enable the task again
  tWaterTask.restart();
  Serial.println("Done updating task frequency");
}

// Forward declarations
void handle_OnConnect();
void handle_NotFound();
void handle_Water();

void saveSettings(const char *path, int frequency, int duration)
{
  File configFile = SPIFFS.open(path, FILE_WRITE);
  if (!configFile)
  {
    Serial.println("Failed to open config file for writing");
    return;
  }

  DynamicJsonDocument doc(1024);
  doc["frequency"] = frequency;
  doc["duration"] = duration;
  serializeJson(doc, configFile);
  configFile.close();
}

// Function to load settings from config.json
void loadSettings(const char *path)
{
  File configFile = SPIFFS.open(path, FILE_READ);
  if (!configFile)
  {
    Serial.println("Failed to open config file for reading");
    return;
  }

  size_t size = configFile.size();
  std::unique_ptr<char[]> buf(new char[size]);
  configFile.readBytes(buf.get(), size);

  DynamicJsonDocument doc(1024);
  auto error = deserializeJson(doc, buf.get());
  if (error)
  {
    Serial.println("Failed to parse config file");
    return;
  }

  waterFrequency = doc["frequency"] | waterFrequency; // Use default if not set
  waterDuration = doc["duration"] | waterDuration;    // Use default if not set
}

// Handlers
void handle_OnConnect()
{
  server.send(200, "text/html", getHomeForm());
}

void handle_NotFound()
{
  server.send(404, "text/plain", "Not found");
}

void handle_Water()
{
  if (shouldWater())
  {
    int waterResult = digitalRead(waterSensorPin);
    Serial.println(waterFrequency);
    Serial.println(waterDuration);
    water(waterDuration);
    playRandom(buzzerPin);
  }
  server.sendHeader("Location", "/"); // Set the redirect location to root
  server.send(302);                   // Send a 302 redirect response
}

void handle_ConfigGet()
{
  server.send(200, "text/html", getConfigForm(waterFrequency, waterDuration));
}

void handle_ConfigPost()
{

  if (server.hasArg("frequency") && server.hasArg("duration"))
  {
    int frequency = server.arg("frequency").toInt();
    int duration = server.arg("duration").toInt();

    // Save settings to SPIFFS
    saveSettings("/config.json", frequency, duration);

    // Update global variables
    waterFrequency = frequency;
    waterDuration = duration;

    updateWaterTaskFrequency(waterFrequency);
  }
  server.sendHeader("Location", "/"); // Set the redirect location to root
  server.send(302);                   // Send a 302 redirect response
}

void handle_Diagnostic()
{
  String json = "{";
  json += "\"heap\": " + String(ESP.getFreeHeap());
  json += ", \"maxAllocHeap\": " + String(ESP.getMaxAllocHeap());
  json += ", \"chipId\": \"" + String((uint32_t)ESP.getEfuseMac(), HEX) + "\"";
  json += ", \"sdkVersion\": \"" + String(ESP.getSdkVersion()) + "\"";
  json += ", \"shouldWater\": \"" + String(shouldWater()) + "\"";
  json += ", \"mDNSFailed\": \"" + String(mDNSFailed) + "\"";
  json += "}";
  server.send(200, "application/json", json);
}

void setup()
{

  Serial.begin(9600);

  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(waterSensorPin, INPUT_PULLUP); // Set the water sensor pin as input
  pinMode(builtInLEDPin, OUTPUT);

  // Initialize and configure NTP for Denver, Colorado (Mountain Time Zone)
  configTime(-7 * 3600, 3600, "pool.ntp.org", "time.nist.gov"); // UTC-7 hours offset, 3600 seconds for DST
  setenv("TZ", "MST7MDT,M3.2.0,M11.1.0", 1);                    // Set timezone to Mountain Time with DST rules
  tzset();                                                      // Apply the timezone settings

  if (!SPIFFS.begin(true))
  {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  // Load settings from SPIFFS
  loadSettings("/config.json");

  // Add the water task to the scheduler
  ts.startNow();
  ts.addTask(tWaterTask);
  tWaterTask.setInterval(waterFrequency * TASK_MINUTE);
  tWaterTask.enable();

  // Initialize WiFi
  WiFi.mode(WIFI_STA);
  WiFiManager wm;
  if (wm.autoConnect("water-dispenser"))
  {
    Serial.println("Connected to WiFi!");
    currentState = STATION_MODE;
  }

  if (currentState == STATION_MODE)
  {
    if (!MDNS.begin("water2"))
    {
      Serial.println("Error setting up MDNS responder!");
      digitalWrite(builtInLEDPin, HIGH); // Turn the LED on
      mDNSFailed = true;
    }

    Serial.println("mDNS responder started");

    server.on("/", handle_OnConnect);
    server.on("/water", handle_Water);
    server.on("/config", HTTP_GET, handle_ConfigGet);
    server.on("/config", HTTP_POST, handle_ConfigPost);
    server.on("/diagnostic", HTTP_GET, handle_Diagnostic);
    server.onNotFound(handle_NotFound);

    server.begin();
    Serial.println("HTTP server started");
  }
}

void loop()
{
  // Execute scheduled tasks
  ts.execute();

  // Listen for clients
  server.handleClient();
}
