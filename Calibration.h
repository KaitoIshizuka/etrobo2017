#include "ev3api.h"
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
	int8_t run();
  private:
	ColorSensor colorSensor;
	TouchSensor touchSensor;
	Clock clock;
};

