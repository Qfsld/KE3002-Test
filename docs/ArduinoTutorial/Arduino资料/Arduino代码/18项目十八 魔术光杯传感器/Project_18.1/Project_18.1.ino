int buttonStateA = 0;//模块1的状态
int buttonStateB = 0;//模块2的状态
int brightnessA = 0;//模块1的亮度
int brightnessB = 1000;//模块2的亮度
int sensor1=A2,sensor2=A4;//模块1传感器接A2，模块2传感器接A4
int led1=A3,led2=A5;//模块1led接A3，模块2led接A5

void PWMA(int val1) //输出模拟值val
{
  for (int i = 1; i <= 5; i = i + 1) 
  {
    digitalWrite(led1, HIGH);
    delayMicroseconds(val1);
    digitalWrite(led1, LOW);
    delayMicroseconds(1000 - val1);
  }
}

void PWMB(int val2) //输出模拟值val2
{
  for (int i = 1; i <= 5; i = i + 1) 
  {
    digitalWrite(led2, HIGH);
    delayMicroseconds(val2);
    digitalWrite(led2, LOW);
    delayMicroseconds(1000 - val2);
  }
}

void setup() 
{
  Serial.begin(9600);//设置波特率为9600
  pinMode(sensor1, INPUT);//传感器1输入模式
  pinMode(led1,OUTPUT);//LED1输出模式
  pinMode(sensor2, INPUT);//传感器2输入模式
  pinMode(led2,OUTPUT);//LED2输出模式
}

void loop() 
{
  buttonStateA = digitalRead(sensor1);//读取传感器1的转态
  buttonStateB = digitalRead(sensor2);//读取传感器2的转态
  if (buttonStateA == 1 && brightnessA != 1000) //如果传感器1的转态为1，但亮度不到1000
  {
    brightnessA = brightnessA + 1;//变亮
  } 
  else if (buttonStateA == 0 && brightnessA != 0) 
  {//如果传感器1的转态为0，但亮度不到0
    brightnessA = brightnessA - 1;//变暗
  }
  
  if (buttonStateB == 1 && brightnessB != 0) 
  {//如果传感器2的转态为1，但亮度不到0
    brightnessB = brightnessB - 1;//变暗
  }
  else if (buttonStateB == 0 && brightnessB != 1000) //如果传感器2的转态为0，但亮度不到1000
  {
    brightnessB = brightnessB + 1;//变亮
  }
  //打印出两个模块的亮度值
  Serial.print(brightnessA);
  Serial.print("      ");
  Serial.println(brightnessB);
  
  if (brightnessA == 0) //当LED1亮度为0
  {
    digitalWrite(led1, LOW);//熄灭
  } 
  else if (brightnessA == 1000) //当LED1亮度为1000
  {
    digitalWrite(led1, HIGH);//最亮
  } 
  else if (buttonStateA > 0 && brightnessA < 1000) //否则亮度在中间的话
  {
    PWMA(brightnessA);//输出模拟值
  }
  //下同
  if (brightnessB == 0) 
  {
    digitalWrite(led2, LOW);
  } 
  else if (brightnessB == 1000) 
  {
    digitalWrite(led2, HIGH);
  } 
  else if (brightnessB > 0 && brightnessB < 1000) 
  {
    PWMB(brightnessB);
  }
}
