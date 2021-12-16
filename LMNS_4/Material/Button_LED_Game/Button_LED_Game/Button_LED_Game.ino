
// Globale Variablen 
long start_timer = 0;
int randNumber = 0;

void setup() {
  // Öffnet die serielle Schnittstelle und stellt die Datenrate auf 9600 Bit/s ein
  Serial.begin(9600); 
  // Den Pin der LED als "OUTPUT" definieren
  pinMode(13,OUTPUT); 
  // Den Pin des Tasters als "INPUT" definieren
  pinMode(8,INPUT);

  // Initialer aufruf der "start_game" Funktion um das Spiel zu starten
  start_game();
}

void loop() {

  // Auslesen des 
  int button_value = digitalRead(8);

  // Wenn der Knopf gedrückt wurde dann ... 
  if(button_value == HIGH){
    // Aktuellen Timestamp mit der Startzeit vergleichen um die Reaktionszeit zu bestimmen
    Serial.println( (String) "NICHT SCHLECHT " + ( millis() - start_timer) );
    // LED ausschalten
    digitalWrite(13,LOW);
    // Kurz warten bis die nächste Runde startet
    delay(3000);

    // Ruft die Funktion "start_game" auf um eine neue Runde zu starten
    start_game();
  } 

  delay(10);
}


void start_game(){
  Serial.println("NEUE RUNDE NEUES GLÜCK");
  // Eine zufällige Zahl generieren zwischen 2000-10000
  randNumber = random(2000, 10000);
  // Die zufällig generierte Zahl in millisekunden abwarten. Zwischen 2-10 Sekunden
  delay(randNumber);
  // LED einschalten
  digitalWrite(13,HIGH);
  // Den Aktuellen millisekunden Wert in der Variable "start_timer" abspeicher. 
  start_timer = millis();
}
