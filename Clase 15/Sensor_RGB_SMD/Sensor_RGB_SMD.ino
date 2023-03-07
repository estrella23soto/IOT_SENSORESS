// Incluye la biblioteca para el sensor RGB
#include <Adafruit_TCS34725.h>

// Crea un objeto TCS34725 para el sensor RGB
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup() {
  // Inicializa el sensor RGB
  tcs.begin();
  
  // Configura la velocidad de transmisión de serie
  Serial.begin(9600);
}

void loop() {
  // Lee los valores de color del sensor RGB
  uint16_t r, g, b, c;
  tcs.getRawData(&r, &g, &b, &c);
  
  // Imprime los valores de color en la consola serie
  Serial.print("Red:   "); Serial.print(r);
  Serial.print(" Green: "); Serial.print(g);
  Serial.print(" Blue:  "); Serial.print(b);
  Serial.print(" Clear: "); Serial.println(c);
  
  // Espera un corto período antes de volver a leer los valores de color
  delay(500);
}
