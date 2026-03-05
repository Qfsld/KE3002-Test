int val = 0;

void setup() 
{
  Serial.begin(9600);//设置波特率为9600
  pinMode(3, INPUT);//设置模式为输入
}

void loop() 
{
  val = digitalRead(3);//读取电平
  Serial.print(val);//打印信号
  if (val == 0) //存在南极磁场
  {
    Serial.println("      The magnetic field at the South Pole!");
  }
  else //不存在
  {
    Serial.println("      Just be all normal!");
  }
}
