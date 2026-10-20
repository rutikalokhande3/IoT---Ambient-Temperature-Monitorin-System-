#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

// 1. Your mobile hotspot details
const char* ssid = "RutuIQ";
const char* password = "123456789";

// 2. MQTT test broker
const char* mqtt_server = "test.mosquitto.org";
const int mqtt_port = 1883;

// Use a project-specific topic for this demonstration
const char* mqtt_topic = "iot/ambient-temp/kau-demo-8266";

// 3. DHT11 sensor settings
#define DHTPIN D4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

WiFiClient espClient;
PubSubClient client(espClient);

unsigned long lastPublish = 0;

void connectWiFi() {
  Serial.print("Connecting to Wi-Fi...");

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
    Serial.println("Wi-Fi connected!");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("Wi-Fi connection failed.");
  }
}

bool connectMQTT() {
  if (client.connected()) {
    return true;
  }

  // Unique client ID for this device
  String clientId = "ESP8266-";
  clientId += String(ESP.getChipId(), HEX);

  Serial.print("Connecting to MQTT broker...");

  if (client.connect(clientId.c_str())) {
    Serial.println("connected!");
    Serial.print("Publishing topic: ");
    Serial.println(mqtt_topic);
    return true;
  }

  Serial.print("failed, state = ");
  Serial.println(client.state());
  return false;
}

void setup() {
  Serial.begin(9600);
  delay(1000);

  dht.begin();

  Serial.println();
  Serial.println("Ambient Temperature IoT Project");

  connectWiFi();

  client.setServer(mqtt_server, mqtt_port);
  client.setBufferSize(256);
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Wi-Fi disconnected. Retrying...");
    connectWiFi();
    delay(1000);
    return;
  }

  if (!client.connected()) {
    if (!connectMQTT()) {
      delay(3000);
      return;
    }
  }

  client.loop();

  if (millis() - lastPublish >= 5000) {
    lastPublish = millis();

    float temperature = dht.readTemperature();

    if (isnan(temperature)) {
      Serial.println("DHT11 read failed. Check sensor wiring.");
      return;
    }

    char message[32];
    snprintf(message, sizeof(message), "%.1f", temperature);

    Serial.print("Temperature: ");
    Serial.print(message);
    Serial.println(" C");

    if (client.publish(mqtt_topic, message)) {
      Serial.println("MQTT publish successful!");
    } else {
      Serial.println("MQTT publish failed.");
    }

    Serial.println("--------------------");
  }
}