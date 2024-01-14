#ifndef music_h
#define music_h
// your declarations
#endif

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#include <ctime>
#else
#include "WProgram.h"
#endif

// change this to make the song slower or faster
void playNoise(const int *melody, int tempo, int buzzerPin, size_t size)
{
    // Calculate the number of notes in the melody
    int notes = size / 2;

    // this calculates the duration of a whole note in ms
    int wholenote = (60000 * 4) / tempo;

    int divider = 0, noteDuration = 0;

    Serial.println("Playing noise");

    for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2)
    {
        // Use pgm_read_word_near to read data from flash memory
        int note = pgm_read_word_near(&melody[thisNote]);
        divider = pgm_read_word_near(&melody[thisNote + 1]);

        if (divider > 0)
        {
            noteDuration = (wholenote) / divider;
        }
        else if (divider < 0)
        {
            noteDuration = (wholenote) / abs(divider);
            noteDuration *= 1.5;
        }

        tone(buzzerPin, note, noteDuration * 0.9);
        delay(noteDuration);
        noTone(buzzerPin);
    }
}

void furElise(int buzzerPin)
{

    const int NOTE_B0 = 31;
    const int NOTE_C1 = 33;
    const int NOTE_CS1 = 35;
    const int NOTE_D1 = 37;
    const int NOTE_DS1 = 39;
    const int NOTE_E1 = 41;
    const int NOTE_F1 = 44;
    const int NOTE_FS1 = 46;
    const int NOTE_G1 = 49;
    const int NOTE_GS1 = 52;
    const int NOTE_A1 = 55;
    const int NOTE_AS1 = 58;
    const int NOTE_B1 = 62;
    const int NOTE_C2 = 65;
    const int NOTE_CS2 = 69;
    const int NOTE_D2 = 73;
    const int NOTE_DS2 = 78;
    const int NOTE_E2 = 82;
    const int NOTE_F2 = 87;
    const int NOTE_FS2 = 93;
    const int NOTE_G2 = 98;
    const int NOTE_GS2 = 104;
    const int NOTE_A2 = 110;
    const int NOTE_AS2 = 117;
    const int NOTE_B2 = 123;
    const int NOTE_C3 = 131;
    const int NOTE_CS3 = 139;
    const int NOTE_D3 = 147;
    const int NOTE_DS3 = 156;
    const int NOTE_E3 = 165;
    const int NOTE_F3 = 175;
    const int NOTE_FS3 = 185;
    const int NOTE_G3 = 196;
    const int NOTE_GS3 = 208;
    const int NOTE_A3 = 220;
    const int NOTE_AS3 = 233;
    const int NOTE_B3 = 247;
    const int NOTE_C4 = 262;
    const int NOTE_CS4 = 277;
    const int NOTE_D4 = 294;
    const int NOTE_DS4 = 311;
    const int NOTE_E4 = 330;
    const int NOTE_F4 = 349;
    const int NOTE_FS4 = 370;
    const int NOTE_G4 = 392;
    const int NOTE_GS4 = 415;
    const int NOTE_A4 = 440;
    const int NOTE_AS4 = 466;
    const int NOTE_B4 = 494;
    const int NOTE_C5 = 523;
    const int NOTE_CS5 = 554;
    const int NOTE_D5 = 587;
    const int NOTE_DS5 = 622;
    const int NOTE_E5 = 659;
    const int NOTE_F5 = 698;
    const int NOTE_FS5 = 740;
    const int NOTE_G5 = 784;
    const int NOTE_GS5 = 831;
    const int NOTE_A5 = 880;
    const int NOTE_AS5 = 932;
    const int NOTE_B5 = 988;
    const int NOTE_C6 = 1047;
    const int NOTE_CS6 = 1109;
    const int NOTE_D6 = 1175;
    const int NOTE_DS6 = 1245;
    const int NOTE_E6 = 1319;
    const int NOTE_F6 = 1397;
    const int NOTE_FS6 = 1480;
    const int NOTE_G6 = 1568;
    const int NOTE_GS6 = 1661;
    const int NOTE_A6 = 1760;
    const int NOTE_AS6 = 1865;
    const int NOTE_B6 = 1976;
    const int NOTE_C7 = 2093;
    const int NOTE_CS7 = 2217;
    const int NOTE_D7 = 2349;
    const int NOTE_DS7 = 2489;
    const int NOTE_E7 = 2637;
    const int NOTE_F7 = 2794;
    const int NOTE_FS7 = 2960;
    const int NOTE_G7 = 3136;
    const int NOTE_GS7 = 3322;
    const int NOTE_A7 = 3520;
    const int NOTE_AS7 = 3729;
    const int NOTE_B7 = 3951;
    const int NOTE_C8 = 4186;
    const int NOTE_CS8 = 4435;
    const int NOTE_D8 = 4699;
    const int NOTE_DS8 = 4978;
    const int REST = 0;

    int tempo = 80;

    const int melody[] PROGMEM = {

        // starts from 1 ending on 9
        NOTE_E5, 16, NOTE_DS5, 16, // 1
        NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
        NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
        NOTE_B4, -8, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,
        NOTE_C5, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16, NOTE_DS5, 16,

        NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16, // 6
        NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
        NOTE_B4, -8, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16,
        NOTE_A4, 4, REST, 8, // 9 - 1st ending
    };

    playNoise(melody, tempo, buzzerPin, sizeof(melody) / sizeof(melody[0]));
}

