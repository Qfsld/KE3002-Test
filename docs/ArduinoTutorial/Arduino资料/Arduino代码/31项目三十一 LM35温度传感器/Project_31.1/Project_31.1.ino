int lm35Pin = A3;
float temperture = 0;

void setup() {
  Serial.begin(9600);  //设置波特率9600

  //设置A3引脚为输入
  pinMode(lm35Pin, INPUT);
}

void loop() {
  int value = analogRead(A3);  //传感器接A3
  //计算温度值
  temperture = ((value * 5.0) * 100) / 1024;
  Serial.print("Temperture:");
  Serial.print(temperture);
  Serial.println(" C");  //换行打印
  delay(100);            //加延时100MS
}
