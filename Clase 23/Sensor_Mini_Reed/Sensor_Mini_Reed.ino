// Incluir la biblioteca de pines de entrada y salida
#include <Arduino.h>

// Definir el pin del mini reed switch y el pin de salida del LED
#define REED_PIN 2
#define LED_PIN 13

void setup() {
  // Configurar el pin del mini reed switch como entrada
  pinMode(REED_PIN, INPUT);

  // Configurar el pin de salida del LED como salida
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Leer el valor del pin del mini reed switch
  int reed = digitalRead(REED_PIN);

  // Si el interruptor está cerrado (imán cerca), encender el LED
  if (reed == HIGH) {
    digitalWrite(LED_PIN, HIGH);
  } 
  // De lo contrario, apagar el LED
  else {
    digitalWrite(LED_PIN, LOW);
  }

  // Esperar un momento antes de volver a verificar el estado del interruptor
  delay(100);
}
