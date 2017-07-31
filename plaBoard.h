#include "SonarSensor.h"
#include "util.h"

using namespace ev3api;

class plaBoard {
	public:
		plaBoard();
		void init();
		void search();



	private:
		SonarSensor sonarSensor;
		int16_t plaDistance = sonarSensor.getDistance();

};