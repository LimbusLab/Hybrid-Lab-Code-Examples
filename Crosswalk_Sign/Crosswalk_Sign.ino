const int sign = 0;
int delayTime = 1, randomTime, initialTime=0;
int distanceTrigger = 40;

void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(A3));
  getRandomTime();
  for(int i=0; i<3;i++)
    {
    Serial.println("BLINK SIGN");
    blinkSign();
    delay(250);
    }
}

void loop()
{
  Serial.println(checkDistance());
  if(checkDistance() < distanceTrigger)
  {
    for(int i=0; i<3;i++)
    {
    Serial.println("BLINK SIGN");
    blinkSign();
    delay(250);
    }
  }
  if(initialTime>=randomTime)
  {
    blinkSign();
    getRandomTime();
    initialTime=0;
  }
  initialTime+=10;
  delay(10);
}
  
  
void blinkSign()
{
  for(int i=1;i<=255;i++)
  {
    analogWrite(sign,i);
    delay(delayTime);
  }
  for(int i=255;i>=0;i--)
  {
    analogWrite(sign,i);
    delay(delayTime);
  }
}
  
int checkDistance()
{
  int distance=0, iterations = 10;
  for(int i=0;i<iterations;i++)
  {
    distance += analogRead(A1);
    delay(1);
  }
  distance = distance/iterations;
  distance = map(distance, 0, 550, 50, 0);
  Serial.println(distance);
  return distance;
}

void getRandomTime()
{
  randomTime = random(500);
  randomTime = map(randomTime,0,100, 250, 10000);
}
