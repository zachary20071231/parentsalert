#include <Microduino_ColorLED.h>

ColorLED strip = ColorLED(4, 6);
long timer;
float checkdistance_1_2() {
  digitalWrite(1, LOW);
  delayMicroseconds(2);
  digitalWrite(1, HIGH);
  delayMicroseconds(10);
  digitalWrite(1, LOW);
  float distance = pulseIn(2, HIGH) / 58.00;
  delay(10);
  return distance;
}

void setup()
{
  strip.begin();
  timer = 0;
  pinMode(1, OUTPUT);
  pinMode(2, INPUT);
}

void loop()
{
  if (checkdistance_1_2() < 50) {
    timer = timer + 1;
    delay(1000);
    if (timer >= 20) {
      for (int i = 1; i <= 4; i = i + (1)) {
        strip.setPixelColor(i-1, 255,0,0);
        strip.show();
      }

    } else {
      for (int i = 1; i <= 4; i = i + (1)) {
        strip.setPixelColor(i-1, 0,0,0);
        strip.show();
      }

    }

  } else {
    timer = timer + 0;

  }

}
