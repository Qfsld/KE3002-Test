void attachInterrupt_fun_3() 
{ //中断服务函数
  procedure();
}

void procedure() 
{
  Serial.println("Knock on!");//触发中断打印"Knock on!"
  delay(100);
}

void setup()
{
  Serial.begin(9600);//设置波特率为9600
  pinMode(3, INPUT_PULLUP);//引脚3配置为输入上拉模式
  attachInterrupt(digitalPinToInterrupt(3),attachInterrupt_fun_3,FALLING);//中断引脚为D3，下降沿触发
}

void loop()
{
  Serial.println("All going well!");
  delay(200);
}
