int relayPin = 3; //定义继电器接管脚D3

void setup() 
{
  pinMode(3, OUTPUT);//设置输出模式
}

void loop() 
{
  digitalWrite(3, HIGH);//打开
  delay(1000);
  digitalWrite(3, LOW);//关闭
  delay(1000);
}
