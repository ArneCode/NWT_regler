float x, xSum;
float sollWert = 60; // Hier den Sollwert einstellen
float Hysterese = 4; // Hier den Hysteresewert einstellen


void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}

void loop() {
  xSum = 0;
  for (int i = 0; i < 500; i++) {
    x =  -0.518700233* analogRead(A0) + 286.315611679; // Hier die eigene Funktion der Kalibrierung eintragen
    if (x < sollWert - Hysterese / 2)  {
      digitalWrite(3, HIGH);
    }
    if (x > sollWert + Hysterese / 2)  {
      digitalWrite(3, LOW);
    }
    xSum += x;
    delay(1);
  }
  Serial.println(xSum / (500));
}
