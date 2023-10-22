#include <Arduino.h>
#include <WiFi.h>

#define WIFI_SSID "BELL124"
#define WIFI_PASSWORD "temp"

void setup() {
  Serial.begin(921600);
  pinMode(LED_BUILTIN, OUTPUT); // Set pin mode of the built in LED

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.println("Initializing");
}

bool isConnected = false;

void loop() {
  if (WiFi.status() == WL_CONNECTED && !isConnected) {
    Serial.println("Connected");
    digitalWrite(LED_BUILTIN, HIGH);
    isConnected = true;
  }

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println(".");
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    isConnected = false;
    delay(100);
  }
}
