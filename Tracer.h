#include "Motor.h"
#include "ColorSensor.h"
#include "util.h"

using namespace ev3api;

class Tracer {
	public:
		Tracer();
		void run();
		void init();
		void terminate();
		float　alpaca_value();

	private:
		Motor leftWheel;
		MOtor rightWheel;
		ColorSensor colorSensor;
		const int8_t pwm = (Motor::PWM_MAX) / 2;
}

