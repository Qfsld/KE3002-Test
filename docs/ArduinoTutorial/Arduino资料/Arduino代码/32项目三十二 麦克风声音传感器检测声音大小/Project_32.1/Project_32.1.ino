volatile int item = 0;

void setup() 
{
  Serial.begin(9600);//设置波特率9600
}

void loop()
{
  item = analogRead(A3);//传感器接A3
  Serial.println(item);//换行打印
  delay(100);//加延时100MS
}
