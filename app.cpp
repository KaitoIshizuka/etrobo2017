#include "app.h"
#include "util.h"
#include "Motor.h"
#include "Clock.h"
#include "SonarSensor.h"


using namespace ev3api;

void main_task(intptr_t unused){
  /*
  SonarSensor sonarSensor(PORT_2);
  センサーのコンストラクタ
  コンストラクタ(関数)
　  ∟オブジェクトを作る際に内容を初期化する関数
  */
  Motor leftWheel(PORT_C);
  Motor rightWheel(PORT_B);
  SonarSensor sonarSensor(PORT_2);
  Clock clock;

  init_f(__FILE__);
  while(1){//無限ループ


    msg_f("rooping.", 1);

    //左ボタン押下でループ抜ける
    if (ev3_button_is_pressed(LEFT_BUTTON)) {
      break;
    }
  }

  ext_tsk();
}

