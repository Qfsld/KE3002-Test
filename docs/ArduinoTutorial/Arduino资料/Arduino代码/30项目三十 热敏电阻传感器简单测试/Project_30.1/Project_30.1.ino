void setup() 
{
  Serial.begin(9600);//设置波特率为9600
}

void loop() 
{
  Serial.println(analogRead(A3));//读取并打印热敏电阻模拟值
  delay(100);//延时100毫秒
}
