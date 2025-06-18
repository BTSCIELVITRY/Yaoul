#include <WiFiS3.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD I2C à l'adresse 0x27 (modifie si nécessaire)
LiquidCrystal_I2C lcd(0x27, 16, 2);

const char* ssid = "Senkuuu";
const char* password = "Dysprosium";

WiFiServer server(80);
String currentMessage = "Bonjour !";

void setup() {
  Serial.begin(115200);

  // Initialisation de l'écran LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(currentMessage);

  // Connexion Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnecté au Wi-Fi !");
  Serial.print("IP : ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("Client connecté");

    // Lis la requête (même si on ne l’utilise pas ici)
    String request = client.readStringUntil('\r');
    Serial.println(request);

    // Répond avec le texte affiché
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/plain");
    client.println("Connection: close");
    client.println();
    client.println(currentMessage);  // Texte actuel affiché

    delay(1);
    client.stop();
    Serial.println("Client déconnecté");
  }

  // (Tu peux ajouter ici des changements de message dynamiques si nécessaire)
}
