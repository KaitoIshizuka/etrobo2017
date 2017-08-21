#include "app.h"
#include "util.h"
#include "Tracer.h"
#include "Calibration.h"
#include "Clock.h"

// 一時的に
#include <string>


using namespace ev3api;

Tracer tracer;
Clock clock;



void main_task(intptr_t unused){

  /*
  SonarSensor sonarSensor(PORT_2);
  センサーのコンストラクタ
  コンストラクタ(関数)
　  ∟オブジェクトを作る際に内容を初期化する関数
  */
  tracer.init();
  tracer.setPwm(10);
//  tracer.run(14500);
  tracer.walk(14500);
/*
  tracer.setPwm(100);
  tracer.run(3000);
  tracer.setPwm(70);
  tracer.run(12500);
  tracer.setPwm(100);
  tracer.run(14500);
*/
  tracer.terminate();
  ext_tsk();
}

