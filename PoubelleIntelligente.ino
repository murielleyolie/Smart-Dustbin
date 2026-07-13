 
#include <Servo.h>

// Définition des broches pour le capteur "main"
const int trigMain = 5;
const int echoMain = 4;

// Définition des broches pour le capteur de niveau
const int trigNiveau = 7;
const int echoNiveau = 6;

// Servo
const int pinServo = 13;
Servo monServo;

// LEDs
const int ledRouge = 10;
const int ledVerte = 8;
    
// Seuil de niveau (à ajuster selon la hauteur de ta poubelle)
const int seuilPleinCM = 10;

void setup() {
  Serial.begin(9600);

  // Capteur main
  pinMode(trigMain, OUTPUT);
  pinMode(echoMain, INPUT);

  // Capteur niveau
  pinMode(trigNiveau, OUTPUT);
  pinMode(echoNiveau, INPUT);

  // LEDs
  pinMode(ledRouge, OUTPUT);
  pinMode(ledVerte, OUTPUT);

  // Servo
  monServo.attach(pinServo);
  monServo.write(0); // Position fermée
}

void loop() {
  // 1. Lire distance main
  long distanceMain = mesurerDistance(trigMain, echoMain);
 
  if (distanceMain > 0 && distanceMain < 15) {
    Serial.write("obstacle"); 
    monServo.write(90); // Ouvrir
    delay(3000);        // Attente
    monServo.write(0);  // Fermer
  }

  // 2. Lire niveau de remplissage
  long distanceNiveau = mesurerDistance(trigNiveau, echoNiveau);
  Serial.write("distanceNiveau",distanceNiveau); 
  if (distanceNiveau > 0 && distanceNiveau < seuilPleinCM) {
    Serial.write("ohhhhhhhhhhhh"); 
    digitalWrite(ledRouge, HIGH);
    digitalWrite(ledVerte, LOW);
    Serial.println("Poubelle pleine !");
  } else {
    digitalWrite(ledRouge, LOW);
    digitalWrite(ledVerte, HIGH);
    Serial.println("Poubelle OK.");
  }

  delay(1000);
}

// Fonction de mesure de distance pour HC-SR04
long mesurerDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duree = pulseIn(echoPin, HIGH);
  long distance = duree * 0.034 / 2;

  return distance;
}