void harryPotter(int buzzerPin)
{

    const int NOTE_B0 = 31;
    const int NOTE_C1 = 33;
    const int NOTE_CS1 = 35;
    const int NOTE_D1 = 37;
    const int NOTE_DS1 = 39;
    const int NOTE_E1 = 41;
    const int NOTE_F1 = 44;
    const int NOTE_FS1 = 46;
    const int NOTE_G1 = 49;
    const int NOTE_GS1 = 52;
    const int NOTE_A1 = 55;
    const int NOTE_AS1 = 58;
    const int NOTE_B1 = 62;
    const int NOTE_C2 = 65;
    const int NOTE_CS2 = 69;
    const int NOTE_D2 = 73;
    const int NOTE_DS2 = 78;
    const int NOTE_E2 = 82;
    const int NOTE_F2 = 87;
    const int NOTE_FS2 = 93;
    const int NOTE_G2 = 98;
    const int NOTE_GS2 = 104;
    const int NOTE_A2 = 110;
    const int NOTE_AS2 = 117;
    const int NOTE_B2 = 123;
    const int NOTE_C3 = 131;
    const int NOTE_CS3 = 139;
    const int NOTE_D3 = 147;
    const int NOTE_DS3 = 156;
    const int NOTE_E3 = 165;
    const int NOTE_F3 = 175;
    const int NOTE_FS3 = 185;
    const int NOTE_G3 = 196;
    const int NOTE_GS3 = 208;
    const int NOTE_A3 = 220;
    const int NOTE_AS3 = 233;
    const int NOTE_B3 = 247;
    const int NOTE_C4 = 262;
    const int NOTE_CS4 = 277;
    const int NOTE_D4 = 294;
    const int NOTE_DS4 = 311;
    const int NOTE_E4 = 330;
    const int NOTE_F4 = 349;
    const int NOTE_FS4 = 370;
    const int NOTE_G4 = 392;
    const int NOTE_GS4 = 415;
    const int NOTE_A4 = 440;
    const int NOTE_AS4 = 466;
    const int NOTE_B4 = 494;
    const int NOTE_C5 = 523;
    const int NOTE_CS5 = 554;
    const int NOTE_D5 = 587;
    const int NOTE_DS5 = 622;
    const int NOTE_E5 = 659;
    const int NOTE_F5 = 698;
    const int NOTE_FS5 = 740;
    const int NOTE_G5 = 784;
    const int NOTE_GS5 = 831;
    const int NOTE_A5 = 880;
    const int NOTE_AS5 = 932;
    const int NOTE_B5 = 988;
    const int NOTE_C6 = 1047;
    const int NOTE_CS6 = 1109;
    const int NOTE_D6 = 1175;
    const int NOTE_DS6 = 1245;
    const int NOTE_E6 = 1319;
    const int NOTE_F6 = 1397;
    const int NOTE_FS6 = 1480;
    const int NOTE_G6 = 1568;
    const int NOTE_GS6 = 1661;
    const int NOTE_A6 = 1760;
    const int NOTE_AS6 = 1865;
    const int NOTE_B6 = 1976;
    const int NOTE_C7 = 2093;
    const int NOTE_CS7 = 2217;
    const int NOTE_D7 = 2349;
    const int NOTE_DS7 = 2489;
    const int NOTE_E7 = 2637;
    const int NOTE_F7 = 2794;
    const int NOTE_FS7 = 2960;
    const int NOTE_G7 = 3136;
    const int NOTE_GS7 = 3322;
    const int NOTE_A7 = 3520;
    const int NOTE_AS7 = 3729;
    const int NOTE_B7 = 3951;
    const int NOTE_C8 = 4186;
    const int NOTE_CS8 = 4435;
    const int NOTE_D8 = 4699;
    const int NOTE_DS8 = 4978;
    const int REST = 0;

    int tempo = 144;

    int melody[] = {
        REST,
        2,
        NOTE_D4,
        4,
        NOTE_G4,
        -4,
        NOTE_AS4,
        8,
        NOTE_A4,
        4,
        NOTE_G4,
        2,
        NOTE_D5,
        4,
        NOTE_C5,
        -2,
        NOTE_A4,
        -2,
        NOTE_G4,
        -4,
        NOTE_AS4,
        8,
        NOTE_A4,
        4,
        NOTE_F4,
        2,
        NOTE_GS4,
        4,
        NOTE_D4,
        -1,
        NOTE_D4,
        4,

        NOTE_G4,
        -4,
        NOTE_AS4,
        8,
        NOTE_A4,
        4, // 10
        NOTE_G4,
        2,
        NOTE_D5,
        4,
        NOTE_F5,
        2,
        NOTE_E5,
        4,
        NOTE_DS5,
        2,
        NOTE_B4,
        4,
        NOTE_DS5,
        -4,
        NOTE_D5,
        8,
        NOTE_CS5,
        4,
        NOTE_CS4,
        2,
        NOTE_B4,
        4,
        NOTE_G4,
        -1,
        NOTE_AS4,
        4,
    };

    playNoise(melody, tempo, buzzerPin, sizeof(melody) / sizeof(melody[0]));
}

