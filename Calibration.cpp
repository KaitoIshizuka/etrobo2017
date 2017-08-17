#include "Calibration.h"

Calibration::Calibration():
  colorSensor(PORT_2),touchSensor(PORT_1),clock(){
  init_f("Calibration");
}

int8_t Calibration::run(){
  int8_t temp[10]={0};
  int8_t group[10]={0};
  int8_t braightness;

  int i=0,j=0,k=0;


  while(1){
	if(i>= 1){
	  if(touchSensor.isPressed()==true){break;}
	}
	i++;

	clock.wait(4);
  }

  for(i=0; i<10; i++){
	temp[i] = colorSensor.getBrightness();
  }

  int flg=0;
  int number_of_group[10]={0};//各groupの要素数を持っとく

  for(i=0; i<10; i++){//tempの要素数だけ回る
	for(j=0; j<=flg; j++){//グループの数だけ回る
	  if((group[j]-5) < temp[i] && temp[i] < (group[j]+5)){//もし似たグループがあれば
		//グループの値と光センサの値の一つの平均を取る。
		group[j] += temp[i];
		group[j] /= 2;
		number_of_group[j]+=1;
	  }else{
		//新しいグループを作る。
		group[j+1] = temp[i];
		number_of_group[j+1]+=1;
		//グループを作ったためそのグループまで探索が及ぶように++
		flg++; 
	  }
	}
  }

	msg_f(temp[0],1);

	msg_f(group[0],2);


  int8_t soeji_of_maxnumber=0;
  for(k=0; k<=flg; k++){//number_of_groupから各groupの要素数最大の値を返す
	if(number_of_group[k] > soeji_of_maxnumber){
	  soeji_of_maxnumber = k;
	}
  }

  msg_f(group[soeji_of_maxnumber],3);


  braightness = group[soeji_of_maxnumber];

  return braightness;
}


