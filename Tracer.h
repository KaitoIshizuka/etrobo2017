#include "Motor.h"
#include "pidCtrl.h"
#include "util.h"
#include "Clock.h"

using namespace ev3api;

class Tracer {
	public:
		Tracer();
		void run(int distance);
		void init();
		void terminate();
		float alpaca_value();
		void setPwm(int8_t setValue);

	private:
		Motor leftWheel;
		Motor rightWheel;
		pidCtrl pidctrl;
		Clock clock;
		int8_t pwm = (Motor::PWM_MAX) / 2;
};

