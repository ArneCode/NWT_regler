/*
   KTY81-110 im Spannungsteiler  mit 1kOhm als Vergleichswiderstand

*/
#define sensor A0
int temperaturWert;

void setup() {
  Serial.begin(9600);   // serieller Plotter und serieller Monitor haben die gleiche Schnittstelle!
}
void loop() {
  temperaturWert = analogRead(sensor);
  Serial.println(temperaturWert);
  delay (5000);

}
