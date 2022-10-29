#include <ESP32Servo.h>
#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

// d s l b <- Controls

Servo servo_motor;
Servo esc_motor;

int values = 90;
int motorValue = 90;



void setup() {
 // Open serial communications and wait for port to open:
 Serial.begin(115200);
 //while (!Serial) {
 //; // wait for serial port to connect. Needed for native USB port only
// }
Serial.println("Starting ESP32");
  servo_motor.attach(4);
  esc_motor.attach(5);
 //bluetooth settings:
 //Serial.begin(115200);
 SerialBT.begin("sanderesp32"); //Bluetooth device name
 Serial.println("The device started, now you can pair it with bluetooth!");
}

void goForwards(Servo servo, int speed){
  delay(50);
  servo.write(90);
  delay(100);
  for (int i = 0; i <= 10; i++){
    delay(50);
    servo.write(speed + 5);
    }
  }

void stopGoing(Servo servo){
  delay(50);
  servo.write(90);
  }

void loop() {
  bool zooming = false;
 if (Serial.available()) {
 SerialBT.write(Serial.read());
 }
 // read data from bluetooth
 if (SerialBT.available()) {
 int value = SerialBT.read();
 SerialBT.println(value);

 if ( value == 115 ) // s straight
 {
 servo_motor.write(90);
 }
 if ( value == 108 ) // L right
 {
 // Left
 servo_motor.write(30);
 }
 if ( value == 100 ) // d left
 {
 servo_motor.write(130);
 }
 if ( value == 102 ) // f reverse
 {
// Neutral!
 esc_motor.write(90);
 delay( 10 );
 esc_motor.write(85);
 // Neutral!
 delay( 1500 );
 esc_motor.write(90);

 }
if (value == 120) { // X to stop
  zooming = false;
  stopGoing(esc_motor);
  }
 
 if ( value == 119 ) // forwards, W
 {
  zooming = true;
  while (zooming){
  goForwards(esc_motor, 100);
  }
 // Neutral!
 /*
 delay( 50 );
 esc_motor.write(90);
 delay(1500);
 esc_motor.write(100);

 // Enable reverse
 delay( 50 );
 esc_motor.write(95);

 // Neutral!
 delay( 50 );
 esc_motor.write(90);

 // Reverse
 delay( 50 );
 esc_motor.write(100);
 // Neutral!
 delay( 1500 );
 esc_motor.write(90);
 }
 */
 }
 // Read data coming from pin with serial
 //if (Serial.available()) {
// mySerial.write(Serial.read());
 //}
}
}
