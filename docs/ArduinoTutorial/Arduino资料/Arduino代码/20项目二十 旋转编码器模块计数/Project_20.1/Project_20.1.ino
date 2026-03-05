#include <Encoder.h>//导入编码器的库
int item = 0;
int old = 0;
Encoder encoder(2, 3);
int button = 4;

void setup() 
{
  Serial.begin(9600);//设置波特率
  pinMode(button, INPUT);//按键为输入模式
}

void loop() 
{
  item = encoder.read();//读取编码器的值赋给item
  if (digitalRead(button) == 0) //如果按键按下
  {
    Serial.println(digitalRead(button));//打印按键值
    delay(100);
  }
  if (old != item) //与之前读取的值不一样
  {
    Serial.println(item);//打印编码器的值
    old = item;
  }
}
