#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "IxD F166";
const char* password = "12345678";

void scrapeData(String URL){
    HTTPClient http;
    http.begin(URL,3200); 
    int httpCode = http.GET();

    if (httpCode == 200) {
      String payload = http.getString(); 

      DynamicJsonDocument doc(24576);
      
      DeserializationError error = deserializeJson(doc, payload);
      
      if (error) {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        return;
      }
      
      const char* id = doc["id"]; // "259"
      
      for (JsonObject stream_item : doc["stream"].as<JsonArray>()) {
      
        const char* stream_item_name = stream_item["name"]; // "\"Fahrräder an StadtRad-Station ...
        const char* stream_item_coordinate = stream_item["coordinate"];

        delay(1000);
        Serial.println("----------------------------------------");
        Serial.println(stream_item_name);
        Serial.println(stream_item_coordinate);
      
      }
      

    } else{
      Serial.println("bad response, check httpCode");
    }
}

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("connecting to WiFi...");
  }
  delay(500);
  Serial.println("connected");
}

void loop() {
  scrapeData("pfuscha.cool"); 
}
