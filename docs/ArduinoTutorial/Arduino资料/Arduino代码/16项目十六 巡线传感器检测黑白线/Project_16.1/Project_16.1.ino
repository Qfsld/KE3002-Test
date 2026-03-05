int val = 0;

void setup() 
{
  Serial.begin(9600);//设置波特率为9600
  pinMode(3, INPUT);//设置传感器引脚为输入模式
}

void loop() 
{
  val = digitalRead(3);//读取传感器的值
  Serial.print(val);//串口打印值
  if (val == 0) //白色
  {
    Serial.print("        ");
    Serial.println("White");
    delay(100);
  }
  else {//黑色
    Serial.print("        ");
    Serial.println("Black");
    delay(100);
  }
}
