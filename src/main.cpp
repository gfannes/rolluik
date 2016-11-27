#include <Arduino.h>

const int led_up    = 3;
const int led_down  = 4;

const int knop_up   = 8;
const int knop_down = 9;

void setup()
{
  pinMode(led_up,    OUTPUT);
  pinMode(led_down,  OUTPUT);

  pinMode(knop_up,   INPUT);
  pinMode(knop_down, INPUT);

  //Zet interne pull-up weerstandjes aan
  digitalWrite(knop_up,   HIGH);
  digitalWrite(knop_down, HIGH);
}

void loop()
{
    int waarde_up = digitalRead(knop_up);
    digitalWrite(led_up, waarde_up);

    int waarde_down = digitalRead(knop_down);
    digitalWrite(led_down, waarde_down);
}
