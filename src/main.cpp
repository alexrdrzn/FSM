#include <Arduino.h>
#include <Ultrasonic.h>

#define FORWARD 100
#define TURN 200
#define BACKWARD 210
#define LEFT 220
#define RIGHT 230
#define ERROR 404

const uint8_t upperTrigger 	= 0;
const uint8_t upperEcho 	= 4;
const uint8_t lowerTrigger 	= 16;
const uint8_t lowerEcho 	= 17;
const uint8_t rightTrigger 	= 5;
const uint8_t rightEcho 	= 18;

void setup()
{
	// declarar los sensores
	Ultrasonic upperSensor(upperTrigger, upperEcho);
	Ultrasonic lowerSensor(lowerTrigger, lowerEcho);
	Ultrasonic rightSensor(rightTrigger, rightEcho);
	
	// declarar los motores
	
	// declarar los pines auxiliares
	
	//inicializar el puerto serial
	Serial.begin(115200);
	
	//inicializar wifi?
	//correr la webapage de configuracion?
}

void loop()
{
	// iniciar la fsm

}