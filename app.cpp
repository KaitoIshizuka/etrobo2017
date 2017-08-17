#include "app.h"
#include "util.h"
#include "Tracer.h"
#include "Calibration.h"
#include "Clock.h"

// 一時的に
#include <string>


using namespace ev3api;

//Tracer tracer;
Calibration cab;
Clock clock;



void main_task(intptr_t unused){

  /*
  SonarSensor sonarSensor(PORT_2);
  センサーのコンストラクタ
  コンストラクタ(関数)
　  ∟オブジェクトを作る際に内容を初期化する関数
  */
//  tracer.run(5000);
//  tracer.terminate();

  cab.run();
  while(1){
	clock.wait(4);
  }

  ext_tsk();
}

