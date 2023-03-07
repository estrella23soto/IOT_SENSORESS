// Incluimos la librería para el ESP32
#include <Arduino.h>

// Pin en el que conectamos el sensor de llama
#define FLAME_SENSOR_PIN 32

void setup() {
  // Inicializamos el monitor serie a 115200 baudios
  Serial.begin(115200);
  
  // Configuramos el pin del sensor de llama como entrada
  pinMode(FLAME_SENSOR_PIN, INPUT);
}

void loop() {
  // Leemos el valor del sensor de llama
  int flameValue = digitalRead(FLAME_SENSOR_PIN);
  
  // Si el valor es alto, hay una llama detectada
  if (flameValue == HIGH) {
    Serial.println("¡Llama detectada!");
  } else {
    Serial.println("No hay llama");
  }
  
  // Esperamos 500 ms antes de volver a leer el sensor
  delay(500);
}
