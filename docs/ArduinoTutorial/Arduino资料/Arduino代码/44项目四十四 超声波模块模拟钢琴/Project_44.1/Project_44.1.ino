int distance;
//读取超声波测距函数
float checkdistance_12_13() {
  digitalWrite(12, LOW);
  delayMicroseconds(2);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);
  float distance = pulseIn(13, HIGH) / 58.00;
  delay(10);
  return distance;
}

void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(13, INPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  distance = checkdistance_12_13();
  Serial.println(distance);
  //如果距离小于等于10CM播放`Do`
  if (distance <= 10) {
    tone(3, 262, 250);
    //如果距离大于10CM小于等于20CM播放`Re`
  } else if (distance > 10 && distance <= 20) {
    tone(3, 294, 250);
    //如果距离大于20CM小于等于30CM播放`Re`
  } else if (distance > 20 && distance <= 30) {
    tone(3, 330, 250);
    //如果距离大于30CM小于等于40CM播放`Re`
  } else if (distance > 30 && distance <= 40) {
    tone(3, 349, 250);
    //如果距离大于40CM小于等于50CM播放`Re`
  } else if (distance > 40 && distance <= 50) {
    tone(3, 392, 250);
    //如果距离大于50CM小于等于60CM播放`Re`
  } else if (distance > 50 && distance <= 60) {
    tone(3, 440, 250);
    //如果距离大于60CM小于等于70CM播放`Re`
  } else if (distance > 60 && distance <= 70) {
    tone(3, 494, 250);
    //如果以上条件都不满足就停止播放
  } else {
    noTone(3);
  }
  delay(100);
}