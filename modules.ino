#include <math.h>


class Therm
{
  int thermPin;
  int input;
  int B;
  float temperature;
  float resistance;

  public:
  Therm(int pin, int bValue = 3975)
  {
    thermPin = pin;
    B = bValue;    
  }
  float getTemp()
  {
    input=analogRead(thermPin);
    resistance = (float)(1023-input)*10000/input; //get the resistance of the sensor
    temperature = 1/(log(resistance/10000)/B+1/298.15)-273.15;//convert to temperature via datasheet&nbsp;;
    return temperature;
  }
  
};
class Relay
{
  int relayPin;        //the pin number for the relay
  int relayState;  //used to set relay
  String description;


  public:
  Relay(int pin)
  {
    relayPin = pin;
    pinMode(relayPin, OUTPUT);
    relayState = LOW;
  }
  boolean State()
  {
    if(relayState = HIGH){
      return true;
    }
    else
    {
      return false;
    }
  }
  boolean On()
  {
    if (State())
    {
      return false;
    }
    else
    {
      relayState = HIGH;
    }
  }
  boolean Off()
  {
    if (!State())
    {
      return false;
    }
    else
    {
      relayState = LOW;
    }
  }
  void Update()
  {
    digitalWrite(relayPin, relayState);
  }

  
};
class Light
{
  int lightPin;
  int threshold;
  int sensorValue;
  float resistance;
  
  public:
  Light(int pin, int th = 10)
  {
    lightPin = pin;
    threshold = th;
  }
  boolean check()
  {
    int sensorValue = analogRead(lightPin); 
    resistance = (float)(1023-sensorValue)*10/sensorValue;
    if (resistance > threshold)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  int value()
  {
    sensorValue = analogRead(lightPin); 
    resistance = (float)(1023-sensorValue)*10/sensorValue;
    return resistance;
  }
  
};

  
  Therm T1(0);
  Relay R1(2);
  Light L1(1,10);



void setup()
{

  
}


void loop()
{
  if( Serial.available() > 0)
  {
    String r = Serial.readString();
    if (r.charAt(0) == 'R') {
      if ( r.charAt(2) == 'O' ) {
        R1.On();
      }
      else {
        R1.Off();
      }
      R1.Update();
    }
    else if (r.charAt(0) == 'T') {
      Serial.print(T1.getTemp());
    }
    else {
      Serial.print(L1.value());
    }
      
        
    
  }
}

