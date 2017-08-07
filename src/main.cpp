// Incluimos las dependencias de Arduino
// Include Arduino's dependencies
#include <Arduino.h>

// Incluimos la cabecera que contiene las definiciones
// Include the header that contains the definitions
#include "interruptores.h" // estadoLED

// Contienen la lectura temporal del botón, el estado actual y el estado anterior
// Contains the temporal read value from the button, the current state and the previous one
int tmpRead, currentState, previousState;

// Contienen un valor obtenido por el reloj de la placa y el tiempo que ha pasado entre las dos lecturas
// Contains a value from the boards' clock and the difference of time between two reads from it
unsigned long start, delta;

// Función de configuración inicial ejecutada una sola vez por la placa de Arduino una vez se ha encendido o se ha
// presionado el botón de reset
// Setup function executed once when the Arduino board is powered or the reset button is pressed
void setup() {
	// Asignamos los valores iniciales
	// Assign initial values
	previousState = currentState = 0;
	// Definimos los LEDs para que funcionen en modo salida
	// Set the LEDs to work in output mode
	pinMode(LED_ROJO_1, OUTPUT);
	pinMode(LED_ROJO_2, OUTPUT);
	pinMode(LED_VERDE, OUTPUT);
	// Definimos el pulsador para que funcione en modo entrada
	// Set the button to work in input mode
	pinMode(PULSADOR, INPUT);
}

/**
 * Espera el tiempo especificado en milisegundos y actualiza "currentState"
 *
 * @param time el tiempo que esperamos en milisegundos
 */
void esperaActiva(unsigned long time) {
	start = millis();
	do {
		tmpRead = digitalRead(PULSADOR);
		if (currentState == 0 && tmpRead == HIGH && previousState != tmpRead) {
			currentState = 0;
		}
		previousState = tmpRead;
		delta = millis() - start;
	} while (delta < time);
}

// El código de Arduino que se ejecuta infinitamente (llamada implicita a la función loop al final)
// Arduino code that executes forever (implicit call to the loop function at the end)
void loop() {
	// Leemos el estado actual y lo comparamos con el anterior del PULSADOR, si son diferentes y
	// estamos en el flanco ascendente (HIGH) entonces invertimos el estado del PULSADOR (virtual).
	tmpRead = digitalRead(PULSADOR);
	if (tmpRead == HIGH && tmpRead != previousState) {
		currentState = 1 - currentState;
	}
	previousState = tmpRead;
	// Si el estado del PULSADOR es desactivado, entonces encendemos el LED verde y apagamos los rojos.
	// Sino, alternamos entre el primer y el segundo LED rojo cada 250 milisegundos comprobando el estado del PULSADOR.
	if (currentState == 0) {
		estadoLED(ESTADO_READY);
	} else {
		estadoLED(ESTADO_DRIVE);
		esperaActiva(250);
		estadoLED(ESTADO_LASER);
		esperaActiva(250);
	}
}