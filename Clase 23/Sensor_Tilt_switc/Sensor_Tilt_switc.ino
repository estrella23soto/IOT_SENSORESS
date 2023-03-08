// Definir el pin al que está conectado el sensor
#define TILT_PIN 5

void setup() {
  Serial.begin(9600);
  pinMode(TILT_PIN, INPUT_PULLUP); // Configurar el pin del sensor como entrada con resistencia pull-up
}

void loop() {
  // Leer el valor del pin del sensor
  int tiltValue = digitalRead(TILT_PIN);

  if (tiltValue == LOW) {
    // El sensor se ha inclinado hacia abajo
    Serial.println("Tilt switch activado");
  } else {
    // El sensor está en posición vertical
    Serial.println("Tilt switch desactivado");
  }

  delay(500); // Esperar un momento antes de volver a leer el sensor
}
