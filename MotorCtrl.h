#include "Motor.h"

using namespace ev3api;

class WheelCntl {
  public:
	Motor WheelCntl();
	void init();
	void term();
	bool getBrake(int id);
	int32_t getCount(int id);
	int getPWM(int id);
	void reset();
	void setBrake(bool status);
	void setCount(int32_t count, int id);
	void setCount(int32_t count);
	void setPWM(int pwm, int id);
	void setPWM(int pwm);
	void stop(int id);
	void stop();
  private:
	const int PWM_MAX = 100;
	const int PWM_MIN = -100;
};
