#include <ESP8266WiFi.h>
#include <DHT.h>

// Enter your mobile hotspot details here
const char* ssid = "RutuIQ";
const char* password = "123456789";

// DHT11 sensor settings
#define DHTPIN D4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  delay(1000);

  dht.begin();

  Serial.println();
  Serial.println("Ambient Temperature IoT Project");
  Serial.println("Connecting to Wi-Fi...");

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  int attempts = 0;

  while (WiFi.status() != WL_CONNECTED && attempts < 40) {
    delay(500);
    Serial.print(".");
    attempts++;
  }

  Serial.println();

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Wi-Fi connected successfully!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("Wi-Fi connection failed.");
    Serial.println("Check hotspot name, password and 2.4 GHz setting.");
  }
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    float temperature = dht.readTemperature();

    if (isnan(temperature)) {
      Serial.println("Could not read temperature. Check sensor wiring.");
    } else {
      Serial.print("Room temperature: ");
      Serial.print(temperature);
      Serial.println(" C");
    }

    delay(2000);
  } else {
    Serial.println("Wi-Fi disconnected. Restart the board to retry.");
    delay(3000);
  }
}