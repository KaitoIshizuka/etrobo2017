#include "ColorSensor.h"
#include "TouchSensor.h"
#include "util.h"
#include "Clock.h"

using ev3api::ColorSensor;
using ev3api::TouchSensor;
using ev3api::Clock;

class Calibration {
  public:
	Calibration();
	int8_t getBrightness();
	int8_t getColor();
  private:
	ColorSensor colorSensor;
	TouchSensor touchSensor;
	Clock clock;
};

