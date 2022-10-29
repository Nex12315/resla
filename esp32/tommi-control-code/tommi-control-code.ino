#include "BluetoothSerial.h"
#include <ESP32Servo.h>
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run 'make menuconfig' to and enable it
#endif
BluetoothSerial SerialBT;

// DIRECTION
// d = left
// s = straight
// l = right

// MOVEMENT
// b = forward
// a = stop!!!
// c = fast backward
// f = slow backward

Servo servo_motor;
Servo esc_motor;

// int values = 90;

void setup() {
 // Open serial communications and wait for port to open:
 Serial.begin(115200);
 servo_motor.attach(4);
 esc_motor.attach(5);
 //while (!Serial) {
 //; // wait for serial port to connect. Needed for native USB port only
// }

// Serial.println("Starting ESP32");
 //bluetooth settings:
 //Serial.begin(115200);
 SerialBT.begin("RESLA"); //Bluetooth device name
 Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
 if (Serial.available()) {
 SerialBT.write(Serial.read());
 }
 // read data from bluetooth
 if (SerialBT.available()) {
 int value = SerialBT.read();
 SerialBT.println(value);

 if ( value == 115 )  // s
 {
 servo_motor.write(90);
 }
 
 if ( value == 108 )  // l
 {
 // Vasen
 servo_motor.write(30);
 }
 
 if ( value == 100 )  // d
 {
 servo_motor.write(130);
 }
 
 if ( value == 102 )  // f
 {
 // Neutral!
 esc_motor.write(90);
 delay( 10 );
 esc_motor.write(85);
 // Neutral!
 /*
 delay( 1500 );
 esc_motor.write(90);
 */
 }

 if (value == 97) // a
 {
  delay(50);
  esc_motor.write(90);
 }

 if (value == 99) // c
 {
  delay(50);
  esc_motor.write(90);
  
  delay(50);
  esc_motor.write(80);
 }

 if (value == 101)
 {
  delay(50);
  esc_motor.write(90);
  
  delay(50);
  esc_motor.write(95);
 }
 
 if ( value == 98 ) // b
 {

 // Tommy's version
 
 // Neutral!
 /*
 delay( 50 );
 esc_motor.write(90);


 // Kytke reverse
 delay( 50 );
 esc_motor.write(80);
 */
 
 // Neutral!
 delay( 50 );
 esc_motor.write(90);

 // Pakita
 delay( 50 );
 esc_motor.write(100);
 // Neutral!
 /*
 delay( 1500 );
 esc_motor.write(90);
 */
 }
 }

 // My version
 /*
 // Pakita
 delay( 50 );
 esc_motor.write(100);
 // Neutral!
 delay( 1500 );
 esc_motor.write(90);
 */
 // 85 - slow forword
 // 95 - slow backword
 // 90 - no moving
 
 
 // Read data in serial coming from pin
 //if (Serial.available()) {
 // mySerial.write(Serial.read());
 //}
}
