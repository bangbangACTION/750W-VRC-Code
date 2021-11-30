#include "main.h"
#include "config.h"
void auton(){
  moveDistance(200, 100);
  turn_cw(40);
  delay(40);
  fL.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
  fR.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
  bL.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
  bR.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
  intake.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
}
void auton_selector(){

}
void moveDistance(float spd, int time){
  fL.moveVelocity(spd);
  fR.moveVelocity(spd);
  bL.moveVelocity(spd);
  bR.moveVelocity(spd);
  delay(time);
}
void frontIntakeUp(){
  intake.moveVoltage(10000);
  delay(75); //experiment with this value
}
void frontIntakeClampDown(){
  intake.moveVoltage(10000);
  delay(30); //experiment with this value
}

void liftMoveUp(){
  lift.moveVelocity(100);
  delay(30); //experiment with this value
}
void liftMoveDown(){
  lift.moveVelocity(-100);
  delay(30); //experiment with this value
} 

void turn_cw(int time){
  fL.moveVelocity(200);
  fR.moveVelocity(0);
  bL.moveVelocity(200);
  bR.moveVelocity(200);
  delay(time);
}
void turn_ccw(int time){
  fL.moveVelocity(0);
  fR.moveVelocity(200);
  bL.moveVelocity(200);
  bR.moveVelocity(200);
  delay(time);
}

void motionPID(float dist){
  float error, integral, prevError, derivative = 0;
  float power = 150;
  while((int)pot.controllerGet() != (int)dist){ 
    error = dist - pot.controllerGet();
    integral += error;
    if(error == 0 || (int)pot.controllerGet() == (int)dist){
      integral = 0;
    }
    if(pot.controllerGet() > 10){ 
      integral = 0;
    }
    derivative = integral - prevError;
    prevError = error;
    power = error*kP + integral*kI + derivative*kD;
    delay(15);
    moveDistance(power, 10);
  }
}
