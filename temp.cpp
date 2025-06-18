#include <WiFiS3.h>

const char* ssid = "Senkuuu";
const char* password = "Dysprosium";
const char* serverUrl = "https://btscielvitry.github.io/Yaoul/index.html";

void setup() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    String postData = "temperature=22.5&humidite=40";
    http.POST(postData);
    http.end();
  }
  delay(5000);
}
