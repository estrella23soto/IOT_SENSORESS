const int relayPin = 5; // Pin del módulo de relé
bool relayState = false; // Variable para almacenar el estado del relé

void setup() {
  pinMode(relayPin, OUTPUT); // Configurar el pin del relé como salida
  Serial.begin(9600); // Inicializar la comunicación serial
}

void loop() {
  if (relayState == false) { // Si el relé está apagado
    digitalWrite(relayPin, HIGH); // Encender el relé
    Serial.println("Relé encendido"); // Imprimir un mensaje por el puerto serial
    relayState = true; // Actualizar el estado del relé
  } else { // Si el relé está encendido
    digitalWrite(relayPin, LOW); // Apagar el relé
    Serial.println("Relé apagado"); // Imprimir un mensaje por el puerto serial
    relayState = false; // Actualizar el estado del relé
  }

  delay(1000); // Pequeña pausa para que se pueda apreciar el cambio de estado del relé
}