#include "DFRobot_SHT20.h";
const int ledPin = LED_BUILTIN;

DFRobot_SHT20 sht20(&Wire, SHT20_I2C_ADDR);
unsigned long br=0;
const int maxbr = 255;
const int minbr = 0;


void setup() 
{

  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);

  sht20.initSHT20();
  delay(100);
  Serial.println("Temp Sensor");
  sht20.checkSHT20();

}

void loop() 
{
  float humd = sht20.readHumidity();

  float temp = sht20.readTemperature();

  unsigned long Brightness = temp * 6;
  br = Brightness;


   
  Serial.print("Time");
  Serial.print(millis());
  Serial.print("Temprature:");
  Serial.print(temp, 1);
  Serial.print("C");
  Serial.print(" Humidity:");
  Serial.print(humd, 1);
  Serial.print("%");
  Serial.println();
  delay(1000);
  Serial.print(br, 1);

  if ( br <= maxbr) {

    analogWrite(ledPin, br);
  }

}