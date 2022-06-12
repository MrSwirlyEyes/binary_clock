// Binary Clock LED Array Prototype on the Arduino UNO
//
// Blinks/toggles an array of LEDs ON and OFF



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

byte leds[NUM_LEDS] = {
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

void setup() {
  // Configure ALL led pins to be a digital OUTPUT
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(leds[i],OUTPUT);
  }
}

void loop() { 
  // Write all LEDs HIGH/ON
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(leds[i],HIGH);
    delay(50);
  }

  delay(500);

  // Write all LEDs LOW/OFF
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(leds[i],LOW);
    delay(50);
  }

  delay(500);
}