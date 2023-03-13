#define MOSFET 3
float sollWert = 50;
float Kpr = 2;
float Kir = 0.01;

float e, stellWert, x, xSum, eSum, istSchnitt, istWert, pRegler, iRegler;

void setup() {
  Serial.begin(9600);
  pinMode(MOSFET, OUTPUT);
}

void loop() {
  istWert = getMessWert(A0);
  Serial.println(istWert);
  e = -istWert + sollWert;                 //Regelabweichung berechnen
  eSum = eSum + e;                         //Regelabweichungen aufsummieren
  pRegler = Kpr * e;                       //P-Anteil bestimmen
  iRegler = Kir * eSum;                    //I-Anteil bestimmen
  stellWert = pRegler + iRegler;           //Stellwert berechnen mit P-Regler + I-Regler
  stellWert = constrain(stellWert, 0, 9); //Stellwert begrenzen
  stellWert = stellWert / 9 * 255;        //Stellwert umrechnen auf analogen Ausgang
  analogWrite(MOSFET, stellWert);
}


float getMessWert (int port) {
  xSum = 0;
  for (int i = 0; i < 10; i++) {
    x = -0.4881 * analogRead(port) + 271.83;
    xSum += x;
    delay(1);
  }
  istSchnitt = xSum / 10;
  return istSchnitt;
}
