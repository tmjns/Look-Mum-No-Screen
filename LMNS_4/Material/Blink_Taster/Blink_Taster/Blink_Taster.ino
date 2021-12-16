#define led_pin 13
#define button_pin 8

void setup() {
  Serial.begin(9600); // Öffnet die serielle Schnittstelle und stellt die Datenrate auf 9600 Bit/s ein
  pinMode(led_pin,OUTPUT); // Definiert Pin 13 als Outout
  pinMode(button_pin,INPUT); // Definiert Pin 8 als Input
}

void loop() {

  int button_value = digitalRead(button_pin); // Ließt den Wert von Pin 8 und speichern ihn in die Variable "button_value" 
  
  if(button_value == 1){ // Sollte der Wert in der Variable "button_value" gleich "1" ist dann ...
    Serial.println("LICHT AN"); // Schreibe "LICHT AN" 
    digitalWrite(led_pin,HIGH); // Setz den Pin 13 auf "High" 
  } else { // Sollte der Wert in der Varibale "button_value" nicht gleich "1" sein dann ...
    digitalWrite(led_pin,LOW); // Setz den Pin 13 auf "Low" 
  }

  delay(10); // Warte 10 millisekunden 
}
