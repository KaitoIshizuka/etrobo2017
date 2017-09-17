#ifndef INCLUDED_WHEELCONTROLL
#define INCLUDED_WHEELCONTROLL
#include "WheelCtrl.h"
#endif


using namespace ev3api;

class ItemMove{
public:
	void run();
	void place();

    
private:
    WheelCtrl wc;

    int32_t startRight = 0;
    int32_t startLeft = 0;
    float startAve = 0;

    int32_t nowRight = 0;
    int32_t nowLeft = 0;
    float nowAve = 0;

    float goal = 0;
};
