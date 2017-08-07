// Header Guard (evita múltiples inclusiones)
// Header Guard (avoids multiple inclusions)
#ifndef ARDUINO_INTERRUPTORES_H
#define ARDUINO_INTERRUPTORES_H

#include <stdint.h> // uint8_t

// Macros que definen los pines
// Pin-defining macros
#define LED_ROJO_1 5
#define LED_ROJO_2 4
#define LED_VERDE  3
#define PULSADOR   2

// Define la máscara asociada a cada LED
// Mask associated to each LED
#define ESTADO_READY_MASK 0b001
#define ESTADO_DRIVE_MASK 0b010
#define ESTADO_LASER_MASK 0b100
#define ESTADO_ALL_MASK (ESTADO_READY_MASK | ESTADO_DRIVE_MASK | ESTADO_LASER_MASK)

// Definimos los estados de la nave espacial
// Set the spaceship states
#define ESTADO_READY ESTADO_READY_MASK
#define ESTADO_DRIVE ESTADO_DRIVE_MASK
#define ESTADO_LASER ESTADO_LASER_MASK

/**
 * Sets the state of the LEDs.
 *
 * @param state the state of the LEDs (defined in ESTADO_* macros)
 * @return true if the state is valid, otherwise false
 */
bool estadoLED(uint8_t state);

#endif //ARDUINO_INTERRUPTORES_H