# 项目二 双色LED模块调节LED颜色

## 1.实验说明

在这个套件中，有一个keyes brick双色LED模块，它采用F5-红绿共阴雾状LED元件。控制时，我们需要将模块R G连接单片机PWM口，GND接地线。我们通过调节两个PWM值，控制LED元件显示红光、绿光的比例，从而控制双色LED显示不同颜色。

实验中，我们通过2个测试代码，两种控制方法，控制它显示不同颜色。

## 2.实验器材

- keyes brick 双色LED模块*1

- keyes UNO R3开发板*1

- 传感器扩展板*1

- 3P双头XH2.54连接线*1

- USB线*1

## 3.接线图

![0358c59cf5d9b844f753d17567636d9f](./media/0358c59cf5d9b844f753d17567636d9f.png)

## 4.测试代码

**代码1：**

```c
int Red_LED_Pin = 6; //设置控制红色灯的引脚为6
int Green_LED_Pin = 5; //设置控制绿色灯的引脚为5

void setup() {
  pinMode(Green_LED_Pin, OUTPUT);
  pinMode(Red_LED_Pin, OUTPUT);
}

void loop() {
  //亮绿色灯，红色灯不亮
  digitalWrite(Green_LED_Pin, HIGH);
  digitalWrite(Red_LED_Pin, LOW);
  delay(1000); //延时一秒钟
  //亮红色灯，绿色灯不亮
  digitalWrite(Green_LED_Pin, LOW);
  digitalWrite(Red_LED_Pin, HIGH);
  delay(1000);
  //红色与绿色一起亮，出现混合灯光颜色
  digitalWrite(Green_LED_Pin, HIGH);
  digitalWrite(Red_LED_Pin, HIGH);
  delay(1000);

}
```

**代码2：**

```c
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
```

## 5.代码1说明

1.  代码1中，redPin与greenPin代表控制模块上LED对应的红绿2种颜色对应的端口，根据接线图我们接到了D5、D6 引脚，使用pinMode函数设置LED控制引脚为输出模式，使用digitalWrite函数控制引脚输出高低电平从而点亮led灯。

2.  redPin使用digitalWrite函数输出高电平时红灯亮，低电平红灯灭，绿灯控制原理也是一样的。

3.  当红灯与绿灯一起亮时两种颜色的灯光就会显示出混出后的灯光颜色

## 6.代码2说明

1. 代码2中，使用到了PWM输出，使用analogWrite函数输出PWM值控制LED的亮度 。PWM值范围是0-255，函数中设置的值越大，PWM输出越大，设置该颜色的比例越大。
2. 实验中通过设置对应数值，调节RG  LED上红绿颜色比例，从而控制RG LED显示对应颜色。

## 7.测试结果

上传测试代码1成功，上电后，模块上双色LED循环显示对应设置的3种颜色，间隔时间为1秒。上传测试代码2成功，上电后，模块上双色LED显示对应设置的3种颜色，循环不止，间隔时间为1秒。