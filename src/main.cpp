#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
const int Buzzer = 15;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  pinMode(Buzzer, OUTPUT);
  Wire.begin(21, 22); // SDA, SCL

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 not found");
    while (true);
  }

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  // ON for 1 second
  tone(Buzzer, 2000); // Generate a 2kHz tone
  display.clearDisplay();
  display.setCursor(0, 20);
  display.println("Hello,");
  display.println("World!");
  display.display();
  delay(1000);

  // OFF for 1 second
  noTone(Buzzer); // Stop the tone
  display.display();
  delay(1000);
}