void canonInD(int buzzerPin)
{
    const int NOTE_B0 = 31;
    const int NOTE_C1 = 33;
    const int NOTE_CS1 = 35;
    const int NOTE_D1 = 37;
    const int NOTE_DS1 = 39;
    const int NOTE_E1 = 41;
    const int NOTE_F1 = 44;
    const int NOTE_FS1 = 46;
    const int NOTE_G1 = 49;
    const int NOTE_GS1 = 52;
    const int NOTE_A1 = 55;
    const int NOTE_AS1 = 58;
    const int NOTE_B1 = 62;
    const int NOTE_C2 = 65;
    const int NOTE_CS2 = 69;
    const int NOTE_D2 = 73;
    const int NOTE_DS2 = 78;
    const int NOTE_E2 = 82;
    const int NOTE_F2 = 87;
    const int NOTE_FS2 = 93;
    const int NOTE_G2 = 98;
    const int NOTE_GS2 = 104;
    const int NOTE_A2 = 110;
    const int NOTE_AS2 = 117;
    const int NOTE_B2 = 123;
    const int NOTE_C3 = 131;
    const int NOTE_CS3 = 139;
    const int NOTE_D3 = 147;
    const int NOTE_DS3 = 156;
    const int NOTE_E3 = 165;
    const int NOTE_F3 = 175;
    const int NOTE_FS3 = 185;
    const int NOTE_G3 = 196;
    const int NOTE_GS3 = 208;
    const int NOTE_A3 = 220;
    const int NOTE_AS3 = 233;
    const int NOTE_B3 = 247;
    const int NOTE_C4 = 262;
    const int NOTE_CS4 = 277;
    const int NOTE_D4 = 294;
    const int NOTE_DS4 = 311;
    const int NOTE_E4 = 330;
    const int NOTE_F4 = 349;
    const int NOTE_FS4 = 370;
    const int NOTE_G4 = 392;
    const int NOTE_GS4 = 415;
    const int NOTE_A4 = 440;
    const int NOTE_AS4 = 466;
    const int NOTE_B4 = 494;
    const int NOTE_C5 = 523;
    const int NOTE_CS5 = 554;
    const int NOTE_D5 = 587;
    const int NOTE_DS5 = 622;
    const int NOTE_E5 = 659;
    const int NOTE_F5 = 698;
    const int NOTE_FS5 = 740;
    const int NOTE_G5 = 784;
    const int NOTE_GS5 = 831;
    const int NOTE_A5 = 880;
    const int NOTE_AS5 = 932;
    const int NOTE_B5 = 988;
    const int NOTE_C6 = 1047;
    const int NOTE_CS6 = 1109;
    const int NOTE_D6 = 1175;
    const int NOTE_DS6 = 1245;
    const int NOTE_E6 = 1319;
    const int NOTE_F6 = 1397;
    const int NOTE_FS6 = 1480;
    const int NOTE_G6 = 1568;
    const int NOTE_GS6 = 1661;
    const int NOTE_A6 = 1760;
    const int NOTE_AS6 = 1865;
    const int NOTE_B6 = 1976;
    const int NOTE_C7 = 2093;
    const int NOTE_CS7 = 2217;
    const int NOTE_D7 = 2349;
    const int NOTE_DS7 = 2489;
    const int NOTE_E7 = 2637;
    const int NOTE_F7 = 2794;
    const int NOTE_FS7 = 2960;
    const int NOTE_G7 = 3136;
    const int NOTE_GS7 = 3322;
    const int NOTE_A7 = 3520;
    const int NOTE_AS7 = 3729;
    const int NOTE_B7 = 3951;
    const int NOTE_C8 = 4186;
    const int NOTE_CS8 = 4435;
    const int NOTE_D8 = 4699;
    const int NOTE_DS8 = 4978;
    const int REST = 0;

    int tempo = 100;

    int melody[] = {
        NOTE_FS4,
        2,
        NOTE_E4,
        2,
        NOTE_D4,
        2,
        NOTE_CS4,
        2,
        NOTE_B3,
        2,
        NOTE_A3,
        2,
        NOTE_B3,
        2,
        NOTE_CS4,
        2,
        NOTE_FS4,
        2,
        NOTE_E4,
        2,
        NOTE_D4,
        2,
        NOTE_CS4,
        2,
        NOTE_B3,
        2,
        NOTE_A3,
        2,
        NOTE_B3,
        2,
        NOTE_CS4,
        2,
        NOTE_D4,
        2,
        NOTE_CS4,
        2,
        NOTE_B3,
        2,
        NOTE_A3,
        2,
        NOTE_G3,
        2,
        NOTE_FS3,
        2,
        NOTE_G3,
        2,
        NOTE_A3,
        2,

        NOTE_D4,
        4,
        NOTE_FS4,
        8,
        NOTE_G4,
        8,
        NOTE_A4,
        4,
        NOTE_FS4,
        8,
        NOTE_G4,
        8,
        NOTE_A4,
        4,
        NOTE_B3,
        8,
        NOTE_CS4,
        8,
        NOTE_D4,
        8,
        NOTE_E4,
        8,
        NOTE_FS4,
        8,
        NOTE_G4,
        8,
        NOTE_FS4,
        4,
        NOTE_D4,
        8,
        NOTE_E4,
        8,
        NOTE_FS4,
        4,
        NOTE_FS3,
        8,
        NOTE_G3,
        8,
        NOTE_A3,
        8,
        NOTE_G3,
        8,
        NOTE_FS3,
        8,
        NOTE_G3,
        8,
        NOTE_A3,
        2,
        NOTE_G3,
        4,
        NOTE_B3,
        8,
        NOTE_A3,
        8,
        NOTE_G3,
        4,
        NOTE_FS3,
        8,
        NOTE_E3,
        8,
        NOTE_FS3,
        4,
        NOTE_D3,
        8,
        NOTE_E3,
        8,
        NOTE_FS3,
        8,
        NOTE_G3,
        8,
        NOTE_A3,
        8,
        NOTE_B3,
        8,
    };

    playNoise(melody, tempo, buzzerPin, sizeof(melody) / sizeof(melody[0]));
}

