#include <Adafruit_GFX.h>    // Librería para gráficos en pantallas LED
#include <Adafruit_NeoMatrix.h>    // Librería para controlar matrices de LEDs
#include <Adafruit_NeoPixel.h>    // Librería para controlar LEDs
#include <Adafruit_PCD8544.h>    // Librería para controlar pantallas Nokia 5110

#define BUTTON_PIN 2    // Pin utilizado para el botón

#define MATRIX_WIDTH 8    // Ancho de la matriz de LEDs
#define MATRIX_HEIGHT 8    // Altura de la matriz de LEDs

// Crear objeto Adafruit_NeoMatrix para la matriz de LEDs
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(MATRIX_WIDTH, MATRIX_HEIGHT, 6,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);

// Crear objeto Adafruit_PCD8544 para la pantalla Nokia 5110
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

// Definir el número de LEDs en la matriz de LEDs
#define NUM_LEDS MATRIX_WIDTH * MATRIX_HEIGHT

// Crear objeto Adafruit_NeoPixel para controlar los LEDs
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_LEDS, 8, NEO_GRB + NEO_KHZ800);

// Variables para el botón
int buttonState = 0;
int lastButtonState = 0;

void setup() {
  matrix.begin();    // Inicializar la matriz de LEDs
  matrix.setBrightness(100);    // Establecer el brillo de la matriz de LEDs (0-255)
  matrix.clear();    // Limpiar la matriz de LEDs

  display.begin();    // Inicializar la pantalla Nokia 5110
  display.setContrast(50);    // Establecer el contraste de la pantalla Nokia 5110 (0-127)
  display.clearDisplay();    // Limpiar la pantalla Nokia 5110

  pixels.begin();    // Inicializar los LEDs
  pixels.clear();    // Apagar los LEDs
  pixels.show();    // Mostrar los cambios en los LEDs

  pinMode(BUTTON_PIN, INPUT_PULLUP);    // Establecer el pin del botón como entrada con pull-up interno
}

void loop() {
  // Leer el valor del botón
  buttonState = digitalRead(BUTTON_PIN);

  // Si el botón se presiona, encender los LEDs y mostrar un mensaje en la pantalla Nokia 5110 y la matriz de LEDs
  if (buttonState == LOW && lastButtonState == HIGH) {
    pixels.fill(255, 255, 255);    // Encender todos los LEDs en blanco
    pixels.show();    // Mostrar los cambios en los LEDs

    display.clearDisplay();    // Limpiar la pantalla Nokia 5110
    display.setCursor(0, 0);    // Establecer la posición del cursor en la pantalla Nokia 5110
    display.println("Cruz Estrella");    // Mostrar el primer nombre en la pantalla Nokia 5110
    display.println("Juarez Soto");    // Mostrar los apellidos en la pantalla Nokia 5110
    display.display();   
  }
