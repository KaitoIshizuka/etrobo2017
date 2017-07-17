#include "Tracer.h"

Tracer::Tracer():
leftWheel(PORT_C),
rightWheel(PORT_B),
colorSensor(PORT_3){
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

void Tracer::run(){
	float turn = alpaca_value();
	
	int pwm_l = pwm - turn;
	int pwm_R = pwm + turn;

	leftWheel.setPwm(pwm_l);
	rightWheel.setPwm(pwm_R);
}