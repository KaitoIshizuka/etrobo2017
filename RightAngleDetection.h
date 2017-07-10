#include "Motor.h"
#include "ColorSensor.h"
#include "Clock.h"
#include "util.h"

using namespace ev3api;

class RightAngleDetection {
public:
  RightAngleDetection();
  void run();
  void detectionRun();
  void detectionIf1(int diff);
  void detectionIf2(int diff);
  void detectionIf3(int diff);
  void init();
  void terminate();
  float calc_prop_value();

 private:
  Motor leftWheel;
  Motor rightWheel;
  ColorSensor colorSensor;
  Clock       clock;
  uint32_t max_time = 0;
  int8_t min_bri = 100;
  const int8_t mThreshold = 20;
  const int8_t pwm = (Motor::PWM_MAX) / 10;
  bool first = true;
  bool move = true;
  // const int8_t pwm = (Motor::PWM_MAX) / 6;
 };
