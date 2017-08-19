#include "app.h"
#include "util.h"
#include "plaBoard.h"
#include "ItemMove.h"
#include "WheelCtrl.h"


// 一時的に
#include <string>


using namespace ev3api;

plaBoard plaBoard;
ItemMove IM;
WheelCtrl wc;

	int32_t startRight = 0;
    int32_t startLeft = 0;
    float startAve = 0;

    int32_t nowRight = 0;
    int32_t nowLeft = 0;
    float nowAve = 0;

    float goal = 0;

void main_task(intptr_t unused){


	//plaBoard.init();

	//IM.run();

	wc.setPWM(20);
	startRight = wc.getCount(0);
	startLeft = wc.getCount(1);
	startAve = (startRight + startLeft) / 2;



	while(1){//無限ループ
        	//現在地点の値を取る
        	nowRight = wc.getCount(0);
        	nowLeft = wc.getCount(1);
        	nowAve = (nowRight + nowLeft) / 2;
        	goal = nowAve - startAve;


        	//基準地点から現在地点の距離の条件
        	if(goal == 1000){
        		wc.stop();

        		msg_f(nowRight);
        		msg_f(nowLeft);


        		break;
        	}
        }
	

  ext_tsk();
}

