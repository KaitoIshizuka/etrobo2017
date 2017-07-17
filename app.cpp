
#include "app.h"
#include "util.h"
#include "Clock.h"
#include "SonarSensor.h"

// 一時的に
#include <string>


using namespace ev3api;


SonarSensor sonarSensor(PORT_2);
Clock clock;

void main_task(intptr_t unused){

  /*
  SonarSensor sonarSensor(PORT_2);
  センサーのコンストラクタ
  コンストラクタ(関数)
　  ∟オブジェクトを作る際に内容を初期化する関数
  */

  ext_tsk();
}

