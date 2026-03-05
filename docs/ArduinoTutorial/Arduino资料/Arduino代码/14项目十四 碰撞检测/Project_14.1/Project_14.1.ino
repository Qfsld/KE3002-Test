int val = 0;

void setup() 
{
  Serial.begin(9600);//设置波特率为9600
  pinMode(3, INPUT);//设置输入模式
}

void loop() 
{
  val = digitalRead(3);//读取传感器的值
  Serial.print(val);//打印出来
  if (val == 0) //碰撞到了
  {
    Serial.print("        ");
    Serial.println("The end of his!");
    delay(100);
  }
  else //没碰撞
  {
    Serial.print("        ");
    Serial.println("All going well");
    delay(100);
  }
}
