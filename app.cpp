#include "app.h"
#include "util.h"
#include "Tracer.h"
#include "Calibration.h"
#include "Clock.h"
#include "plaBoard.h"
#include "ItemMove.h"
#include "GetStart.h"

// 一時的に
#include <string>


using namespace ev3api;

Tracer tracer;
Clock clock;
Calibration cab;
plaBoard plaBoard;
ItemMove IM;
GetStart getStart;

void main_task(intptr_t unused){

  /*
  SonarSensor sonarSensor(PORT_2);
  センサーのコンストラクタ
  コンストラクタ(関数)
　  ∟オブジェクトを作る際に内容を初期化する関数
  */
  tracer.init();
  //  cab.getBrightness();
  int black = cab.ColorCalibration();
  int white = cab.ColorCalibration();
  int target = (black + white) * 0.5;

//  tracer.setCollorTarget(target);
  tracer.setCollorTarget(360);
  tracer.setPwm(30);

  getStart.run();
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
	//plaBoard.init();
	//IM.run();

  msg_f("Fin",1);
  while(1){}

  ext_tsk();
}

