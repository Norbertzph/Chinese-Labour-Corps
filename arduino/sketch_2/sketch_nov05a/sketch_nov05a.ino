//reads a sensor and sends the value out the Serial port
//Uses a basic sending function to allow for multiple values to be sent




long lastSend;                                               //used for the timer controlling the send rate
int sendDelay = 200;                                         //ms between data sends. required for proper functionality

int sensorVals[2];                                          //array used to hold the sensor values


void setup() {

Serial.begin(9600);                                         //turn on the Serial port @ 9600 baud, this is the default for the P5 server
}

void loop() {

sensorVals[0] = analogRead(A0);                              //read the sensor values and put them into the array
sensorVals[1] = analogRead(A1);



sendData(sensorVals,(sizeof(sensorVals)/sizeof(int)), 20);  //execute the sendData function
                                                            //(sizeof(sensorVals)/sizeof(int)) is used because we are passing an
                                                            //array into the function and arduino can't determine the size of the
                                                            //array in that s0cope


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
