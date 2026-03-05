int val1 = 0;
int val2 = 0;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  val1 = analogRead(A3);
  Serial.print(val1);
  Serial.print("  ");
  val2 = map(val1, 0, 1023, 0, 255);
  Serial.println(val2);
  analogWrite(3, val2);
  delay(100);
}
