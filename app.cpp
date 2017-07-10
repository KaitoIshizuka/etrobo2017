//いんちょのてすとコメント
#include "app.h"
#include "WheelCtrl.h"

#include "util.h"
#include "Clock.h"


using namespace ev3api;

void main_task(intptr_t unused){
  /*
  SonarSensor sonarSensor(PORT_2);
  センサーのコンストラクタ
  コンストラクタ(関数)
　  ∟オブジェクトを作る際に内容を初期化する関数
  */
  Clock clock;
  WheelCtrl wc;
  wc.setPWM(100);


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

