int redPin = 9; //定义红色接D
int greenPin = 10; //定义绿色接D10
int bluePin = 11; //定义蓝色接D11

//控制颜色显示的函数，这样能代替重复性的代码，使代码更简洁高效
void color(int red, int green,int blue) {
  analogWrite(redPin, red); //输出PWM控制红色led
  analogWrite(greenPin, green); //输出PWM控制绿色led
  analogWrite(bluePin, blue); //输出PWM控制蓝色led
}

void setup() {
    //设置三个管脚为输出模式
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);

    //熄灭全部灯
    color(255,255,255);
}

void loop() {
  //调用color函数控制灯光
  color(0,255,255); //亮红灯
  delay(1000);  //延时一秒
  color(255,0,255); //亮绿灯
  delay(1000);
  color(255,255,0); //亮蓝灯
  delay(1000);
  color(0,0,255); //亮黄灯
  delay(1000);
  color(128,255,0); //亮紫灯
  delay(1000);
  color(0,0,0); //亮白灯
  delay(1000);
  color(255,255,255); //熄灭所有灯
  delay(1000);
}