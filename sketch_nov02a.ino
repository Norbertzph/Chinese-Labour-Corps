int x;
int y;
int pushButton = 2;//originally was a pushbutton but now is a tilt sensor

void setup()
{
  Serial.begin(9600);
  pinMode(2,INPUT);
}

void loop()
{
 int buttonState = digitalRead(pushButton);
  x = analogRead(A0);
  y = analogRead(A1);
  Serial.print(x);
  Serial.print(",");
  Serial.print(y);
  Serial.print(",");
  Serial.println(buttonState);
  delay(50);
}
