const int sensorPin = 34; // Pin del sensor de inclinación
int sensorValue = 0; // Variable para almacenar el valor del sensor

void setup() {
  pinMode(sensorPin, INPUT); // Configurar el pin del sensor como entrada
  Serial.begin(9600); // Inicializar la comunicación serial
}

void loop() {
  sensorValue = analogRead(sensorPin); // Leer el valor del sensor

  if (sensorValue < 500) { // Si el valor del sensor es menor a 500
    Serial.println("Inclinación detectada"); // Imprimir un mensaje por el puerto serial
  }

  delay(10); // Pequeña pausa para evitar la sobrecarga del microcontrolador
}