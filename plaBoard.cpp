#include "plaBoard.h"

plaBoard::plaBoard():
sonarSensor(PORT_3){
}


void plaBoard::init(){
	init_f("plaBoard");
}

void plaBoard::search(){
	int16_t plaDistance = sonarSensor.getDistance();

	msg_f(plaDistance,1);
}

