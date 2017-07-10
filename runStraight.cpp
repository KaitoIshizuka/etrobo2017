#include "runStraight.h"

// 
runStraight::runStraight():
  wc(),clock(){
}

void runStraight::setPwm(int input){
	pwm = input;
}

void runStraight::run(int distance){
  int32_t r_count,l_count,diff;

  init_f(__FILE__);
  while(1){//無限ループ


    wc.setPWM(pwm);

    r_count = wc.getCount(0);
    l_count = wc.getCount(1);
    diff = (r_count - l_count)*10;

    if (diff > 0) { // 正の値 右が大きい
      // 右を下げる
      wc.setPWM(pwm - diff, 0);
      msg_f("over right", 1);
    }else if(diff < 0) { //負の値 左が大きい
      // 左を下げる
      wc.setPWM(pwm + diff, 1);
      msg_f("over left", 1);
    }else{
      wc.setPWM(pwm);
      msg_f("even", 1);
    }

    if (r_count > distance) {
      break;
    }

  clock.wait(4);
  }
}

void runStraight::term(){
  wc.term();
}
