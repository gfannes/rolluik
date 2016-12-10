#include <Arduino.h>

struct KnipperLed
{
  int pin;
  int action_time = 0;
  bool led_aan = true;
  int wait_time = 80;

  KnipperLed(int p)
  {
    pin = p;
  }

  void setup()
  {
    pinMode(pin, OUTPUT);    
  }

  void knipper(int now)
  {
    if (now >= action_time)
    {
       digitalWrite(pin, led_aan);
       action_time = now + wait_time;
      led_aan = !led_aan;
    }
  }

};

KnipperLed up(3);
KnipperLed down(4);

const int knop_up   = 8;
const int knop_down = 9;

void setup()
{
  down.wait_time++;
  up.setup();
  down.setup();

  pinMode(knop_up,   INPUT);
  pinMode(knop_down, INPUT);

  //Zet interne pull-up weerstandjes aan
  digitalWrite(knop_up,   HIGH);
  digitalWrite(knop_down, HIGH);
}

void loop()
{
  const int now = millis();

  up.knipper(now);
  down.knipper(now);
}
