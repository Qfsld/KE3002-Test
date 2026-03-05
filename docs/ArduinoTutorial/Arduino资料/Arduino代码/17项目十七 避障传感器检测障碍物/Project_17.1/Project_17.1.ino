int val = 0;

void setup() 
{
  Serial.begin(9600);//设置波特率为9600
  pinMode(3, INPUT);//设置输入模式
}

void loop() 
{
  val = digitalRead(3);//读取电平
  Serial.print(val);//打印读取的值
  if (val == 0) //有障碍物
  {
    Serial.print("        ");
    Serial.println("There are obstacles");
    delay(100);
  }
  else //没检测到障碍物
  {
    Serial.print("        ");
    Serial.println("All going well");
    delay(100);
  }
}
