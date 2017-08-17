#include "ev3api.h"
#include "ColorSensor.h"
#include "util.h"

#include <algorithm>
#include <cstdlib>

using ev3api::ColorSensor;
using std::max;
using std::min;

class Hsv {

  public:
	Hsv();
	void Calc();
	int& getH();
	int& getS();
	int& getV();
  private:
	ColorSensor colorSensor;
    rgb_raw_t rgbRaw;
	int h,s,v;
};

