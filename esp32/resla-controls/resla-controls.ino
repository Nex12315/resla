#include "ESP32Servo.h"

Servo servo_motor;

/*
	d = left
	s = straight
	l = right
*/

void setup() {
	Serial.begin(115200);
	servo_motor.attach(4);
	Serial.println("Serial connection established");
}

void loop() {
	if (Serial.available()){
	Serial.write("hello");
	int value = Serial.read();

	if (value == 98){
		serial.write("Fuck you");
		delay(50);
		servo_motor.write(90);
		delay(50);
		servo_motor.write(90);
		}

	if (value == 108){
		servo_motor.write(30);
		}
	if (value == 100){
		servo_motor.write(130);
		}
	}
}
