volatile int X = 0;
volatile int Y = 0;
volatile int Button = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(7, INPUT);//定义按键的PIN为数字口7
}

void loop() 
{
  X = analogRead(A0);
  Y = analogRead(A1);
  Button = digitalRead(7);
  Serial.write("X:");
  Serial.print(X);
  Serial.write("     Y:");
  Serial.print(Y);
  Serial.write("     B:");
  Serial.println(Button);
  delay(100);
}
