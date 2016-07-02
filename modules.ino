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
    if (State() == false)
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
void setup(){}
void loop(){}

