// AFROIOIOT ENGINEERS 2025 CONNECTED CANE
// Detects obstacles with HC-SR04 + Buzzer alert + Vibration
// Adjustable range: 50cm to 2m

// Define the pins
const int trigPin = 9; // HC-SR04 Trig Pin
const int echoPin = 10; // HC-SR04 Echo Pin
const int buzzerPin = 11; // Active Buzzer Pin
const int vibrPin = 12; // Vibration Motor Pin

// Variables
long duration;

int distance;

int alertThreshold = 100; // Alert distance in cm. Set to 50, 100, or 200

void setup() {
pinMode(trigPin, OUTPUT);

pinMode(echoPin, INPUT);

pinMode(buzzerPin, OUTPUT);

pinMode(vibrPin, OUTPUT);

Serial.begin(9600); // To view distance on PC

Serial.println("AfroIoT Connected Cane - Starting...");

}

void loop() {

/ // 1. Send ultrasonic pulse

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

/ // 2. Read the return time

duration = pulseIn(echoPin, HIGH);

/ // 3. Calculate distance in cm: speed of sound = 343 m/s

distance = duration * 0.034 / 2;

/ // 4. Display on Serial Monitor for testing

Serial.print("Distance: ");

Serial.print(distance); Serial.println(" cm");

/ // 5. If obstacle detected < alertThreshold

if (distance < alertThreshold && distance > 0) {

/ // The closer the obstacle, the faster it beeps

int beepSpeed = map(distance, 0, alertThreshold, 50, 500);

digitalWrite(buzzerPin, HIGH);

digitalWrite(vibrPin, HIGH);

delay(beepSpeed);

digitalWrite(buzzerPin, LOW);

digitalWrite(vibrPin, LOW);

delay(beepSpeed);

} else {

/ // No obstacle: everything off

digitalWrite(buzzerPin, LOW);

digitalWrite(vibrPin, LOW);

}

delay(100); // Short pause between measurements
}
