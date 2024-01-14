#ifndef html_h
#define html_h
// your declarations
#endif

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#include <string>
#include <cstring>
#else
#include "WProgram.h"
#endif

const char *getHomeForm()
{

    const char *homeForm = R"(
    <!DOCTYPE html>
    <html>
    <head>
        <meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=no">
        <style>
            body {
                text-align: center;
                font-family: Arial, sans-serif;
                background-color: #f4f4f4;
                margin: 0;
                padding: 20px;
                display: flex;
                flex-direction: column;
                justify-content: center;
                height: 100vh;
            }
            .button {
                background-color: #067FD0;
                border: none;
                color: white;
                padding: 15px 32px;
                text-align: center;
                text-decoration: none;
                display: inline-block;
                font-size: 16px;
                margin: 4px 2px;
                cursor: pointer;
                border-radius: 4px;
                transition: background-color 0.3s;
            }
            .button:hover {
                background-color: #067FD0;
            }
            .button2 {
                width: 150px;
                font-weight: bold;
            }
            h1 {
                color: #333;
            }
        </style>
    </head>
    <body>
        <h1>Water Dispenser</h1>

        <p><a href="/water"><button class="button button2">Water</button></a></p>
        <p><a href="/config"><button class="button button2">Config</button></a></p>
    </body>
    </html>

    )";
    return homeForm;
}

const char *getConfigForm(int frequency, int duration)
{
    std::string html = R"(
    <!DOCTYPE html>
    <html>
<head>
        <meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=no">
        <style>
            body {
                text-align: center;
                font-family: Arial, sans-serif;
                background-color: #f4f4f4;
                margin: 0;
                padding: 20px;
                display: flex;
                flex-direction: column;
                justify-content: center;
                height: 100vh;
            }
            .button {
                background-color: #067FD0;
                border: none;
                color: white;
                padding: 15px 32px;
                text-align: center;
                text-decoration: none;
                display: inline-block;
                font-size: 16px;
                margin: 4px 2px;
                cursor: pointer;
                border-radius: 4px;
                transition: background-color 0.3s;
            }
            .button:hover {
                background-color: #067FD0;
            }
            .button2 {
                width: 150px;
                font-weight: bold;
            }
            .input-field {
                width: 20%;
                padding: 10px;
                margin: 10px 0;
                border: 1px solid #ddd;
                border-radius: 4px;
            }
            h1 {
                color: #333;
            }
        </style>
    </head>
    <body>

        <h1>Water Dispenser Config</h1>
        <form action="/config" method="post">
            <div>
            <label for="frequency">Frequency (Minutes)</label><br>
            <input type="text" name="frequency" class="input-field" placeholder="Frequency Mins" value=")";

    html += std::to_string(frequency) + R"("><br><br>
            </div>

            <div>
            <label for="duration">Duration (Milliseconds)</label><br>
            <input type="text" name="duration" class="input-field" placeholder="Duration Milliseconds" value=")";

    html += std::to_string(duration) + R"("><br><br>
            </div>
            <input type="submit" value="Submit" class="button button2">
            <div>
        </form>

    </body>
    </html>
    )";

    // Allocate memory for the C-string
    char *cstr = new char[html.length() + 1];
    strcpy(cstr, html.c_str());
    return cstr;
}