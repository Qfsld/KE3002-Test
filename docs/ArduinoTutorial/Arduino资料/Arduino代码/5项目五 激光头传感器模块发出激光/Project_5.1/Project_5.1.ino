int laserPin = 2; //定义激光引脚为D2

void setup() 
{
  pinMode(laserPin, OUTPUT);//定义输出模式
}

void loop() 
{
  digitalWrite(laserPin, HIGH);//打开
  delay(1000);//延时一秒
  digitalWrite(laserPin, LOW);//关闭
  delay(1000);//延时一秒
}
