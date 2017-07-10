#include "util.h"

#include "ArmMove.h"

ArmMove::ArmMove():
armMoter(PORT_A){
}

ArmMove::ArmMove(int t):
duration(t), armMoter(PORT_A){
}

void ArmMove::run(int pam) {
    init_f(__FILE__);
        while(1) {
    msg_f("Upping...", 1);
    armMoter.setPWM(pam);
    clock.sleep(duration);
    armMoter.stop();
    ext_tsk();
        }
}
