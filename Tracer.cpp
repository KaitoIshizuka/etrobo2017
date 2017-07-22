#include "Tracer.h"

Tracer::Tracer():
leftWheel(PORT_C),
rightWheel(PORT_B),
colorSensor(PORT_3),
pidctrl(),
clock(){
}

void Tracer::init(){
	init_f("Tracer");
}

void Tracer::terminate(){
	leftWheel.stop();
	rightWheel.stop();
}

void Tracer::setPwm(int8_t setValue) {
	pwm = setValue;
}

void Tracer::run(int distance){
  static int run = rightWheel.getCount() + leftWheel.getCount();
  while(distance >= run){ //走行距離run が 設定距離distance より小さい間
	run = rightWheel.getCount() + leftWheel.getCount();
	float turn = pidctrl.calcPid();
	
	int pwm_l = pwm - turn;
	int pwm_R = pwm + turn;

	leftWheel.setPWM(pwm_l);
	rightWheel.setPWM(pwm_R);

	clock.wait(4);
  }
}
