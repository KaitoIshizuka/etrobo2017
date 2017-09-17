#include "Hsv.h"

Hsv::Hsv():
  colorSensor(PORT_2){
  rgbRaw.r=0;
  rgbRaw.g=0;
  rgbRaw.b=0;
  init_f("Hsv");
}

void Hsv::Calc(){
  //カラーセンサで色値を取得
  colorSensor.getRawColor(rgbRaw);

  //max min を取得
  int max = std::max(std::max(rgbRaw.r, rgbRaw.g), rgbRaw.b);
  int min = std::min(std::min(rgbRaw.r, rgbRaw.g), rgbRaw.b);

  // hue の計算
  if (max == min) {
    h = 0; // 本来は定義されないが、仮に0を代入
  } else if (max == rgbRaw.r) {
    h = 60 * (rgbRaw.b - rgbRaw.g) / (max - min) + 180;
  } else if (max == rgbRaw.g) {
    h = (60 * (rgbRaw.r - rgbRaw.b) / (max - min)) + 300;
  } else if (max == rgbRaw.b){
    h = (60 * (rgbRaw.g - rgbRaw.r) / (max - min)) + 60;
  }

  //hの絶対値を取る
  h = abs(h);

  //hを360の剰余にする 
  h %= 360;

  //saturation の計算
  s = max - min;

  // value の計算
  v = max;
}

//getter関数
//変数のアドレス(例: 変数aなら &a)を受け取り,持っているhsv変数でアドレスを辿って変更
void Hsv::getH(int& in){in =  h;}
void Hsv::getS(int& in){in =  s;}
void Hsv::getV(int& in){in =  v;}

