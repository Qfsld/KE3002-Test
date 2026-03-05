volatile int item;

void setup() 
{
  item = 0;
  pinMode(3, INPUT);
  pinMode(10, OUTPUT);
}

void loop() 
{
  item = digitalRead(3);
  if (item == 0) 
  {
    digitalWrite(10, HIGH);
  } 
  else 
  {
    digitalWrite(10, LOW);
  }
  delay(100);
}
