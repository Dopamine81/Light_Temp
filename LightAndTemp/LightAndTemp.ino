#include "DFRobot_SHT20.h";
const int ledPin = LED_BUILTIN;

DFRobot_SHT20 sht20(&Wire, SHT20_I2C_ADDR);
int br=0;
int tmp = 0;
const int maxbr = 255;
const int minbr = 0;
const int maxtmp = 48;
const int mintmp = 28;


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

  tmp = temp - 28;
  br = tmp * 12.75;
  br = map(temp, 48, 28, 0, 255);



   
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

  analogWrite(ledPin, br);

  
}