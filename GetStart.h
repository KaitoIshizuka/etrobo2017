#include "TouchSensor.h"
#include "Clock.h"

using ev3api::TouchSensor;
using ev3api::Clock;

class GetStart{
  public:
	GetStart();
	void run();
  private:
	TouchSensor touchSensor;
	Clock clock;
};

