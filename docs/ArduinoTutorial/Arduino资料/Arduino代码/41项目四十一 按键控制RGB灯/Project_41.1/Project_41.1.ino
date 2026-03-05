volatile int PushCounter;
volatile int State;
volatile int lastState;
volatile int PushCounter1;

void setup() 
{
  PushCounter = 0;
  State = 1;
  lastState = 1;
  PushCounter1 = 0;
  Serial.begin(9600);
  pinMode(3, INPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() 
{
  State = digitalRead(3);
  if (State != lastState) 
  {
    if (State == 0) 
    {
      PushCounter = PushCounter + 1;
    }
  }
  lastState = State;
  PushCounter1 = (long) (PushCounter) % (long) (3);
  Serial.println(PushCounter1);
  delay(200);
  if (PushCounter1 == 0) 
  {
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  } 
  else if (PushCounter1 == 1) 
  {
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  } else if (PushCounter1 == 2) 
  {
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
  }
}
