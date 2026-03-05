int beeppin = 3; //定义蜂鸣器引脚为D3

void setup() 
{
  pinMode(beeppin, OUTPUT);//定义蜂鸣器管脚为输出模式
}

void loop() 
{
  tone(beeppin, 262);//DO播放1000ms
  delay(1000);
  tone(beeppin, 294);//Re播放750ms
  delay(750);
  tone(beeppin, 330);//Mi播放625ms
  delay(625);
  tone(beeppin, 349, 500);//Fa播放500ms
  delay(500);
  tone(beeppin, 392, 375);//So播放375ms
  delay(375);
  tone(beeppin, 440, 250);//La播放250ms
  delay(250);
  tone(beeppin, 494, 125);//Si播放125ms
  delay(125);
  noTone(beeppin);//停止播放一秒
  delay(1000);
}
