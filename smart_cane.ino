// CANNE CONNECTÉE AFROIOIOT ENGINEERS 2025
// Détecte obstacles avec HC-SR04 + Alerte Buzzer + Vibration
// Portée réglable : 50cm à 2m

// Définir les pins
const int trigPin = 9;      // Pin Trig HC-SR04
const int echoPin = 10;     // Pin Echo HC-SR04  
const int buzzerPin = 11;   // Pin Buzzer actif
const int vibrPin = 12;     // Pin Moteur vibration

// Variables
long duration;
int distance;
int seuilAlerte = 100; // Distance d'alerte en cm. Mets 50, 100, ou 200

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(vibrPin, OUTPUT);
  
  Serial.begin(9600); // Pour voir distance sur PC
  Serial.println("Canne Connectée AfroIot - Démarrage...");
}

void loop() {
  // 1. Envoyer impulsion ultrason
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // 2. Lire le temps de retour
  duration = pulseIn(echoPin, HIGH);
  
  // 3. Calculer distance en cm : vitesse son = 343m/s
  distance = duration * 0.034 / 2;
  
  // 4. Afficher sur Moniteur Série pour test
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // 5. Si obstacle détecté < seuilAlerte
  if (distance < seuilAlerte && distance > 0) {
    
    // Plus l’obstacle est proche, plus ça bip vite
    int vitesseBip = map(distance, 0, seuilAlerte, 50, 500);
    
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(vibrPin, HIGH);
    delay(vitesseBip);
    
    digitalWrite(buzzerPin, LOW);
    digitalWrite(vibrPin, LOW);
    delay(vitesseBip);
    
  } else {
    // Pas d’obstacle : tout éteint
    digitalWrite(buzzerPin, LOW);
    digitalWrite(vibrPin, LOW);
  }
  
  delay(100); // Petite pause entre mesures
}