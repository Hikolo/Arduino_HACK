/*
/* Grove - Temperature Sensor demo v1.0
*  This sensor detects the environment temperature,
*  Connect the signal of this sensor to A0, use the 
*  Serial monitor to get the result.
*  By: http://www.seeedstudio.com
*/
#include <math.h>
int a;
String s;
float temperature;
int B=3975;                  //B value of the thermistor
float resistance;
int getTemp(int pin){
  a=analogRead(pin);
  resistance=(float)(1023-a)*10000/a; //get the resistance of the sensor;
  temperature=1/(log(resistance/10000)/B+1/298.15)-273.15;//convert to temperature via datasheet&nbsp;;
  return temperature;
}
String readSerial(){
    if (Serial.available() > 0) { //Check if there's data in the serial port
    s = Serial.readString();
    return s;
}
void setup()
{
  Serial.begin(9600);  
}
 
void loop()
{
  Serial.print("Current temperature is ");
  Serial.println(getTemp(0));
  delay(1000);
 }
