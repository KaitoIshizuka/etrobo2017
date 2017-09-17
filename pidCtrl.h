#include "ev3api.h"
#include "ColorSensor.h"
#ifndef INCLUDED_WHEELCONTROLL
#define INCLUDED_WHEELCONTROLL
#include "WheelCtrl.h"
#endif

//using ev3api::ColorSensor;
using namespace ev3api;

class pidCtrl {

  public:
	pidCtrl();
	float calcPid();
	float calcColorPid();
	float calcColorWalkPid();
	float calcMotorPid();
	void setLineRL(int setRL);
	void setCollorTarget(int target);
  private:
	int LineRL;
	ColorSensor colorSensor;
	WheelCtrl wheelCtrl;
	const float delta_t = 0.002;
	const float Kp = 0.63;
	const float Ki = 0.0;
	const float Kd = 0.0;
	const float Kp_color = 0.12;
//	const float Kp_color = 0.12;
//	const float Ki_color = 0.1;
	const float Ki_color = 0.1;
//	const float Kd_color = 0.006;
	const float Kd_color = 0.003;
//	const float Kp_color_walk = 0.14;
	const float Kp_color_walk = 0.14;
//	const float Ki_color_walk = 0.00;
	const float Ki_color_walk = 0.00;
//	const float Kd_color_walk = 0.005;
	const float Kd_color_walk = 0.000;
	int diff[2];
	int diff_color[2];
	int diff_color_walk[2];
	int motor_diff[2];
	float integral;
	float motor_integral;
	unsigned int target_val = 20;
//	unsigned int target_val_color = 360; 本番コースで調整した値
	unsigned int target_val_color = 260;
};

