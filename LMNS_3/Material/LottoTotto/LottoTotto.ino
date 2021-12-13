int lottozahlen[6];

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(5000);
  // Eine For-Schleife welche 6x mal durchläuft. Bei jedem Durchlauf wird die draw_number() Funktion
  // aufgerufen welche uns eine zufällige Zahl zurück gibt. Sollte diese Zahl ungültig sein( wurde 
  // bereits gezogen), wird draw_number() erneut aufgerufen. Dies passiert so lange bis eine gültige Zahl
  // gezogen wurde.
  for(int i =0;i<6;i++){
    
    int zahl = 0;

    // Solange die Rückgabe der Funktion draw_number() gleich 0 (ungültig) ist wiederhole den
    // auruf der Funktion draw_number() um eine neue Zahl zu bekommen
    do{
     zahl = draw_number();
    }
    while(zahl == 0);
    
    // Nachdem die do while Schleife fertig ist wissen wir das wir eine gültige Zahl bekommen haben. 
    // Diese wird in dem Array lottozahlen gespeichert
    lottozahlen[i] = zahl;
    
    Serial.println("Die nächste Zahl lautet");
    Serial.println(lottozahlen[i]);
  }

  Serial.println("---------------------------------------");
  delay(3000);

}


int draw_number(){
  // Generiert eine zufällige Zahl zwischen 1-49
  int random_zahl = random(1,49); // 

  // Überprüft alle bereits gespeicherten Lottozahlen und guckt ob es die Aktuelle bereits gibt
  for(int i=0;i<6;i++){
    // Sollte die aktuelle Zahl bereits gezogen sein, wird 0 zurückgegeben um zu Signalisieren das 
    // es eine ungültige Zahl ist.
    if( lottozahlen[i] == random_zahl ){
      Serial.println("Doppelt");
      return 0;
    }
  }
  return random_zahl;
}
