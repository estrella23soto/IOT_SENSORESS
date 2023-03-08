#include <Servo.h>  // Librería para controlar el servo motor
#include <DHT.h>    // Librería para leer el sensor DHT11

#define DHTPIN 2    // Pin digital utilizado para el sensor DHT11
#define DHTTYPE DHT11   // Tipo de sensor DHT utilizado

DHT dht(DHTPIN, DHTTYPE);  // Crear objeto DHT

Servo myservo;  // Crear objeto Servo

void setup() {
  dht.begin();    // Inicializar el sensor DHT
  myservo.attach(9);   // Asignar el pin 9 para el servo motor
}

void loop() {
  int humedad = dht.readHumidity();  // Leer la humedad del aire
  int temperatura = dht.readTemperature(); // Leer la temperatura

  // Si no se puede leer la humedad o temperatura, imprimir mensaje de error
  if (isnan(humedad) || isnan(temperatura)) {
    Serial.println("Error al leer el sensor DHT11");
    return;
  }

  // Mover el servo motor según el valor de la humedad
  if (humedad < 50) {
    myservo.write(0);  // Mover el servo motor a 0 grados
  } else {
    myservo.write(90);  // Mover el servo motor a 90 grados
  }

  // Imprimir los valores de humedad y temperatura en el monitor serial
  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.print("%  Temperatura: ");
  Serial.print(temperatura);
  Serial.println("°C");

  delay(2000);  // Esperar 2 segundos antes de leer el sensor nuevamente
}
