#include "plaBord.h"

plaBord::plaBord():
	SonerSensor(Port_3),
	clock(){}

void plaBord::init(){
	init_f("plaBord");
}

void plaBord::serch(){
	plaDistance = sonerSensor.getDistance();

	msg_f("plaDistance = ",plaDistance);
}