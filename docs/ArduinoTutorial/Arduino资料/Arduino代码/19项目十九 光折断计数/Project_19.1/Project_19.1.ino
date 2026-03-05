int PushCounter = 0; //计数赋初值0
int State = 0; //当前的状态
int lastState = 0; //之前的状态

void setup() 
{
  Serial.begin(9600);//设置波特率为9600
  pinMode(3, INPUT);//设置模式为输入
}

void loop() 
{
  State = digitalRead(3);//读取当前状态
  if (State != lastState) //如果与之前的状态不相同
  {
    if (State == 1) //光线折断
    {
      PushCounter = PushCounter + 1;//计数加1
    }
  }
  lastState = State;//更新状态
  Serial.println(PushCounter);//打印计数
}
