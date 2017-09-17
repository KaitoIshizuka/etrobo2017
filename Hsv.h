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
	void getH(int& in);
	void getS(int& in);
	void getV(int& in);
  private:
	ColorSensor colorSensor;
    rgb_raw_t rgbRaw;
	int h,s,v;
};

