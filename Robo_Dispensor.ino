#include <TimeLib.h>

/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#define Button 2

int amount;

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void medicine(){
  myservo.write(0);
  delay(1000);
  myservo.write(179);
  delay(1000);
}

void setup() {
  Serial.begin(9600);
  
  myservo.attach(9); // attaches the servo on pin 9 to the servo object

  pinMode(Button, INPUT_PULLUP);


}


  

void loop() {
    
  Serial.println("What time do you take your first medication?");
  while (Serial.available() == 0) {
  
  }
  String temp = Serial.readString();
  temp.replace("\n", "");
  temp.replace("\r", "");
  int test_level_PM = temp.toInt();
  Serial.print("Time: ");
  Serial.println(test_level_PM);
  
  Serial.flush(); 
  
  Serial.println("How many pills do you need to take?");
  while (Serial.available() == 0){
  
  }
  amount = Serial.parseInt();
  Serial.print("Quantity: ");
  Serial.println(amount);
  
 

  Serial.println("Monitoring button: ");
  while (digitalRead(Button) == HIGH){}
   for (int i=0; i < amount; i++) {
    medicine();
    Serial.print(i);
  Serial.println("Button Pressed");
}
}
