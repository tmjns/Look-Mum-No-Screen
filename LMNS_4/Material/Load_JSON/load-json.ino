#include <ArduinoJSON.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(1000);
  DynamicJsonDocument doc(2048);
  deserializeJson(doc, "{\r\n\"product\":\"Playstion 5\",\r\n\"price\":\"499.99\u20AC\",\r\n\"available\"true,\r\n\"specs\":[\r\n100.50,\r\n290.40,\r\n38.39\r\n],\r\n\"extras\":{\r\n\"colors\":[\r\n{\r\n\"white\":\"#FFFFFF\"\r\n},\r\n{\r\n\"black\":\"#000000\"\r\n},\r\n{\r\n\"red\":\"#FF0000\"\r\n}\r\n]\r\n}\r\n}");
  const char* product = doc["product"];
  Serial.println(product);
}