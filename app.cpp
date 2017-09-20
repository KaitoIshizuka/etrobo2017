#include "app.h"
#include "util.h"
#include "Tracer.h"
#include "Calibration.h"
#include "Clock.h"
#include "GetStart.h"

// 一時的に
#include <string>


using namespace ev3api;

Tracer tracer;
Clock clock;
Calibration cab;
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
  int black = cab.getColor();
  int white = cab.getColor();
  int target = (black + white) * 0.48;

  tracer.setCollorTarget(target);

  getStart.run();//スタート

//  tracer.run(14500);
/*
  //↓ Lコース
  tracer.setRL(1);//0:右エッジ, 1:左エッジ
  tracer.setStraight(1);
  tracer.setPwm(100);
  tracer.run(3000);

  tracer.setStraight(0);
  tracer.setPwm(70);
  tracer.run(12100);

  tracer.setStraight(1);
  tracer.setPwm(100);
  tracer.run(14100);
  //↑ Lコース
*/


  //↓ Rコース
  target = (black + white) * 0.47;
  tracer.setCollorTarget(target);


  tracer.setRL(1);//0:右エッジ, 1:左エッジ
  tracer.setStraight(1);
  tracer.setPwm(100);
  tracer.run(3000);

  target = (black + white) * 0.45;
  tracer.setCollorTarget(target);
  tracer.setStraight(0);
  tracer.setPwm(70);
  tracer.run(12500);

  target = (black + white) * 0.47;
  tracer.setCollorTarget(target);
  tracer.setStraight(1);
  tracer.setPwm(100);
  tracer.run(14500);
  //↑ Rコース
  


  tracer.terminate();
  clock.wait(2000);
  // 期待回収用
  tracer.setCollorTarget(target+30);
  tracer.setStraight(1);
  tracer.setPwm(50);
  tracer.run(17500);


  tracer.terminate();
	//plaBoard.init();
	//IM.run();

  msg_f("Fin",1);
  while(1){}

  ext_tsk();
}

