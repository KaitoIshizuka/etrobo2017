//いんちょのてすとコメント
#include "app.h"
#include "runStraight.h"

#include "util.h"
#include "Clock.h"
#include "SonarSensor.h"

// 一時的に
#include <string>


using namespace ev3api;

void oc();

runStraight runSt;
SonarSensor sonarSensor(PORT_2);
WheelCtrl wheelCtrl;
Clock clock;

void main_task(intptr_t unused){

  /*
  SonarSensor sonarSensor(PORT_2);
  センサーのコンストラクタ
  コンストラクタ(関数)
　  ∟オブジェクトを作る際に内容を初期化する関数
  */

  oc();
  ext_tsk();
}

void oc(){
  const int pwm = 50;
  const int distance = 20;

  while(1){

	runSt.setPwm(pwm);
	runSt.run(distance);
	if(sonarSensor.getDistance() <= 5){
	  runSt.setPwm(-pwm);
	  runSt.run(-100);
	  wheelCtrl.setPWM(-pwm,0);
	  wheelCtrl.setPWM(pwm,1);
	  clock.wait(500);
	}
	clock.wait(4);
  }
}