void takeOnMe(int buzzerPin)
{
    const int NOTE_B0 = 31;
    const int NOTE_C1 = 33;
    const int NOTE_CS1 = 35;
    const int NOTE_D1 = 37;
    const int NOTE_DS1 = 39;
    const int NOTE_E1 = 41;
    const int NOTE_F1 = 44;
    const int NOTE_FS1 = 46;
    const int NOTE_G1 = 49;
    const int NOTE_GS1 = 52;
    const int NOTE_A1 = 55;
    const int NOTE_AS1 = 58;
    const int NOTE_B1 = 62;
    const int NOTE_C2 = 65;
    const int NOTE_CS2 = 69;
    const int NOTE_D2 = 73;
    const int NOTE_DS2 = 78;
    const int NOTE_E2 = 82;
    const int NOTE_F2 = 87;
    const int NOTE_FS2 = 93;
    const int NOTE_G2 = 98;
    const int NOTE_GS2 = 104;
    const int NOTE_A2 = 110;
    const int NOTE_AS2 = 117;
    const int NOTE_B2 = 123;
    const int NOTE_C3 = 131;
    const int NOTE_CS3 = 139;
    const int NOTE_D3 = 147;
    const int NOTE_DS3 = 156;
    const int NOTE_E3 = 165;
    const int NOTE_F3 = 175;
    const int NOTE_FS3 = 185;
    const int NOTE_G3 = 196;
    const int NOTE_GS3 = 208;
    const int NOTE_A3 = 220;
    const int NOTE_AS3 = 233;
    const int NOTE_B3 = 247;
    const int NOTE_C4 = 262;
    const int NOTE_CS4 = 277;
    const int NOTE_D4 = 294;
    const int NOTE_DS4 = 311;
    const int NOTE_E4 = 330;
    const int NOTE_F4 = 349;
    const int NOTE_FS4 = 370;
    const int NOTE_G4 = 392;
    const int NOTE_GS4 = 415;
    const int NOTE_A4 = 440;
    const int NOTE_AS4 = 466;
    const int NOTE_B4 = 494;
    const int NOTE_C5 = 523;
    const int NOTE_CS5 = 554;
    const int NOTE_D5 = 587;
    const int NOTE_DS5 = 622;
    const int NOTE_E5 = 659;
    const int NOTE_F5 = 698;
    const int NOTE_FS5 = 740;
    const int NOTE_G5 = 784;
    const int NOTE_GS5 = 831;
    const int NOTE_A5 = 880;
    const int NOTE_AS5 = 932;
    const int NOTE_B5 = 988;
    const int NOTE_C6 = 1047;
    const int NOTE_CS6 = 1109;
    const int NOTE_D6 = 1175;
    const int NOTE_DS6 = 1245;
    const int NOTE_E6 = 1319;
    const int NOTE_F6 = 1397;
    const int NOTE_FS6 = 1480;
    const int NOTE_G6 = 1568;
    const int NOTE_GS6 = 1661;
    const int NOTE_A6 = 1760;
    const int NOTE_AS6 = 1865;
    const int NOTE_B6 = 1976;
    const int NOTE_C7 = 2093;
    const int NOTE_CS7 = 2217;
    const int NOTE_D7 = 2349;
    const int NOTE_DS7 = 2489;
    const int NOTE_E7 = 2637;
    const int NOTE_F7 = 2794;
    const int NOTE_FS7 = 2960;
    const int NOTE_G7 = 3136;
    const int NOTE_GS7 = 3322;
    const int NOTE_A7 = 3520;
    const int NOTE_AS7 = 3729;
    const int NOTE_B7 = 3951;
    const int NOTE_C8 = 4186;
    const int NOTE_CS8 = 4435;
    const int NOTE_D8 = 4699;
    const int NOTE_DS8 = 4978;
    const int REST = 0;

    int tempo = 140;

    int melody[] = {
        NOTE_FS5,
        8,
        NOTE_FS5,
        8,
        NOTE_D5,
        8,
        NOTE_B4,
        8,
        REST,
        8,
        NOTE_B4,
        8,
        REST,
        8,
        NOTE_E5,
        8,
        REST,
        8,
        NOTE_E5,
        8,
        REST,
        8,
        NOTE_E5,
        8,
        NOTE_GS5,
        8,
        NOTE_GS5,
        8,
        NOTE_A5,
        8,
        NOTE_B5,
        8,
        NOTE_A5,
        8,
        NOTE_A5,
        8,
        NOTE_A5,
        8,
        NOTE_E5,
        8,
        REST,
        8,
        NOTE_D5,
        8,
        REST,
        8,
        NOTE_FS5,
        8,
        REST,
        8,
        NOTE_FS5,
        8,
        REST,
        8,
        NOTE_FS5,
        8,
        NOTE_E5,
        8,
        NOTE_E5,
        8,
        NOTE_FS5,
        8,
        NOTE_E5,
        8,
        NOTE_FS5,
        8,
        NOTE_FS5,
        8,
        NOTE_D5,
        8,
        NOTE_B4,
        8,
        REST,
        8,
        NOTE_B4,
        8,
        REST,
        8,
        NOTE_E5,
        8,
    };

    playNoise(melody, tempo, buzzerPin, sizeof(melody) / sizeof(melody[0]));
}

