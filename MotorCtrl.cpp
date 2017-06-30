#include "WheelCntl.h"

using namespace ev3api;

// コンストラクタ
// ここでright,left モータのインスタンス作成
WheelCntl::WheelCntl(){
  leftWheel(PORT_C),rightWheel(PORT_B)
}

// 初期化するものがあればここで
void WheelCntl::init(){

}

// プログラム終了時に実行
// 倒れる時とか。そんな時にモーターを止める用の
void WheelCntl::term(){
  msg_f("MotorCntl is termineted",1);
  leftWheel.stop();
  rightWheel.stop();
}

// ブレーキ種を取得する関数
bool getBrake(int id){
  if(id == "0"){
	return rightWheel.getBrake();
  }else if(id == "1"){
	return leftWheel.getBrake();
  }
  return -1; // 異常終了
}

// モータの走った距離を回転角度(度)で返す
int32_t getCount(int id){
  if(id == "0"){
	return rightWheel.getCount();
  }else if(id == "1"){
	return leftWheel.getCount();
  }
  return -1; // 異常終了
}

// 現在セットされているモータのPWMを取得する
int getPWM(int id){
  if(id == "0"){
	return rightWheel.getPWM();
  }else if(id == "1"){
	return leftWheel.getPWM();
  }
  return -1; // 異常終了
}

// 左右モーター停止、および角位置の0リセット,オフセット初期化
void reset(){
  rightWheel.reset();
  leftWheel.reset();
}

// ブレーキモードの変更
void setBrake(bool status){
  rightWheel.setBrake(status);
  leftWheel.setBrake(status);
}

// setCount モーター別にセットする関数
void setCount(int32_t count, int id){
  if(id == "0"){
	rightWheel.setCount(count);
  }else if(id == "1"){
	leftWheel.setCount(count);
  }
}

// setCount 一括セット
void setCount(int32_t count){
  rightWheel.setCount(count);
  leftWheel.setCount(count);
}

// モータを動かす強さを設定。モータ別セット
void setPWM(int pwm, int id){
   if(id == "0"){
	rightWheel.setPWM(pwm);
  }else if(id == "1"){
	leftWheel.setPWM(pwm);
  }
}


// モータを動かす強さを設定。一括セット
void setPWM(int pwm){
  rightWheel.setPWM(pwm);
  leftWheel.setPWM(pwm);
}


// モーターをストップ。モーター別
void stop(int id){
   if(id == "0"){
	rightWheel.stop();
  }else if(id == "1"){
	leftWheel.stop();
  }
}

// モーターをストップ。一括
void stop(){
  rightWheel.stop();
  leftWheel.stop();
}
