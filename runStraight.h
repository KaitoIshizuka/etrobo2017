#include "WheelCtrl.h"
#include "util.h"
#include "Clock.h"

class runStraight {

  public:
	runStraight();
	void setPwm(int input);
	void run(int distance);
	void term();
  private:
	int pwm = 0;
	WheelCtrl wc;
	ev3api::Clock clock;
};
