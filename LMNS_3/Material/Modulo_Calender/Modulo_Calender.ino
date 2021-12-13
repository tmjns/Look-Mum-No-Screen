int month[] = {31,28,31,30,31,30,31,31,30,31,30,31};

void setup() {
   Serial.begin(9600);  
}


void loop() {
  for(int i=0;i<12;i++){
     Serial.println(String() +"Monat: " + i+1  +" -- " + calculate_weeks(i) );
     delay(1000);
  }
}


int calculate_weeks(int m){
  int rest = month[m]%7;
  return (rest);
}