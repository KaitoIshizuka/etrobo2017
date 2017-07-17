#include "pidCtrl.h"

pidCtrl::pidCtrl():
  colorSensor(PORT_2){
	LineRL = 0;//line の Right 側を走行
	diff[0]=0,diff[1]=0;
	integral = 0.0;
	target_val= 0;
}

float pidCtrl::calcPid(){
  float p,i,d;
  int8_t color_val = colorSensor.getBrightness();
  float turn;

  diff[0] = diff[1];

  if(LineRL == 0){
	diff[1] = color_val - target_val;
  }else if(LineRL == 1){
	diff[1] = target_val - color_val;
  }

  integral += (diff[0] + diff[1]) / 2.0 * delta_t;

  p = Kp * diff[1];
  i = Ki * integral;
  d = Kd * (diff[1] - diff[0]) / delta_t;

  turn = p+i+d;

  //返り値に下限-100,上限100を設定
  if(turn >= 100.0){
	turn = 100.0;
  }else if(turn <= -100.0){
	turn = -100.0;
  }

  return turn;
}
