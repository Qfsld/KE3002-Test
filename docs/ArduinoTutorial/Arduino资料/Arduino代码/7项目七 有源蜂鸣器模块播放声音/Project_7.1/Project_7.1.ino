int buzzer = 3; //定义蜂鸣器接管脚D3

void setup() 
{
  pinMode(3, OUTPUT);//设置输出模式
}

void loop() 
{
  digitalWrite(3, HIGH); //发声
  delay(1000);
  digitalWrite(3, LOW); //停止发声
  delay(1000);
}
