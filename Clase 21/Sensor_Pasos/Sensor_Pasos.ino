#include <Stepper.h>  // Librería para controlar el motor a pasos

#define STEPS_PER_REV 2048  // Número de pasos por vuelta del motor
#define DELAY_TIME 5    // Tiempo de espera entre pasos del motor (en ms)

// Definir los pines utilizados para el motor a pasos
#define DIR_PIN 19
#define STEP_PIN 18

// Definir el pin utilizado para el sensor de choque
#define SHOCK_PIN 2

// Crear objeto Stepper para el motor a pasos
Stepper motor(STEPS_PER_REV, DIR_PIN, STEP_PIN);

void setup() {
  pinMode(SHOCK_PIN, INPUT_PULLUP);  // Establecer el pin del sensor de choque como entrada
  motor.setSpeed(500);  // Establecer la velocidad del motor a pasos (en rpm)
}

void loop() {
  // Leer el valor del sensor de choque
  int shockValue = digitalRead(SHOCK_PIN);

  // Si el sensor de choque detecta una colisión, mover el motor a pasos en sentido contrario
  if (shockValue == LOW) {
    motor.setSpeed(500);  // Establecer la velocidad del motor a pasos (en rpm)
    motor.step(-STEPS_PER_REV);  // Mover el motor a pasos en sentido contrario a las agujas del reloj (una vuelta completa)
  } else {
    motor.setSpeed(1000);  // Establecer la velocidad del motor a pasos (en rpm)
    motor.step(STEPS_PER_REV);  // Mover el motor a pasos en sentido de las agujas del reloj (una vuelta completa)
  }

  delay(DELAY_TIME);  // Esperar un tiempo antes de leer el sensor de choque nuevamente
}
