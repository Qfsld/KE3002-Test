#include <Encoder.h>
volatile int item;
volatile int val;
Encoder encoder_1(2, 3);

void setup() 
{
  item = 0;
  val = 0;
  Serial.begin(9600);
}

void loop() 
{
  item = encoder_1.read();
  val = (long) (item) % (long) (3);
  Serial.println(val);
  if (val == 0) 
  {
    analogWrite(9, 255);
    analogWrite(10, 0);
    analogWrite(11, 0);
  } 
  else if (val == 1)
  {
    analogWrite(9, 0);
    analogWrite(10, 255);
    analogWrite(11, 0);
  } 
  else{
    analogWrite(9, 0);
    analogWrite(10, 0);
    analogWrite(11, 255);
  }
  delay(100);
}
