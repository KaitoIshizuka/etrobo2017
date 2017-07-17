#include "ev3api.h"
#include "ColorSensor.h"

using ev3api::ColorSensor;

class pidCtrl {

  public:
	pidCtrl();
	float calcPid();
	void setLineRL();
  private:
	int LineRL;
	ColorSensor colorSensor;
	const float delta_t = 0.004;
	const float Kp = 0.8;
	const float Ki = 0.0;
	const float Kd = 0.0;
	int diff[2];
	float integral;
	unsigned int target_val;
};

