int x;
int y;
int pushButton = 2;//originally was a pushbutton but now is a tilt sensor
long lastSend;                                               //used for the timer controlling the send rate
int sendDelay = 200;                                         //ms between data sends. required for proper functionality


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

void sendData(int sVal[], int arLength, int sDel)           //this is the function that sends data out the Serial port
{                                                           //the format is   "sensorvalue1,sensorvalue2,sensorvalue3,..."
    if(millis()-lastSend>=sDel)                             //simple timer controls how often it sends
    {
      for(int i=0;i<arLength;i++)                           //for loop is used to package up all the values in the array
      {
        if(i<arLength-1)                                    //this checks what to do if it ISN'T the last value
        {                                                   //it uses Serial.print and adds the comma to the string
        Serial.print(sVal[i]);                                
        Serial.print(",");
        }
          else
          {
          Serial.println(sVal[i]);                          //there is a different command for the final value
          }                                                 //we use Serial.println because the server looks for the newline character to know the end of the messages
      }                                                     //it also doesn't need the comma because it is the last value
      lastSend = millis();                                  //save the time that the value is sent, so the timer will work   
    } 
}
