#include "Tracer.h"

Tracer::Tracer():
leftWheel(PORT_C),
rightWheel(PORT_B),
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
  static int run = (rightWheel.getCount() + leftWheel.getCount())/2;
  while(1){ 
	run = (rightWheel.getCount() + leftWheel.getCount())/2;
	float turn = pidctrl.calcPid();
	
	int pwm_l = pwm - turn;
	int pwm_R = pwm + turn;

	leftWheel.setPWM(pwm_l);
	rightWheel.setPWM(pwm_R);

	if(distance <= run){//走行距離run が 設定距離distance より小さい間
	  break;
	}

	clock.wait(4);
  }
}
