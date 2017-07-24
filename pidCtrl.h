#include "ev3api.h"
#include "ColorSensor.h"
#include "WheelCtrl.h"

using ev3api::ColorSensor;

class pidCtrl {

  public:
	pidCtrl();
	float calcPid();
	float calcMotorPid();
	void setLineRL(int setRL);
  private:
	int LineRL;
	ColorSensor colorSensor;
	WheelCtrl wheelCtrl;
	const float delta_t = 0.004;
	const float Kp = 0.63;
	const float Ki = 0.0;
	const float Kd = 0.0;
	int diff[2];
	int motor_diff[2];
	float integral;
	float motor_integral;
	unsigned int target_val;
};

