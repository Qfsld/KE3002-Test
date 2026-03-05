volatile int item = 0;

void setup() 
{
  Serial.begin(9600);//设置波特率
}

void loop() 
{
  item = analogRead(A3);//读取电位器的值
  Serial.println(item);//打印值
  delay(100);//延时100MS
}
