int val = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}

void loop() 
{
  val = analogRead(A3);
  Serial.println(val);
  if (val < 150) 
  {
    digitalWrite(3, HIGH);
  }
  else 
  {
    digitalWrite(3, LOW);
  }
  delay(100);
}
