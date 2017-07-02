#include "ev3api.h"
#include "Motor.h"

using ev3api::Motor;

class WheelCtrl {
  public:
	WheelCtrl();
	void init();
	void term();
	int32_t getCount(int id);
	void reset();
	void setBrake(bool status);
	void setCount(int32_t count, int id);
	void setCount(int32_t count);
	void setPWM(int pwm, int id);
	void setPWM(int pwm);
	void stop(int id);
	void stop();
  private:
	Motor leftWheel,rightWheel;
	const int PWM_MAX = 100;
	const int PWM_MIN = -100;
};
