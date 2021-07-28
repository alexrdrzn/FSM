#include <Arduino.h>
#include <stdint.h>
#include <Ultrasonic.h>
#include <L298N.h>
#include <HardwareSerial.h>

//Definiciones para FSM
#define FORWARD 	50
#define TURN 		100
#define BACKWARD 	105
#define LEFT 		110
#define RIGHT 		115
#define ERROR 		250

uint8_t forward();
uint8_t turn();

//constantes para sensores
//Sensor frontal superior
const uint8_t upperTrigger 	= 0;
const uint8_t upperEcho 	= 4;

//Sensor frontal inferior
const uint8_t lowerTrigger 	= 16;
const uint8_t lowerEcho 	= 17;

//Sensor lateral derecho
const uint8_t rightTrigger 	= 5;
const uint8_t rightEcho 	= 18;

//Motor frontal derecho
const uint8_t frontRightMotorENA = 1;
const uint8_t frontRightMotorIN1 = 2;
const uint8_t frontRightMotorIN2 = 3;

//Motor frontal izquierdo
const uint8_t frontLeftMotorENA = 1;
const uint8_t frontLeftMotorIN1 = 2;
const uint8_t frontLeftMotorIN2 = 3;

//Motor central derecho
const uint8_t midRightMotorENA = 1;
const uint8_t midRightMotorIN1 = 2;
const uint8_t midRightMotorIN2 = 3;

//Motor central izquierdo
const uint8_t midLeftMotorENA = 1;
const uint8_t midLeftMotorIN1 = 2;
const uint8_t midLeftMotorIN2 = 3;

//Motor trasero derecho
const uint8_t backRightMotorENA = 1;
const uint8_t backRightMotorIN1 = 2;
const uint8_t backRightMotorIN2 = 3;

//Motor trasero izquierdo
const uint8_t backLeftMotorENA = 1;
const uint8_t backLeftMotorIN1 = 2;
const uint8_t backLeftMotorIN2 = 3;

//Variables para fsm
uint8_t fsmState = FORWARD;
uint8_t targetDistance = 5;


// Declaracion de sensores
Ultrasonic upperSensor(upperTrigger, upperEcho);
Ultrasonic lowerSensor(lowerTrigger, lowerEcho);
Ultrasonic rightSensor(rightTrigger, rightEcho);

// declarar los motores
L298N frontRightMotor();
L298N frontLeftMotor();
L298N midRightMotor();
L298N midLeftMotor();
L298N backRightMotor();
L298N backLeftMotor();

void setup()
{
	//inicializar el puerto serial
	Serial.begin(115200);
	// declarar los pines auxiliares
	//inicializar wifi?
	//correr la webapage de configuracion?
}

void loop()
{
	// iniciar la fsm
	Serial.println("Iniciando el programa");

	switch (fsmState)
	{
	case FORWARD:
		forward();
		break;
	case TURN:
		turn();
		break;
	default:
		break;
	}
}

uint8_t forward()
{
	uint16_t upperSensorValue = 0;
	uint16_t lowerSensorValue = 0;
	upperSensorValue = upperSensor.read();
	lowerSensorValue = lowerSensor.read();
	//Imprimir distancias
	
	//Detectar si estamos a la distancia correcta para empezar a hacer validaciones
	if (upperSensorValue <= targetDistance || lowerSensorValue <= targetDistance)
	{
		if ((upperSensorValue <= (lowerSensorValue + 1)) || (upperSensorValue >= (lowerSensorValue)))
		{
			//Avanza hacia adelante
		}
		else if (upperSensorValue )
		{
			/* code */
		}
	}
	
	
}