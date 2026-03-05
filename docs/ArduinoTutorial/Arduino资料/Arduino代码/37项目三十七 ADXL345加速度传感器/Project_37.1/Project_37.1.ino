#include <Wire.h>
#include <I2Cdev.h>
#include <ADXL345.h>  //ADXL345的库

float X = 0;
float Y = 0;
float Z = 0;
ADXL345 accel;

void setup() 
{
  Serial.begin(9600);
  Wire.begin();
  accel.initialize(); //初始化
}

void loop() 
{
  //读取加速度值
  X = accel.getAccelerationX();
  Y = accel.getAccelerationY();
  Z = accel.getAccelerationZ();
  //打印加速度值
  Serial.print("X:");
  Serial.print(X);
  Serial.print("g    Y:");
  Serial.print(Y);
  Serial.print("g    Z:");
  Serial.print(Z);
  Serial.println("g");
  delay(100);
}
