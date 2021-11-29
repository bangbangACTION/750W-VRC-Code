#include "main.h"
#include "config.h"
#define FRONT_LEFT_MOTOR 4
#define FRONT_RIGHT_MOTOR 7
#define BACK_LEFT_MOTOR 17
#define BACK_RIGHT_MOTOR 14
#define FRONT_INTAKE_MOTOR 5
#define LEFT_LIFT_MOTOR 11
#define RIGHT_LIFT_MOTOR 20

using namespace okapi;

okapi::Motor fL(FRONT_LEFT_MOTOR, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
okapi::Motor fR(FRONT_RIGHT_MOTOR, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
okapi::Motor bL(BACK_LEFT_MOTOR, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
okapi::Motor bR(BACK_RIGHT_MOTOR, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
okapi::Motor intake(FRONT_INTAKE_MOTOR, true, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees);
okapi::Motor liftL(LEFT_LIFT_MOTOR, true, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees);
okapi::Motor liftR(RIGHT_LIFT_MOTOR, false, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees);
std::shared_ptr<okapi::ChassisController> chassis = ChassisControllerBuilder()
    .withMotors(
        {fL, bL},
        {fR, bR}
    ).withDimensions(
        AbstractMotor::gearset::green,
        {
            {4.0_in, 6.5_in},
            static_cast<int32_t>(imev5GreenTPR)
        }
    ).build();

okapi::Controller joystick;
okapi::ControllerButton takeIn(ControllerDigital::L1);
okapi::ControllerButton takeOut(ControllerDigital::R1);
okapi::ControllerButton liftUp(ControllerDigital::up);
okapi::ControllerButton liftDown(ControllerDigital::down);

okapi::MotorGroup lift({liftL, liftR});
okapi::Potentiometer Potentiometer('B');
okapi::ADIButton intakeLimitSwitch('A');
okapi::ADIButton liftLimitSwitch('C');

/*
void pid(double dist){
  double kP = 1;
  double error = 0;
  double power = 0;
  double integral = 0;
  while(){
    error = dist - ultra.get();
    integral = integral + error;
    if(error == 0 || dist == integral) //2nd condition - passes setpoint
    integral = 0;
    //if power is outside useful range
    //integral = 0;
    power = error*kP + integral*kI;
    delay(15);
  }
}
*/
