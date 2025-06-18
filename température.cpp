#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  Serial.print("Température: ");
  Serial.print(temp);
  Serial.print(" °C, Humidité: ");
  Serial.print(hum);
  Serial.println(" %");
  delay(2000);
}
