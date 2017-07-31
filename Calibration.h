#include "ev3api.h"
#include "ColorSensor.h"
#include "util.h"

using ev3api::ColorSensor;

class Calibration {

  public:
	Calibration();
	int8_t run();
  private:
	ColorSensor colorSensor;
};

