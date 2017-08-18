#include "ev3api.h"
#include "ColorSensor.h"
#include "WheelCtrl.h"

using ev3api::ColorSensor;

class pidCtrl {

  public:
	pidCtrl();
	float calcPid();
	float calcColorPid();
	float calcMotorPid();
	void setLineRL(int setRL);
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
	int diff[2];
	int diff_color[2];
	int motor_diff[2];
	float integral;
	float motor_integral;
	unsigned int target_val;
	unsigned int target_val_color = 360;
};

