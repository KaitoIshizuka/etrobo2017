#include "ItemMove.h"
#include "util.h"


//懸賞まで行く
void ItemMove::run(){

	wc.setPWM(10);

  //基準となる地点の値を取る
	startRight = wc.getCount(0);
	startLeft = wc.getCount(1);
	startAve = (startRight + startLeft) / 2;

	//後退
	while(1){
		wc.setPWM(-10,0);
		wc.setPWM(-10,1);

		nowRight = wc.getCount(0);
		nowLeft = wc.getCount(1);
		nowAve = (nowRight + nowLeft) / 2;
		goal = nowAve - startAve;

		if(goal == -70){
			wc.stop();

			startRight = wc.getCount(0);
			startLeft = wc.getCount(1);
			startAve = (startRight + startLeft) / 2;

			break;
		}
	}
	//右車輪
	while(1){
		wc.setPWM(-10,0);

		nowRight = wc.getCount(0);
		nowLeft = wc.getCount(1);
		nowAve = (nowRight + nowLeft) / 2;
		goal = nowAve - startAve;

		if(goal == -150){
			wc.stop();

			startRight = wc.getCount(0);
			startLeft = wc.getCount(1);
			startAve = (startRight + startLeft) / 2;

			break;
		}
	}
	//前進
	while(1){
		wc.setPWM(10,0);
		wc.setPWM(10,1);

		nowRight = wc.getCount(0);
		nowLeft = wc.getCount(1);
		nowAve = (nowRight + nowLeft) / 2;
		goal = nowAve - startAve;

		if(goal == 445){
			wc.stop();

			startRight = wc.getCount(0);
			startLeft = wc.getCount(1);
			startAve = (startRight + startLeft) / 2;

			break;
		}
	}	



	//ここでアームを上げる処理を入れたい




	//後退
	while(1){
		wc.setPWM(-20,0);
		wc.setPWM(-20,1);

		nowRight = wc.getCount(0);
		nowLeft = wc.getCount(1);
		nowAve = (nowRight + nowLeft) / 2;
		goal = nowAve - startAve;

		if(goal == -445){
			wc.stop();

			startRight = wc.getCount(0);
			startLeft = wc.getCount(1);
			startAve = (startRight + startLeft) / 2;

			break;
		}
	}
	//右車輪
	while(1){
		wc.setPWM(10,0);

		nowRight = wc.getCount(0);
		nowLeft = wc.getCount(1);
		nowAve = (nowRight + nowLeft) / 2;
		goal = nowAve - startAve;

		if(goal == 150){
			wc.stop();

			break;
		}
	}
}


//懸賞を置きに行く
void ItemMove::place(){
	//前進
	while(1){
		wc.setPWM(10,0);
		wc.setPWM(10,1);

		nowRight = wc.getCount(0);
		nowLeft = wc.getCount(1);
		nowAve = (nowRight + nowLeft) / 2;
		goal = nowAve - startAve;

		if(goal == 600){
			wc.stop();

			startRight = wc.getCount(0);
			startLeft = wc.getCount(1);
			startAve = (startRight + startLeft) / 2;

			break;
		}
	}

	//右車輪
	while(1){
		wc.setPWM(-10,0);

		nowRight = wc.getCount(0);
		nowLeft = wc.getCount(1);
		nowAve = (nowRight + nowLeft) / 2;
		goal = nowAve - startAve;

		if(goal == -150){
			wc.stop();

			startRight = wc.getCount(0);
			startLeft = wc.getCount(1);
			startAve = (startRight + startLeft) / 2;

			break;
		}
	}	

	//前進
	while(1){
		wc.setPWM(10,0);
		wc.setPWM(10,1);

		nowRight = wc.getCount(0);
		nowLeft = wc.getCount(1);
		nowAve = (nowRight + nowLeft) / 2;
		goal = nowAve - startAve;

		if(goal == 400){
			wc.stop();

			startRight = wc.getCount(0);
			startLeft = wc.getCount(1);
			startAve = (startRight + startLeft) / 2;

			break;
		}
	}



	//懸賞を置く動作を入れたい(アーム下げる)




	//後退
	while(1){
		wc.setPWM(-20,0);
		wc.setPWM(-20,1);

		nowRight = wc.getCount(0);
		nowLeft = wc.getCount(1);
		nowAve = (nowRight + nowLeft) / 2;
		goal = nowAve - startAve;

		if(goal == -400){
			wc.stop();

			startRight = wc.getCount(0);
			startLeft = wc.getCount(1);
			startAve = (startRight + startLeft) / 2;

			break;
		}
	}

	//右車輪
	while(1){
		wc.setPWM(10,0);

		nowRight = wc.getCount(0);
		nowLeft = wc.getCount(1);
		nowAve = (nowRight + nowLeft) / 2;
		goal = nowAve - startAve;

		if(goal == 150){
			wc.stop();

			startRight = wc.getCount(0);
			startLeft = wc.getCount(1);
			startAve = (startRight + startLeft) / 2;

			break;
		}
	}	
}