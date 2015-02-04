/****************************************************************************** <filename>
<SparkFun IR Photogate Simple Sketch>
<Dave @ SparkFun Electronics>
<November 2014>
<https://github.com/sparkfun/Photo_Interrupter_Breakout>

Simple Sketch for getting started with Photo Interrupter Breakout. 

This code is beerware; if you see me (or any other SparkFun employee) at the local, and you've found our code helpful, please buy us a round!
Distributed as-is; no warranty is given.

// PIR example
#include <SoftwareSerial.h>

SoftwareSerial display(3, 2);

const int irPin = A5;

void setup()
{
  pinMode(irPin, INPUT);

  display.begin(9600);
  Serial.begin(9600);
  delay(500);

  display.write(254); // move cursor to beginning of first line
  display.write(128);

  display.write("                "); // clear display
  display.write("                ");
}

void loop()
{
  display.write(254); // move cursor to beginning of first line
  display.write(128);

  int val = digitalRead(irPin);

  if(val)
    display.write("All Clear       ");
  else
    display.write("Gate Obstructed!");

  delay(50);
}

