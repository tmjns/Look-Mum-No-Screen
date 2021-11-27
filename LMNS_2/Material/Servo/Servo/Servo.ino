#include <Servo.h> // Einbinden der Servo Bibliothek

Servo myservo; // Object der Servo Klasse erstellen 
#define servo_pin 9

void setup() {
  
  Serial.begin(9600); // Öffnet die serielle Schnittstelle und stellt die Datenrate auf 9600 Bit/s ein
  myservo.attach(servo_pin); // Definiert Pin 9 für den Servo 
}

void loop() {
  
     myservo.write(50); // Sagt dem Servo an Position "50" zu gehen 
     delay(1000); // Wartet 1000 millisekunden -> 1 Sekunde 
     myservo.write(70); // Sagt dem Servo an Position "70" zu gehen 
     delay(1000); // Wartet 1000 millisekunden -> 1 Sekunde 
}
