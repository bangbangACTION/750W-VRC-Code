#include "main.h"
#include "config.h"
void move_dist(float spd, int time){
  drive_fL.moveVelocity(spd);
  drive_fR.moveVelocity(spd);
  drive_bL.moveVelocity(spd);
  drive_bR.moveVelocity(spd);
  delay(time);
}
void front_clamp(){
  front_intake.moveVoltage(8000);
  delay(75); //experiment with this value TEST
}
void front_unclamp(){
  front_intake.moveVoltage(-8000);
  delay(50); //experiment with this value
}
void back_clamp(){
  back_intake.moveVoltage(8000);
  delay(75);
}
void back_unclamp(){
  back_intake.moveVoltage(-8000);
  delay(50);
}
void lift_up(){
  lift.moveVelocity(75);
  delay(30); //experiment with this value
}
void lift_down(){
  lift.moveVelocity(-100);
  delay(30); //experiment with this value
}
void stop(){
  drive_fL.moveVelocity(0);
  drive_fR.moveVelocity(0);
  drive_bL.moveVelocity(0);
  drive_bR.moveVelocity(0);
  lift.moveVelocity(0);
  front_intake.moveVoltage(0);
  back_intake.moveVoltage(0);
}

void turn_cw (float spd, int time){
  drive_fL.moveVelocity(spd);
  drive_fR.moveVelocity(0);
  drive_bL.moveVelocity(spd);
  drive_bR.moveVelocity(spd);
  delay(time);
  stop();
}
void turn_ccw (float spd, int time){
  drive_fL.moveVelocity(0);
  drive_fR.moveVelocity(spd);
  drive_bL.moveVelocity(0);
  drive_bR.moveVelocity(spd);
  delay(time);
  stop();
}

void drive_PID(float dist){
  const float kP = 0;
  const float kI = 0;
  const float kD = 0;
  
  double error, prev_error, derivative, total_error, integral, motor_power;
  double drive_fL_pos = drive_fL.getPosition();
  double drive_fR_pos = drive_fR.getPosition();
  double drive_bL_pos = drive_bL.getPosition();
  double drive_bR_pos = drive_bR.getPosition();

  double avg_pos = (drive_fL_pos + drive_fR_pos + drive_bL_pos + drive_bR_pos)/4.0;

  double desired_val = 200; //degrees, convert distance needed to travel to degrees
  error = avg_pos - desired_val;
  derivative = error - prev_error;
  tot_error += error;

  motor_power = error*kP + derivate*kD + total_error*kI;
  move_dist(motor_power, 25);

  prev_error = error;
  delay(20);
}
/*
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
*/
