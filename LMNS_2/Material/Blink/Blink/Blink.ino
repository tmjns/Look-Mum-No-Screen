#define led_pin 13

void setup() {
  Serial.begin(9600); // Öffnet die serielle Schnittstelle und stellt die Datenrate auf 9600 Bit/s ein
  pinMode(led_pin,OUTPUT); // Definiert Pin 13 als Outout
}

void loop() {

  digitalWrite(led_pin,HIGH); // Setz den Pin 13 auf "High" 
  delay(1000); // Wartet 1000 millisekunden -> 1 Sekunde 
  digitalWrite(led_pin,LOW); // Setz den Pin 13 auf "Low" 
  delay(1000); // Wartet 1000 millisekunden -> 1 Sekunde 
}
