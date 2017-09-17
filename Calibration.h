#include "ColorSensor.h"
#include "TouchSensor.h"
#include "util.h"
#include "Clock.h"

using namespace ev3api;

class Calibration {
  public:
	Calibration();
	int8_t getBrightness();
	int getColor();
	int ColorCalibration();
  private:
	ColorSensor colorSensor;
	TouchSensor touchSensor;
	Clock clock;
};

