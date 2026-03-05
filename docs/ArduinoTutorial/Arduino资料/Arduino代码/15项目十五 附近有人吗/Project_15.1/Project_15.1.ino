int val = 0;

void setup() 
{
  Serial.begin(9600);//设置波特率为9600
  pinMode(3, INPUT);//设置输入模式
}

void loop() 
{
  val = digitalRead(3);//读取传感器的值
  Serial.print(val);//打印值
  if (val == 1) //附近有人输出高电平
  {
    Serial.print("        ");
    Serial.println("Some body is in this area!");
    delay(100);
  }
  else //没人则输出低电平
  {
    Serial.print("        ");
    Serial.println("No one!");
    delay(100);
  }
}
