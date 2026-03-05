int redPin = 6;    //定义红色接D6
int greenPin = 5;  //定义绿色接D5

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  //红色
  analogWrite(redPin, 255);
  analogWrite(greenPin, 0);
  delay(1000);
  //绿色
  analogWrite(redPin, 0);
  analogWrite(greenPin, 255);
  delay(1000);
  //红色加绿色的混合色
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  delay(1000);
}