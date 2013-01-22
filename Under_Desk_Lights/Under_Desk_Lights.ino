
const int red=4;
const int blue=0;
const int green=1;
int pause=20;

void setup()
{
  Serial.begin(9600);
  //randomSeed(analogRead(1));
}

void loop()
{
  //Serial.println("running");
  //setColor(50,50,50);
  //ballonDisplay();
  //delay(1000);
  //randomTransition(random(100));
  if(analogRead(A1)<500)
  {
  colorWheel();
  }
  if(analogRead(A1)>=500)
  {
    setColor(0,0,0);
  }
}

void setColor(int redLED, int greenLED, int blueLED)
{
  analogWrite(red,redLED);
  analogWrite(blue,blueLED);
  analogWrite(green,greenLED);
}

void transition(int colorNow, int colorChange, int colorNone, int timeDelay)
{
  int color1=255, color2=0, color3=0;
  for(int i=1;i<256;i++)
  {
    color1--;
    color2++;
    analogWrite(colorNow,color1);
    analogWrite(colorChange,color2);
    analogWrite(colorNone,color3);
    delay(timeDelay);
  }
}

void randomTransition(int delayTime)
{
  int random1=random(255);
  int random2=random(255);
  int random3=random(255);
  setColor(random1, random2, random3);
  delay(delayTime);
}

void colorWheel()
{
  transition(red,blue,green,pause);
  transition(blue,green,red,pause);
  transition(green,red,blue,pause);
}

void ballonDisplay()
{
  colorSplosion(red);
  delay(1000);
  colorSplosion(blue);
  delay(1000);
  colorSplosion(green);
  delay(1000);
}

void colorSplosion(int color1)
{
  for(int i=1;i<=255;i++)
  {
    analogWrite(color1,i);
    delayMicroseconds(20);
  }
  //delay(50);
  for(int i=255;i>=150;i--)
  {
    analogWrite(color1,i);
    delay(1);
  }
  for(int i=150;i>=0;i--)
  {
    analogWrite(color1,i);
    delay(30);
  }
}
  
