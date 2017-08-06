// Incluimos las dependencias de Arduino
// Include Arduino's dependencies
#include <Arduino.h>

// Función de configuración inicial ejecutada una sola vez por la placa de Arduino una vez se ha encendido o se ha
// presionado el botón de reset
// Setup function executed once when the Arduino board is powered or the reset button is pressed
void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
}

// El código de Arduino que se ejecuta infinitamente (llamada implicita a la función loop al final)
// Arduino code that executes forever (implicit call to the loop function at the end)
void loop() {
    // Enciende el LED incorporado y espera 1 segundo
    // Turns on the built-in LED and waits 1 second
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    // Apaga el LED incorporado y espera 1 segundo
    // Turns off the built-in LED and waits 1 second
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
}