void gameOfThrones(int buzzerPin)
{

    int tempo = 85;

    const int NOTE_B0 = 31;
    const int NOTE_C1 = 33;
    const int NOTE_CS1 = 35;
    const int NOTE_D1 = 37;
    const int NOTE_DS1 = 39;
    const int NOTE_E1 = 41;
    const int NOTE_F1 = 44;
    const int NOTE_FS1 = 46;
    const int NOTE_G1 = 49;
    const int NOTE_GS1 = 52;
    const int NOTE_A1 = 55;
    const int NOTE_AS1 = 58;
    const int NOTE_B1 = 62;
    const int NOTE_C2 = 65;
    const int NOTE_CS2 = 69;
    const int NOTE_D2 = 73;
    const int NOTE_DS2 = 78;
    const int NOTE_E2 = 82;
    const int NOTE_F2 = 87;
    const int NOTE_FS2 = 93;
    const int NOTE_G2 = 98;
    const int NOTE_GS2 = 104;
    const int NOTE_A2 = 110;
    const int NOTE_AS2 = 117;
    const int NOTE_B2 = 123;
    const int NOTE_C3 = 131;
    const int NOTE_CS3 = 139;
    const int NOTE_D3 = 147;
    const int NOTE_DS3 = 156;
    const int NOTE_E3 = 165;
    const int NOTE_F3 = 175;
    const int NOTE_FS3 = 185;
    const int NOTE_G3 = 196;
    const int NOTE_GS3 = 208;
    const int NOTE_A3 = 220;
    const int NOTE_AS3 = 233;
    const int NOTE_B3 = 247;
    const int NOTE_C4 = 262;
    const int NOTE_CS4 = 277;
    const int NOTE_D4 = 294;
    const int NOTE_DS4 = 311;
    const int NOTE_E4 = 330;
    const int NOTE_F4 = 349;
    const int NOTE_FS4 = 370;
    const int NOTE_G4 = 392;
    const int NOTE_GS4 = 415;
    const int NOTE_A4 = 440;
    const int NOTE_AS4 = 466;
    const int NOTE_B4 = 494;
    const int NOTE_C5 = 523;
    const int NOTE_CS5 = 554;
    const int NOTE_D5 = 587;
    const int NOTE_DS5 = 622;
    const int NOTE_E5 = 659;
    const int NOTE_F5 = 698;
    const int NOTE_FS5 = 740;
    const int NOTE_G5 = 784;
    const int NOTE_GS5 = 831;
    const int NOTE_A5 = 880;
    const int NOTE_AS5 = 932;
    const int NOTE_B5 = 988;
    const int NOTE_C6 = 1047;
    const int NOTE_CS6 = 1109;
    const int NOTE_D6 = 1175;
    const int NOTE_DS6 = 1245;
    const int NOTE_E6 = 1319;
    const int NOTE_F6 = 1397;
    const int NOTE_FS6 = 1480;
    const int NOTE_G6 = 1568;
    const int NOTE_GS6 = 1661;
    const int NOTE_A6 = 1760;
    const int NOTE_AS6 = 1865;
    const int NOTE_B6 = 1976;
    const int NOTE_C7 = 2093;
    const int NOTE_CS7 = 2217;
    const int NOTE_D7 = 2349;
    const int NOTE_DS7 = 2489;
    const int NOTE_E7 = 2637;
    const int NOTE_F7 = 2794;
    const int NOTE_FS7 = 2960;
    const int NOTE_G7 = 3136;
    const int NOTE_GS7 = 3322;
    const int NOTE_A7 = 3520;
    const int NOTE_AS7 = 3729;
    const int NOTE_B7 = 3951;
    const int NOTE_C8 = 4186;
    const int NOTE_CS8 = 4435;
    const int NOTE_D8 = 4699;
    const int NOTE_DS8 = 4978;
    const int REST = 0;

    int melody[] = {
        NOTE_G4, 8, NOTE_C4, 8, NOTE_DS4, 16, NOTE_F4, 16, NOTE_G4, 8, NOTE_C4, 8, NOTE_DS4, 16, NOTE_F4, 16, // 1
        NOTE_G4, 8, NOTE_C4, 8, NOTE_DS4, 16, NOTE_F4, 16, NOTE_G4, 8, NOTE_C4, 8, NOTE_DS4, 16, NOTE_F4, 16,
        NOTE_G4, 8, NOTE_C4, 8, NOTE_E4, 16, NOTE_F4, 16, NOTE_G4, 8, NOTE_C4, 8, NOTE_E4, 16, NOTE_F4, 16,
        NOTE_G4, 8, NOTE_C4, 8, NOTE_E4, 16, NOTE_F4, 16, NOTE_G4, 8, NOTE_C4, 8, NOTE_E4, 16, NOTE_F4, 16,
        NOTE_G4, -4, NOTE_C4, -4, // 5

        NOTE_DS4, 16, NOTE_F4, 16, NOTE_G4, 4, NOTE_C4, 4, NOTE_DS4, 16, NOTE_F4, 16, // 6
        NOTE_D4, -1,                                                                  // 7 and 8
        NOTE_F4, -4, NOTE_AS3, -4,
        NOTE_DS4, 16, NOTE_D4, 16, NOTE_F4, 4, NOTE_AS3, -4,
        NOTE_DS4, 16, NOTE_D4, 16, NOTE_C4, -1, // 11 and 12
    };

    playNoise(melody, tempo, buzzerPin, sizeof(melody) / sizeof(melody[0]));
}

typedef void (*FunctionPointer)(int);

void playRandom(int buzzerPin)
{
    FunctionPointer functions[] = {furElise, canonInD, takeOnMe, gameOfThrones, harryPotter};

    // Initialize random seed
    std::srand(std::time(nullptr));

    // Generate a random index between 0 and 4
    int randomIndex = std::rand() % 4;

    // Call the selected function
    functions[randomIndex](buzzerPin);
}
