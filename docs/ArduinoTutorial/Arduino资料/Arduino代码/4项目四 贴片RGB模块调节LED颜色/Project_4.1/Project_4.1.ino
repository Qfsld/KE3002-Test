int redPin = 9; //定义红色接D
int greenPin = 10; //定义绿色接D10
int bluePin = 11; //定义蓝色接D11

//控制颜色显示的函数，这样能代替重复性的代码，使代码更简洁高效
void color(int red, int green,int blue) {
  digitalWrite(redPin, red?HIGH:LOW); //使用三目运算符输出控制红色led的高低电平
  digitalWrite(greenPin, green?HIGH:LOW);
  digitalWrite(bluePin, blue?HIGH:LOW);
}

void setup() {
    //设置三个管脚为输出模式
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
}

void loop() {
  //调用color函数控制灯光
  color(0,1,1); //亮红灯
  delay(1000);  //延时一秒
  color(1,0,1); //亮绿灯
  delay(1000);
  color(1,1,0); //亮蓝灯
  delay(1000);

}