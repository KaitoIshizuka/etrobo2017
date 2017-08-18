#include "SumouMove.h"
#include "util.h"


void SumouMove::run(int flag){

	wc.setPWM(10);

  //基準となる地点の値を取る
  //たとえば色を判断した地点とか
	startRight = wc.getCount(0);
	startLeft = wc.getCount(1);
	startAve = (startRight + startLeft) / 2;

	//寄り切り
	if(flag == 0){
		//前進
        while(1){//無限ループ
        	//現在地点の値を取る
        	nowRight = wc.getCount(0);
        	nowLeft = wc.getCount(1);
        	nowAve = (nowRight + nowLeft) / 2;
        	goal = nowAve - startAve;

        	//基準地点から現在地点の距離の条件
        	if(goal == 50){
        		wc.stop();

                //基準値設定
                startRight = wc.getCount(0);
                startLeft = wc.getCount(1);
                startAve = (startRight + startLeft) / 2;

        		break;
        	}
        }
        //右車輪動かす
        while(1){//無限ループ
            //現在地点の値を取る
            nowRight = wc.getCount(0);
            nowLeft = wc.getCount(1);
            nowAve = (nowRight + nowLeft) / 2;
            goal = nowAve - startAve;

            wc.setPWM(20,0);

            //基準地点から現在地点の距離の条件
            if(goal == 150){
                wc.stop();

                //基準値設定
                startRight = wc.getCount(0);
                startLeft = wc.getCount(1);
                startAve = (startRight + startLeft) / 2;

                break;
            }
        }
        //戻す
        while(1){//無限ループ
            //現在地点の値を取る
            nowRight = wc.getCount(0);
            nowLeft = wc.getCount(1);
            nowAve = (nowRight + nowLeft) / 2;
            goal = nowAve - startAve;

            wc.setPWM(-20,0);

            //基準地点から現在地点の距離の条件
            if(goal == -150){
                wc.stop();

                //基準値設定
                startRight = wc.getCount(0);
                startLeft = wc.getCount(1);
                startAve = (startRight + startLeft) / 2;

                break;
            }
        }
        //後退
        while(1){
            wc.setPWM(-20,0);
            wc.setPWM(-20,1);

            nowRight = wc.getCount(0);
            nowLeft = wc.getCount(1);
            nowAve = (nowRight + nowLeft) / 2;
            goal = nowAve - startAve;

            if(goal == -100){
               wc.stop();

               break;
            }
        }


    //押し出し
    }else if(flag == 1){
            //前進,押し出す
        while(1){
            wc.setPWM(10);

            nowRight = wc.getCount(0);
            nowLeft = wc.getCount(1);
            nowAve = (nowRight + nowLeft) / 2;
            goal = nowAve - startAve;

            if(goal == 200){
               wc.stop();

               //ストップしたところの基準値を設定する
               startRight = wc.getCount(0);
               startLeft = wc.getCount(1);
               startAve = (startRight + startLeft) / 2;

               break;
            }
        }
            //後退
        while(1){
            wc.setPWM(-20,0);
            wc.setPWM(-20,1);

            nowRight = wc.getCount(0);
            nowLeft = wc.getCount(1);
            nowAve = (nowRight + nowLeft) / 2;
            goal = nowAve - startAve;

            if(goal == -250){
                wc.stop();

                break;
            }
        }
    }
}