#include <Arduino.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>

// Define the pins that we will use
#define SENSOR 33
#define DHTTYPE DHT11 
DHT_Unified dht(SENSOR, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Initialize device.
  dht.begin();
  Serial.println(F("DHTxx Unified Sensor Example"));
}

void loop() {
  // Effectuer une mesure toutes les 5s
  delay(5000);
  // Afficher l'humidité relative avec un peu de formatage
  sensors_event_t event;
dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
  }
  // Afficher la température avec un peu de formatage
    dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  }
  else {
    Serial.print(F("Humidity: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));
  }
}