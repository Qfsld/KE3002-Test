int buzzer = 3; //定义蜂鸣器接管脚D3

void setup() 
{
  pinMode(buzzer, OUTPUT);//设置输出模式
}

void loop() 
{
  digitalWrite(buzzer, HIGH); //发声
  delay(1000);
  digitalWrite(buzzer, LOW); //停止发声
  delay(1000);
}
