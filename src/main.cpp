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

KnipperLed led_1(4);
KnipperLed led_2(5);
KnipperLed led_3(6);
KnipperLed led_4(7);
KnipperLed led_5(8);
KnipperLed led_6(9);
KnipperLed led_7(10);
KnipperLed led_8(11);
KnipperLed led_9(12);
KnipperLed led_10(13);

const int knop_up   = 8;
const int knop_down = 9;

void setup()
{
  led_2.wait_time += 2;
  led_3.wait_time += 4;
  led_4.wait_time += 6;
  led_5.wait_time += 8;
  led_6.wait_time += 10;
  led_7.wait_time += 12;
  led_8.wait_time += 14;
  led_9.wait_time += 16;
  led_10.wait_time += 18;
  led_1.setup();
  led_2.setup();
  led_3.setup();
  led_4.setup();
  led_5.setup();
  led_6.setup();
  led_7.setup();
  led_8.setup();
  led_9.setup();
  led_10.setup();


  pinMode(knop_up,   INPUT);
  pinMode(knop_down, INPUT);

  //Zet interne pull-up weerstandjes aan
  digitalWrite(knop_up,   HIGH);
  digitalWrite(knop_down, HIGH);
}

void loop()
{
  const int now = millis();

  led_1.knipper(now);
  led_2.knipper(now);
  led_3.knipper(now);
  led_4.knipper(now);
  led_5.knipper(now);
  led_6.knipper(now);
  led_7.knipper(now);
  led_8.knipper(now);
  led_9.knipper(now);
  led_10.knipper(now);

}
