#define y 12     // 12 Volt Stellwert
float x, xSum;
float sollWert = 60; // Hier denn Sollwert anpassen


void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  //analogWrite(3,float(y)/12*255);
}

void loop() {
  xSum = 0;
  for (int i = 0; i < 100; i++) {
    x = - 0.00819696*pow(6.71408816*analogRead(A0) - 1304.22303995; // Hier die eigene Funktion der Kalibrierung eintragen
    xSum += x;
    delay(1);
  }
  Serial.print(float(millis()) / 1000); // Angabe in Sekunde
  Serial.print(";");
  Serial.println(xSum / (100));

  if (x < sollWert)
  {
    analogWrite(3, float(y) / 12 * 255);
  }
  else
  {
    analogWrite(3, 0);
  }
}
