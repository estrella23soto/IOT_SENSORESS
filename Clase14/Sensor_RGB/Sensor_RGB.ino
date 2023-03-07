// Incluimos la librería para el ESP32
#include <Arduino.h>

// Pins en los que conectamos el sensor RGB
#define RED_PIN 26
#define GREEN_PIN 27
#define BLUE_PIN
 14

void setup() {
  // Configuramos los pines del sensor RGB como salidas
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  // Encendemos el LED rojo
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
  delay(1000);
  
  // Encendemos el LED verde
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);
  delay(1000);
  
  // Encendemos el LED azul
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);
  delay(1000);
  
  // Encendemos el LED blanco
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
  delay(1000);
}
