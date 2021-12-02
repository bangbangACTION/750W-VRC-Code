#include "main.h"
#include "config.h"
using namespace okapi;

void initialize() {
  intake.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
  lift.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
  intake.tarePosition();
  lift.tarePosition();
}

void autonomous() {
  auton_selector();
  auton();
  stop();
}

void opcontrol() {
  while(true){
    chassis->getModel()->arcade(
      joystick.getAnalog(ControllerAnalog::leftY),
      joystick.getAnalog(ControllerAnalog::rightX)
    );

    if(intakeLimitSwitch.isPressed()){
      intake.moveVoltage(0);
    }
    else{
      if(takeIn.isPressed()){
        frontIntakeClampDown();
      }
      else if(takeOut.isPressed()){
        frontIntakeUp();
      }
      else{
        intake.moveVoltage(0);
      }
    }

    if(liftLimitSwitch.isPressed()){
      lift.moveVelocity(0);
    }
    //else if(pot.controllerGet() > a certain value){
    //  lift.moveVelocity(0);
    //}
    else{
      if(liftUp.isPressed()){
        liftMoveUp();
      }
      else if(liftDown.isPressed()){
        liftMoveDown();
      }
      else{
        lift.moveVelocity(0);
      }
    }


    delay(10);
  }
}
