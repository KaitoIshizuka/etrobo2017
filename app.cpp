//いんちょのてすとコメント
#include "app.h"
#include "runStraight.h"

#include "util.h"

// 一時的に
#include <string>


using namespace ev3api;

void main_task(intptr_t unused){
  const int pwm = 50;
  const int distance = 4000;
  /*
  SonarSensor sonarSensor(PORT_2);
  センサーのコンストラクタ
  コンストラクタ(関数)
　  ∟オブジェクトを作る際に内容を初期化する関数
  */
  runStraight runSt;
  //各モータのエンコーダ値を出力
  //std::string right_data = "rightEncd " + rightEncd_val;
  //std::string left_data = "leftEncd " + leftEncd_val;
  //const char* str1 = right_data.c_str();
  //const char* str2 = left_data.c_str();
  //msg_f(str1, 1);
  //msg_f(str2, 2);
  runSt.setPwm(pwm);
  runSt.run(distance);
  runSt.term();

  ext_tsk();
}

