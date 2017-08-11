// Incluimos las dependencias de Arduino
// Include Arduino's dependencies
#include <Arduino.h>

// Define el pin analógico del termómetro
// Sets the analog pin of the thermometer
const int sensorPin = A0;
const float baselineTemp = 22.0;

// Función de configuración inicial ejecutada una sola vez por la placa de Arduino una vez se ha encendido o se ha
// presionado el botón de reset
// Setup function executed once when the Arduino board is powered or the reset button is pressed
void setup() {
	// Iniciamos la comunicación serial a 9600 bauds
	// Initialize the serial communication at a rate of 9600 bauds
	Serial.begin(9600);
	// Definimos todos los LEDs como salida y apagados
	// Set all LEDs to output and turned off
	for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
		pinMode(pinNumber, OUTPUT);
		digitalWrite(pinNumber, LOW);
	}
}

// El código de Arduino que se ejecuta infinitamente (llamada implicita a la función loop al final)
// Arduino code that executes forever (implicit call to the loop function at the end)
void loop() {
	// Leemos el valor que nos da el sensor y lo mostramos (por el serial)
	// Read the value from the sensor and print it (though the serial)
	int sensorVal = analogRead(sensorPin);
	Serial.print("Sensor value: ");
	Serial.print(sensorVal);
	// Calculamos el voltage asociado a ese valor
	// Calculate the mapped value to a voltage
	float voltage = (sensorVal / 1024.0) * 5.0;
	Serial.print(", Volts: ");
	Serial.print(voltage);
	// Calculamos la temperatura en base al voltage
	// Caulculate the temperature using that voltage
	float temperature = (voltage - 0.5) * 100;
	Serial.print(", degrees C: ");
	Serial.println(temperature);
	// Mostramos el valor leído usando los LEDs
	// Show the measured value using a the LEDs
	if (temperature < baselineTemp + 2.0) {
		digitalWrite(2, LOW);
		digitalWrite(3, LOW);
		digitalWrite(4, LOW);
	} else if (temperature >= baselineTemp + 2.0 && temperature < baselineTemp + 4.0) {
		digitalWrite(2, HIGH);
		digitalWrite(3, LOW);
		digitalWrite(4, LOW);
	} else if (temperature >= baselineTemp + 4.0 && temperature < baselineTemp + 6.0) {
		digitalWrite(2, HIGH);
		digitalWrite(3, HIGH);
		digitalWrite(4, LOW);
	} else if (temperature >= baselineTemp + 6.0) {
		digitalWrite(2, HIGH);
		digitalWrite(3, HIGH);
		digitalWrite(4, HIGH);
	}
	// Necesitamos un delay para no leer mal los valores
	// Wait a little to read values correctly
	delay(1);
}