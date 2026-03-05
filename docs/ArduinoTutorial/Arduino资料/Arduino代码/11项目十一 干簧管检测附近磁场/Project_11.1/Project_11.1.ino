int val = 0;
void setup() 
{
  Serial.begin(9600);//设置波特率为9600
  pinMode(3, INPUT);//设置模式为输入
}

void loop() 
{
  val = digitalRead(3);//读取数字电平
  Serial.print(val);//串口显示出来
  if (val == 0) //附近存在磁场
  {
    Serial.print("        ");
    Serial.println("A magnetic  field");
    delay(100);
  }
  else //无磁场
  {
    Serial.print("        ");
    Serial.println("There is no magnetic field");
    delay(100);
  }
}
