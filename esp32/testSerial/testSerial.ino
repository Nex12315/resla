#include <Servo.h>

String nom = "ESP32";
String msg;
Servo steering;
Servo motor;
int brakeLight = 21;
int forwardLight = 18;
int headLights = 15;

void setup() {
	Serial.begin(921600);
	steering.attach(4);
	motor.attach(5);
	pinMode(brakeLight, OUTPUT);
	pinMode(forwardLight, OUTPUT);
	pinMode(headLights, OUTPUT);
}

void loop() {
	readSerialPort();

	if (msg != ""){
		if (msg == "left"){
			steering.write(130);
		}

		if (msg == "right"){
		
			steering.write(30);
		}

		if (msg == "straight"){
			steering.write(90);
		}

		if (msg == "forward"){
			motor.write(95);
			delay(50);
			motor.write(100);
			digitalWrite(forwardLight, HIGH);
			digitalWrite(headLights, HIGH);
		}

		if (msg == "backward"){
		motor.write(95);
		delay(50);
		motor.write(89);
		digitalWrite(brakeLight, HIGH);
		}

		if (msg == "stop"){
		// motor.write(90);
		// delay(150);
		motor.write(95);
		digitalWrite(brakeLight, LOW);
		digitalWrite(forwardLight, LOW);
		digitalWrite(headLights, LOW);
		}

	sendData();
	}
}

void readSerialPort(){
	msg = "";
	if (Serial.available()){
	delay(10);
	while (Serial.available() > 0){
		msg += (char)Serial.read();
		}
	Serial.flush();
	}	
}

void sendData(){
	Serial.print(nom);
	Serial.print(" received: ");
	Serial.print(msg);
}
