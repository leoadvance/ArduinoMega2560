#include "ArduinoMega_UART1.h"

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete


void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);

  UART1_Init(115200);

}

void loop()
{

//    delay(1000);
  //  Serial.println("Hello Mega2560");

  if (stringComplete)
  {
    Serial.print("收到数据:");
    Serial.println(inputString);
    // clear the string:
    inputString = "";
    stringComplete = false;
  }

}


void serialEvent()
{
  while (Serial.available())
  {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n')
    {
      stringComplete = true;
    }
  }
}


