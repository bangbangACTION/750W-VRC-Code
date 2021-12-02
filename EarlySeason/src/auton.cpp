#include "main.h"
#include "config.h"
using namespace okapi;
void auton(){
  chassis->setMaxVelocity(60);
  while(!intakeLimitSwitch.isPressed()){
    moveDistance(60, 25);
  }
  moveDistance(0, 25);
  frontIntakeClampDown();
  moveDistance(-60, 25);
  chassis->setMaxVelocity(200);

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
}
void frontIntakeUp(){
  intake.moveVoltage(10000);
  delay(75); //experiment with this value
}
void frontIntakeClampDown(){
  intake.moveVoltage(-10000);
  delay(1000); //experiment with this value
}

void liftMoveUp(){
  lift.moveVelocity(100);
  delay(30); //experiment with this value
}
void liftMoveDown(){
  lift.moveVelocity(-100);
  delay(30); //experiment with this value
}
void stop(){
  fL.moveVelocity(0);
  fR.moveVelocity(0);
  bL.moveVelocity(0);
  bR.moveVelocity(0);
  lift.moveVelocity(0);
  intake.moveVoltage(0);
}

void turn_cw(int time){
  fL.moveVelocity(100);
  fR.moveVelocity(0);
  bL.moveVelocity(100);
  bR.moveVelocity(100);
  delay(time);
  stop();
}
void turn_ccw(int time){
  fL.moveVelocity(0);
  fR.moveVelocity(100);
  bL.moveVelocity(100);
  bR.moveVelocity(100);
  delay(time);
  stop();
}

void motionPID(float dist){
  float error, integral, prevError, derivative = 0;
  float power = 100;
  while((int)pot.controllerGet() != (int)dist){
    error = dist - pot.controllerGet();
    integral += error;
    if(error == 0 || (int)pot.controllerGet() == (int)dist){
      integral = 0;
    }
    if(pot.controllerGet() > 10){ //if error is outside of useful range
      integral = 0;
    }
    derivative = integral - prevError;
    prevError = error;
    power = error*kP + integral*kI + derivative*kD;
    delay(15);
    moveDistance(power, 15);
  }
}
