#include "SonarSensor.h"
#include "util.h"

using namespace ev3api;

class plaBord {
	public:
		plaBord();
		void init();
		void search();


	private:
		SonerSensor sonerSensor;
		int16_t plaDistance = sonerSensor.getDistance();

};