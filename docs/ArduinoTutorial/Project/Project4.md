# 项目四 贴片RGB模块调节LED颜色

## 1.实验说明

在这个套件中，有一个贴片RGB模块，它采用5050 RGB高亮LED元件。控制时，我们需要将模块R G B连接单片机PWM口，+接5V。我们通过调节3个PWM值，控制LED元件显示红光、绿光和蓝光的比例，从而控制RGB模块上LED显示不同颜色灯光。当设置的PWM值越大，对应显示的颜色比例越低。理论来说，通过调节这3中颜色光的混合比例，可以模拟出所有颜色的灯光。

实验中，我们通过测试代码，控制模块上RGB LED显示几个常用颜色。

## 2.实验器材

- keyes brick 贴片RGB模块*1

- keyes UNO R3开发板*1

- 传感器扩展板*1

- 3P双头XH2.54连接线*1
- USB线*1

## 3.接线图

![643e129e7c279c12be75374db76a33d8](./media/643e129e7c279c12be75374db76a33d8.png)

## 4.测试代码

**代码1：**

```c
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
```

**代码2：**

```c
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
```

## 5.代码1说明

1. 声明三个整数变量分别对应RGB LED的三个引脚：红色（D9）、绿色（D10）、蓝色（D11）。使用变量而非直接数字使程序易于修改和维护。
2. 自定义`color()`函数通过三个参数控制LED状态：参数为0时点亮对应颜色，非0时熄灭。内部使用三目运算符将参数转换为HIGH/LOW电平，并通过`digitalWrite()`输出到对应引脚。
3. 三目运算符(?:)：紧凑的条件表达式，语法为`条件 ? 值1 : 值2`，条件真返回值1，否则返回值2
4. `setup()`函数在程序开始时运行一次，用于硬件初始化。使用`pinMode()`将三个引脚设置为输出模式，使Arduino能够控制LED的亮灭。
5. `loop()`函数循环执行，依次调用`color()`显示红、绿、蓝三色，每种颜色保持1秒。`delay(1000)`实现延时功能，参数1000表示1000毫秒（1秒）。

## 6.代码2说明

1. 定义三个变量对应RGB LED的三个引脚。这里使用了支持PWM（脉冲宽度调制）的数字引脚9、10、11。
2. `color()`函数使用`analogWrite()`输出PWM控制LED亮度，参数范围0-255：
   - 0：全亮
   - 255：全灭（假设共阳极连接）
   - 中间值：不同亮度

3. `setup()`函数中初始化引脚，并将所有LED设置为熄灭状态：`color(255,255,255); `
4. 调用`color`函数并输入0-255的PWM值，循环显示七种颜色状态，包括红、绿、蓝、黄、紫、白、全灭，每种颜色显示1秒。

## 7.测试结果

上传测试代码1成功，上电后，模块上RGB LED循环显示红绿蓝3种颜色，间隔时间为1秒。上传测试代码2成功，上电后，模块上RGB LED显示红绿蓝黄紫白6种颜色，然后熄灭，循环不止，间隔时间为1秒。