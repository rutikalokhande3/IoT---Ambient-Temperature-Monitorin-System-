#include <DHT.h>

#define DHTPIN D4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  Serial.println("Temperature sensor started!");
}

void loop() {
  float temperature = dht.readTemperature();

  if (isnan(temperature)) {
    Serial.println("Sensor error! Check connections.");
  } else {
    Serial.print("Room temperature: ");
    Serial.print(temperature);
    Serial.println(" C");
  }

  delay(2000);
}