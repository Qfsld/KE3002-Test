int redLED = 9;     //定义控制红色LED引脚为D9
int greenLED = 10;  //定义控制绿色LED引脚为D10
int blueLED = 11;   //定义控制蓝色LED引脚为D11

//小数类型的变量用于存放温度值
float temperture = 0;

void setup() {
  Serial.begin(9600);
  //设置控制led的引脚为输出
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

void loop() {
  //计算处温度值
  temperture = ((analogRead(A3) * 5.0) * 100) / 1024;
  //打印温度值
  Serial.print("Temperature:");
  Serial.println(temperture);
  delay(100);
  //判断温度值是否小于等于27℃，如果是就亮蓝灯
  if (temperture <= 27) {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, HIGH);
    //判断温度值是否大于27℃并且小于等于30℃，如果是就亮绿灯
  } else if (temperture > 27 && temperture <= 30) {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, LOW);
    //判断温度值是否大于30℃，如果是就亮红灯
  } else if (temperture > 30) {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);
  }
}
