#include "pidCtrl.h"

pidCtrl::pidCtrl():
  colorSensor(PORT_2),wheelCtrl(){
	LineRL = 0;//line の Right 側を走行
	diff[0]=0,diff[1]=0;
	diff_color[0]=0,diff_color[1]=0;
	integral = 0.0;
	target_val= 10;
}

float pidCtrl::calcPid(){
  float p,i,d;
  int color_val = colorSensor.getBrightness();
  float turn;

  diff[0] = diff[1];

  if(LineRL == 0){
	diff[1] = color_val - target_val;
  }else if(LineRL == 1){
	diff[1] = target_val - color_val;
  }
	diff[1] = color_val - target_val;

  integral += (diff[0] + diff[1]) / 2.0 * delta_t;

  p = Kp * diff[1];
  i = Ki * integral;
  d = Kd * (diff[1] - diff[0]) / delta_t;

  turn = p + i + d;

  //返り値に下限-100,上限100を設定
  if(turn >= 100.0){
	turn = 100.0;
  }else if(turn <= -100.0){
	turn = -100.0;
  }

  return turn;
}


float pidCtrl::calcColorPid(){
  float p,i,d;
  rgb_raw_t rgb;
  colorSensor.getRawColor(rgb);
  int color_val = rgb.r + rgb.g +rgb.b;
  float turn;

  diff_color[0] = diff_color[1];

  if(LineRL == 0){
	diff_color[1] = color_val - target_val_color;
  }else if(LineRL == 1){
	diff_color[1] = target_val_color - color_val;
  }

  integral += (diff_color[0] + diff_color[1]) / 2.0 * delta_t;

  p = Kp_color * diff_color[1];
  i = Ki_color * integral;
  d = Kd_color * (diff_color[1] - diff_color[0]) / delta_t;

  turn = p + i + d;

  //返り値に下限-100,上限100を設定
  if(turn >= 100.0){
	turn = 100.0;
  }else if(turn <= -100.0){
	turn = -100.0;
  }

  return turn;
}



void pidCtrl::setLineRL(int setRL){
  LineRL = setRL;
}


float pidCtrl::calcMotorPid(){
  float p,i,d;
  float motorR_val = (float)wheelCtrl.getCount(0);
  float motorL_val = (float)wheelCtrl.getCount(1);
  float turn;

  diff[0] = diff[1];

  //turn値+なら左に,-なら右に行く
  if(LineRL == 0){
	diff[1] = motorR_val - motorL_val;
  }else if(LineRL == 1){
	diff[1] = motorL_val - motorR_val;
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

