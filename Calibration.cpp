#include "Calibration.h"

calibration::calibration():
  colorSensor(PORT_2){
}

int8_t calibration::run(){
  int8_t temp[10];
  int8_t group[10];
  int8_t braightness;

  for(int i=0; i<10; i++){
	temp[i] = colorSensor.getBrightness();
  }

  int flg=0;
  int number_of_group[10]=0;//各groupの要素数を持っとく

  for(int i=0; i<10; i++){//tempの要素数だけ回る
	for(int j=0; j<=flg; j++){//グループの数だけ回る
	  if((group[j]-5) > temp[i] && temp[i] < (group[j]-5)){//もし似たグループがあれば
		//グループの値と光センサの値の一つの平均を取る。
		group[j] += temp[i];
		group[j] /= 2;
		number_of_group[j]++;
	  }else{
		//新しいグループを作る。
		group[j+1] = temp[i]
		number_of_group[j+1]++;
		//グループを作ったためそのグループまで探索が及ぶように++
		flg++; 
	  }
	}
  }

  return braightness;
}


