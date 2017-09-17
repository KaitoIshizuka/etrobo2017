#include "app.h"
#include "util.h"
#include "Tracer.h"
#include "Calibration.h"
#include "plaBoard.h"
#include "ItemMove.h"

// 一時的に
#include <string>


using namespace ev3api;

//Tracer tracer;
Calibration cab;
plaBoard plaBoard;
ItemMove IM;

void main_task(intptr_t unused){

  /*
  SonarSensor sonarSensor(PORT_2);
  センサーのコンストラクタ
  コンストラクタ(関数)
　  ∟オブジェクトを作る際に内容を初期化する関数
  */
	//plaBoard.init();
	//IM.run();

  
  //  tracer.run(5000);
//  tracer.terminate();

//  cab.getBrightness();
  cab.getColor();

  msg_f("Fin",1);
  while(1){}

  ext_tsk();
}

