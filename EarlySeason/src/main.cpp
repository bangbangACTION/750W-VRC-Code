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
        intake.moveVoltage(-10000);
      }
      else if(takeOut.isPressed()){
        intake.moveVoltage(10000);
      }
      else{
        intake.moveVoltage(0);
      }
    }

    if(liftLimitSwitch.isPressed()){
      lift.moveVelocity(0);
    }
    else{
      if(liftUp.isPressed()){
        lift.moveVelocity(100);
      }
      else if(liftDown.isPressed()){
        lift.moveVelocity(-100);
      }
      else{
        lift.moveVelocity(0);
      }
    }

    delay(10);
  }
}
