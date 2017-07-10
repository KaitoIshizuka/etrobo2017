#include "Motor.h"
#include "Clock.h"

using namespace ev3api;

class ArmMove{
public:
    ArmMove();
    ArmMove(int t);
    void run(int t);
    void stop();
    int pam;
    
private:
    Motor armMoter;
    Clock clock;
    
    const uint32_t duration = 1000;
};
