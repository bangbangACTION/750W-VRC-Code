#define CONFIG_H
#include "main.h"

const int FRONT_LEFT_MOTOR = 4;
const int FRONT_RIGHT_MOTOR = 7;
const int BACK_LEFT_MOTOR = 13;
const int BACK_RIGHT_MOTOR = 20;
const int FRONT_INTAKE_MOTOR = 5;
const int LIFT_MOTOR = 1;
const int BACK_INTAKE_MOTOR = 15;

const float kP = 0;
const float kI = 0;
const float kD = 0;

extern okapi::Motor drive_fL;
extern okapi::Motor drive_fR;
extern okapi::Motor drive_bL;
extern okapi::Motor drive_bR;
extern okapi::Motor front_intake;
extern okapi::Motor back_intake;
extern okapi::Motor lift;
extern std::shared_ptr<okapi::ChassisController> chassis;

extern okapi::Controller joystick;
extern okapi::ControllerButton backTakeIn;
extern okapi::ControllerButton backTakeOut;
extern okapi::ControllerButton frontTakeIn;
extern okapi::ControllerButton frontTakeOut;
extern okapi::ControllerButton liftUp;
extern okapi::ControllerButton liftDown;

extern okapi::ADIButton back_bumperswitch;
extern okapi::ADIGyro gyro;

int auton_selector();
void mbl_goal();
void left_win_point();
void right_win_point();
void new_auton_trial();
void move_dist(float spd, int time);
void front_clamp();
void back_clamp();
void front_unclamp();
void back_unclamp();
void lift_up();
void lift_down();
void turn_ccw(float spd, int time);
void turn_cw(float spd, int time);
void move_dist_pid(float dist);
void stop();
