volatile int val1 = 0;
volatile int val2 = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(A2, INPUT);
}

void loop() 
{
  val1 = digitalRead(A2);//读取数字值
  Serial.print(val1);
  if (val1 == 1) 
  {
    Serial.println("    Normal");
  }
  else 
  {
    Serial.println("    Exceeding");
  }
  val2 = analogRead(A3);//读取模拟值
  Serial.println(val2);
  delay(500);
}
