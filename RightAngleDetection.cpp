#include "RightAngleDetection.h"

RightAngleDetection::RightAngleDetection():
  leftWheel(PORT_C), rightWheel(PORT_B),
  colorSensor(PORT_2) {
}

void RightAngleDetection::init() {
  init_f("RightAngleDetection");
}

void RightAngleDetection::terminate() {
  //msg_f("Stopped.", 1);
  leftWheel.stop();
  rightWheel.stop();
}

float RightAngleDetection::calc_prop_value() {
  //const float Kp = 0.83;        // <1>
  // const float Kp = 0.05;        // <1>
  // const int target = 30;        // <2>
  // const int bias = 0;

  float Kp = 0.08;        // <1>
  int target = 45;        // <2>
  int bias = 0;

  //int diff = colorSensor.getBrightness()-target; // <3>元のやつ

  int diff = colorSensor.getBrightness(); // <3>書き換え
  if(diff < target){
    Kp = Kp + (target-diff)/60;
  }
  diff=diff-target;//ここまで書き換え
  return (Kp * diff + bias);                       // <4>
}

void RightAngleDetection::run() {
  float turn = calc_prop_value(); // <5>
  int pwm_l = pwm + turn;      // <6>
  int pwm_r = pwm - turn;      // <6>
  leftWheel.setPWM(pwm_l);
  rightWheel.setPWM(pwm_r);
}
void RightAngleDetection::detectionRun() {
  //光の強さを取る
  int diff = colorSensor.getBrightness();
  //光の強さの加減を調べる
  if(diff<min_bri){
        min_bri = diff;
        //msg_f(min_bri,5);
  }
  if(first){
    clock.reset();
    first = false;
  }
  //暗さが一定より低かったら
  detectionIf2(diff);
  
}
void RightAngleDetection::detectionIf1(int diff) {
  if(move){
    if(diff<5){
      //暗い状態（線の上いる時）が1000msを超えたら止める
      if(clock.now()>100){
        // if(clock.now()>3000){
        //msg_f("stop:angle", 1);
        //msg_f(diff, 2);
        // leftWheel.setPWM(-pwm);
        // rightWheel.setPWM(-pwm);
        // clock.sleep(50);
        leftWheel.stop();
        rightWheel.stop();
        move = false;
      }else{
        //1秒なるまではそのまま走る，
        //線上時間の最大時間を計測
        if(clock.now()>max_time){
          max_time = clock.now();
          //msg_f(max_time,4);
        }
        //msg_f("countminus...", 1);
        //msg_f(diff, 2);
        //msg_f(clock.now(),3);
        run();
      }
    }else{
    //明るかった時
      //時間のリセット
      clock.reset();
      //msg_f("normal...", 1);
      //msg_f(diff, 2);
      run();
    }
  }
}

void RightAngleDetection::detectionIf2(int diff) {
  //暗い状態に入った瞬間
  if(diff<6){
      //msg_f("stop:angle", 1);
      //msg_f(diff, 2);
      leftWheel.stop();
      rightWheel.stop();
    }else{
    //明るかった時
      //時間のリセット
      clock.reset();
      //msg_f("normal...", 1);
      //msg_f(diff, 2);
      run();
  }
}
//最小の明度と最大タイムを計ってる
void RightAngleDetection::detectionIf3(int diff) {
  if(move){
    if(diff<7){
      //暗い状態（線の上いる時）が1000msを超えたら止める
      if(clock.now()>3000){
        // if(clock.now()>3000){
        //msg_f("stop:angle", 1);
        //msg_f(diff, 2);
        leftWheel.stop();
        rightWheel.stop();
        if(diff<7){
          move = false;
        }
      }else{
        //1秒なるまではそのまま走る，
        //線上時間の最大時間を計測
        if(clock.now()>max_time){
          max_time = clock.now();
          //msg_f(max_time,4);
        }
        //msg_f("countminus...", 1);
        //msg_f(diff, 2);
        //msg_f(clock.now(),3);
        run();
      }
    }else{
    //明るかった時
      //時間のリセット
      clock.reset();
      //msg_f("normal...", 1);
      //msg_f(diff, 2);
      run();
    }
  }
}

