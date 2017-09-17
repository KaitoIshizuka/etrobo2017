#include "GetStart.h"

GetStart::GetStart():
  clock(),touchSensor(PORT_1){
}

void GetStart::run(){
  while(1){//タッチセンサが押されるまで待機
	clock.wait(20);
	if(true == touchSensor.isPressed()){break;}
  }


  while(1){//タッチセンサが離されるまで待機
	clock.wait(20);
	if(false == touchSensor.isPressed()){break;}
  }
}
 

