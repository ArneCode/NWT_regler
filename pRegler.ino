#define w 60 // Sollwert
#define messzeit 300 // Zeit die auf dem seriellen Plotter dargestellt werden soll in s.
float Kpr=20;
float e,y,x,xSum,ySum;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(3,OUTPUT);
Serial.println("w,x,y");
}

void loop() {
xSum=0;
ySum=0;
for (int i=0;i<messzeit*2;i++){
x = 0.000503408*pow(analogRead(A0),2) - 1.039946385*analogRead(A0) + 424.348317221;
e=-x+w;
y = constrain(Kpr*e,0,12); // Beschränkt den Stellwert y auf eine Zahl zwischen 0 und 12, je nachdem wie groß die Proportionalitätskonstante mal die Regelabweichung ist. 
analogWrite(3,y/12*255); // Dimmung der Lampe mit Hilfe der PWM Modulation (255 (höchster Wert des Arduinos) steht für 12V)
xSum += x;
ySum += y;
delay(1);
}
Serial.print(w);
Serial.print(" , ");
Serial.print(xSum/(messzeit*2));
Serial.print(" , ");
Serial.println(ySum/(messzeit*2));
}
