#include <Arduino.h>
#include "DHT.h"

#define DHTPIN 8     

DHT dht(DHTPIN, DHT22);  

int humidity;
float temperatureDHT;

void setup() {
  Serial.begin(9600);  
  dht.begin();         
}

void loop() {
  humidity = dht.readHumidity(); 
  temperatureDHT = dht.readTemperature();  

  if (isnan(humidity)) {
    Serial.println("Data reading error!");
  } else {
    Serial.println("====== Sensor Data ======");
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
    Serial.print("Temperature: ");
    Serial.print(temperatureDHT);
    Serial.println(" °C");
    Serial.println("===============================");
  }

  delay(10000);
}
