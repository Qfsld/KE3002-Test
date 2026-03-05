int val = 0;

void setup() 
{
  Serial.begin(9600);//设置波特率为9600
  pinMode(3, INPUT);//设置传感器的PIN输入模式
}

void loop() 
{
  val = digitalRead(3);//读取电平
  Serial.print(val);//打印数字电平
  if (val == 0) 
  {
    Serial.print("        ");
    Serial.println("Right");
    delay(100);
  }
  else 
  {
    Serial.print("        ");
    Serial.println("Left");
    delay(100);
  }
}
