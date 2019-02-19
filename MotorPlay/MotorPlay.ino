#include <AFMotor.h>
 
AF_DCMotor l_motor(1, MOTOR12_1KHZ); // create motor #2, 64KHz pwm
AF_DCMotor r_motor(2, MOTOR12_1KHZ);

void mov(AF_DCMotor l_motor, AF_DCMotor r_motor, uint8_t dir){
    l_motor.run(dir);
    r_motor.run(dir);
}

//void turn(AF_DCMotor l_motor, AF_DCMotor r_motor, uint8_t dir)

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");
  
  l_motor.setSpeed(255);     // set the speed to 200/255
  r_motor.setSpeed(255);
}
 
void loop() {
  Serial.print("tick");
  
  l_motor.run(FORWARD);      // turn it on going forward
  r_motor.run(FORWARD);
  delay(1000);
 
  /*Serial.print("tock");
  l_motor.run(BACKWARD);     // the other way
  r_motor.run(BACKWARD);
  delay(1000);*/
  
  Serial.print("tack");
  l_motor.run(RELEASE);      // stopped
  r_motor.run(RELEASE);
  delay(1000);
}
