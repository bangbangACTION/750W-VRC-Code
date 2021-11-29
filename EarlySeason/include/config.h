#define CONFIG_H
#include "main.h"

const int FRONT_LEFT_MOTOR = 4;
const int FRONT_RIGHT_MOTOR = 7;
const int BACK_LEFT_MOTOR = 17;
const int BACK_RIGHT_MOTOR = 14;
const int FRONT_INTAKE_MOTOR = 5;
const int LEFT_LIFT_MOTOR = 11;
const int RIGHT_LIFT_MOTOR = 20;

extern okapi::Motor fL;
extern okapi::Motor fR;
extern okapi::Motor bL;
extern okapi::Motor bR;
extern okapi::Motor intake;
extern okapi::Motor liftL;
extern okapi::Motor liftR;
extern std::shared_ptr<okapi::ChassisController> chassis;

extern okapi::Controller joystick;
extern okapi::ControllerButton takeIn;
extern okapi::ControllerButton takeOut;
extern okapi::ControllerButton liftUp;
extern okapi::ControllerButton liftDown;

extern okapi::MotorGroup lift;
extern okapi::Potentiometer pot;
extern okapi::ADIButton intakeLimitSwitch;
extern okapi::ADIButton liftLimitSwitch;

void auton();
void auton_selector();
void moveDistance(float spd, int time);
void frontIntakeClampDown();
void frontIntakeUp();
void liftMoveUp();
void liftMoveDown();
