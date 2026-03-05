int val = 0;
int button = 3; //按键的PIN

void setup() 
{
  Serial.begin(9600); //设置波特率为9600
  pinMode(button, INPUT); //设置为输入模式
}

void loop() 
{
  val = digitalRead(button);  //读取按键的值
  Serial.print(val);  //串口上打印出来
  if (val == 0)  //按下按键则读取到低电平
  {
    Serial.print("        ");
    Serial.println("Press the botton");
    delay(100);
  }
  else 
  {
    Serial.print("        ");
    Serial.println("Loosen the botton");
    delay(100);
  }
}
