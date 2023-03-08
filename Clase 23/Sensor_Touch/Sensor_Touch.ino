// Incluye la biblioteca para el sensor ultrasónico
#include <NewPing.h>

// Configura los pines para el sensor ultrasónico
#define TRIGGER_PIN  12  // Pin del trigger
#define ECHO_PIN     13  // Pin del echo
#define MAX_DISTANCE 200 // Distancia máxima en cm (puede ajustarse)

// Configura el pin para el motor
#define MOTOR_PIN 14

// Crea un objeto NewPing para el sensor ultrasónico
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  // Configura el pin del motor como salida
  pinMode(MOTOR_PIN, OUTPUT);
}

void loop() {
  // Mide la distancia con el sensor ultrasónico
  int distance = sonar.ping_cm();

  // Si la distancia es menor que 10 cm, enciende el motor
  if (distance < 10) {
    digitalWrite(MOTOR_PIN, HIGH);
  }
  // De lo contrario, apaga el motor
  else {
    digitalWrite(MOTOR_PIN, LOW);
  }
  
  // Espera un corto período antes de volver a medir la distancia
  delay(50);
}

