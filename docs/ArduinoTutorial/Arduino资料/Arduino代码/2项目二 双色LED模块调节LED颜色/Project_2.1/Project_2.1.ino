int redPin = 6; //设置控制红色灯的引脚为6
int greenPin = 5; //设置控制绿色灯的引脚为5

void setup() {
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
}

void loop() {
  //亮绿色灯，红色灯不亮
  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin, LOW);
  delay(1000); //延时一秒钟
  //亮红色灯，绿色灯不亮
  digitalWrite(greenPin, LOW);
  digitalWrite(redPin, HIGH);
  delay(1000);
  //红色与绿色一起亮，出现混合灯光颜色
  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin, HIGH);
  delay(1000);

}