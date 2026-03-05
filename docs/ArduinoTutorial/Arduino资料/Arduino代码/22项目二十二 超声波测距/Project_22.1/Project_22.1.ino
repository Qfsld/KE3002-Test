int distance = 0; //定义一个用来接收距离的变量
int EchoPin = 13; //Echo引脚接D13
int TrigPin = 12; //Trig引脚接D12

float checkdistance()  //获取距离
{
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  float distance = pulseIn(EchoPin, HIGH) / 58.00;
  delay(10);
  return distance;
}

void setup() 
{
  Serial.begin(9600);//设置波特率为9600
  pinMode(TrigPin, OUTPUT);//Trig引脚为输出
  pinMode(EchoPin, INPUT);  //Echo引脚为输入
}

void loop() 
{
  distance = checkdistance();
  if (distance < 2 || distance >= 400) //在范围外打印"-1"
  {
    Serial.println("-1");
    delay(100);
  }
  else   //打印距离，单位厘米
  {
    Serial.print("distance:");
    Serial.print(distance);
    Serial.println("cm");
    delay(100);
  }

}
