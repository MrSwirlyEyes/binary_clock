// Binary Clock Logic Simulation + LED Array Prototype on the Arduino UNO
//
// Tests the Binary CLK Logic code
//  by looping through all 60 minutes
//  in a 24 hour time period.
// Toggles appropriate LEDs to represent
//  every time combination



#include <ds3231.h>

#define NUM_LEDS 13

// hour MSD
#define h_MSD_1 12
#define h_MSD_2 11

// hour LSD
#define h_LSD_1 10
#define h_LSD_2 9
#define h_LSD_4 8
#define h_LSD_8 7

// min MSD
#define m_MSD_1 6
#define m_MSD_2 5
#define m_MSD_4 4

// min LSD
#define m_LSD_1 3
#define m_LSD_2 2
#define m_LSD_4 1
#define m_LSD_8 0

uint8_t leds[NUM_LEDS] = {
  h_MSD_1,
  h_MSD_2,
  h_LSD_1,
  h_LSD_2,
  h_LSD_4,
  h_LSD_8,
  m_MSD_1,
  m_MSD_2,
  m_MSD_4,
  m_LSD_1,
  m_LSD_2,
  m_LSD_4,
  m_LSD_8
};

// Instantiate RTC DS3231 object
DS3231 rtc = DS3231();



void setup() {
  // Configure ALL led pins to be a digital OUTPUT
  for (uint8_t i = 0; i < NUM_LEDS; i++)
    pinMode(leds[i],OUTPUT);
}



void loop() {
  // Loop through all 24 hours
  for (uint8_t h = 0; h < 24; h++) {

    // Loop through all 60 minutes
    for (uint8_t m = 0; m < 60; m++) {

      // Obtain LSD of hour and minute
      uint8_t mLSD = m % 10;
      uint8_t hLSD = h % 10;

      // Toggle LEDs for hour MSD
      if (h >= 10 && h < 20)
        digitalWrite(h_MSD_1,HIGH);
      else
        digitalWrite(h_MSD_1,LOW);
      if (h >= 20 && h < 24)
        digitalWrite(h_MSD_2,HIGH);
      else
        digitalWrite(h_MSD_2,LOW);

      // Toggle LEDs for hour LSD
      if (hLSD == 1 || hLSD == 3 || hLSD == 5 || hLSD == 7 || hLSD == 9)
        digitalWrite(h_LSD_1,HIGH);
      else
        digitalWrite(h_LSD_1,LOW);
      if (hLSD == 2 || hLSD == 3 || hLSD == 6 || hLSD == 7)
        digitalWrite(h_LSD_2,HIGH);
      else
        digitalWrite(h_LSD_2,LOW);
      if (hLSD == 4 || hLSD == 5 || hLSD == 6 || hLSD == 7)
        digitalWrite(h_LSD_4,HIGH);
      else
        digitalWrite(h_LSD_4,LOW);
      if (hLSD == 8 || hLSD == 9)
        digitalWrite(h_LSD_8,HIGH);
      else
        digitalWrite(h_LSD_8,LOW);

      // Toggle LEDs for minute MSD
      if ((m >= 10 && m < 20) || (m >= 30 && m < 40) || (m >= 50 && m < 60))
        digitalWrite(m_MSD_1,HIGH);
      else
        digitalWrite(m_MSD_1,LOW);
      if (m >= 20 && m < 40)
        digitalWrite(m_MSD_2,HIGH);
      else
        digitalWrite(m_MSD_2,LOW);
      if (m >= 40 && m < 60)
        digitalWrite(m_MSD_4,HIGH);
      else
        digitalWrite(m_MSD_4,LOW);

      // Toggle LEDs for minutes LSD
      if (mLSD == 1 || mLSD == 3 || mLSD == 5 || mLSD == 7 || mLSD == 9)
        digitalWrite(m_LSD_1,HIGH);
      else
        digitalWrite(m_LSD_1,LOW);
      if (mLSD == 2 || mLSD == 3 || mLSD == 6 || mLSD == 7)
        digitalWrite(m_LSD_2,HIGH);
      else
        digitalWrite(m_LSD_2,LOW);
      if (mLSD == 4 || mLSD == 5 || mLSD == 6 || mLSD == 7)
        digitalWrite(m_LSD_4,HIGH);
      else
        digitalWrite(m_LSD_4,LOW);
      if (mLSD == 8 || mLSD == 9)
        digitalWrite(m_LSD_8,HIGH);
      else
        digitalWrite(m_LSD_8,LOW);

      delay(100);
    }

  }

}
