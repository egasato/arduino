// Incluimos las dependencias de Arduino
// Include Arduino's dependencies
#include <Arduino.h>

// Contiene el estado del programa (luz verde o roja intermitente)
// Contains the status of the program (green light or blinking red)
int switchState = 0;

// Función de configuración inicial ejecutada una sola vez por la placa de Arduino una vez se ha encendido o se ha
// presionado el pulsador de reset
// Setup function executed once when the Arduino board is powered or the reset button is pressed
void setup() {
    // Definimos los LEDs para que funcionen en modo salida
    // Set the LEDs to work in output mode
    pinMode(5, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(3, OUTPUT);
    // Definimos el pulsador para que funcione en modo entrada
    // Set the button to work in input mode
    pinMode(2, INPUT);
}

// El código de Arduino que se ejecuta infinitamente (llamada implicita a la función loop al final)
// Arduino code that executes forever (implicit call to the loop function at the end)
void loop() {
    // Leemos el valor de entrada del pulsador
    // Read the input value of the button
    switchState = digitalRead(2);
    // Si no esta apretado solo se enciende el LED verde, si lo está se alternan los LEDs rojos una única vez
    // If it's not pressed turn on only the green LED, otherwise blink the red ones alternately
    if (switchState == LOW) {
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
        digitalWrite(3, HIGH);
    } else {
        digitalWrite(5, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(3, LOW);
        delay(250);
        digitalWrite(5, LOW);
        digitalWrite(4, HIGH);
        digitalWrite(3, LOW);
        delay(250);
    }
}