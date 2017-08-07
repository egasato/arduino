#include <USBAPI.h> // digitalWrite(uint8_t, uint8_t)

// Incluimos la cabecera que contiene las definiciones
// Include the header that contains the definitions
#include "interruptores.h"

// Implementamos la función de la cabecera
// Implement the function declared in the header file
/**
 * Define el estado de los LEDs.
 *
 * @param state el estado de los LEDs (definido con las macros ESTADO_*)
 * @return verdadero si el estado es valido, falso si no lo es
 */
bool estadoLED(uint8_t state) {
	digitalWrite(LED_ROJO_1, (state & ESTADO_LASER_MASK) != 0 ? HIGH : LOW);
	digitalWrite(LED_ROJO_2, (state & ESTADO_DRIVE_MASK) != 0 ? HIGH : LOW);
	digitalWrite(LED_VERDE, (state & ESTADO_READY_MASK) != 0 ? HIGH : LOW);
	return (~ESTADO_ALL_MASK & state) == 0;
}