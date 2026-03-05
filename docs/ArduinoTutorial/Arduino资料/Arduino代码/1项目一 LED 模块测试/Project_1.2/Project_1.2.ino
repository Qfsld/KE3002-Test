int ledPin = 3; //定义LED引脚为D3

void setup() 
{
}

void loop() 
{
  for (int i = 0; i <= 255; i = i + 1) //逐渐变亮
  {
    analogWrite(ledPin, i);
    delay(10);
  }
  for (int i = 255; i >= 0; i = i - 1) //逐渐熄灭
  {
    analogWrite(ledPin, i);
    delay(10);
  }
}
