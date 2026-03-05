int sensorPin = A3; // 传感器的引脚为A3

void setup() 
{
  Serial.begin(9600);//设置波特率为9600
}

void loop() 
{
  int value = analogRead(A3); //读取模拟值
  Serial.println(value);//打印出来
}
