#include "Calibration.h"

Calibration::Calibration():
  colorSensor(PORT_2),clock(),touchSensor(PORT_1){
  init_f("Calibration");
}

int8_t Calibration::getBrightness(){
  int8_t temp[10]={0};
  int8_t group[10]={0};
  int8_t braightness;

  while(1){//タッチセンサが押されるまで待機
	clock.wait(20);
	if(true == touchSensor.isPressed()){break;}
  }

  for(int i=0; i<10; i++){
	clock.wait(20);
	temp[i] = colorSensor.getBrightness();
  }

  int flg=0;
  int group_in_flg=0;
  int number_of_group[10]={0};//各groupの要素数を持っとく
  int i=0,j=0,k=0;

  for(i=0; i<10; i++){//tempの要素数だけ回る
	for(j=0; j<=flg; j++){//グループの数だけ回る グループを見回って追加のみ行う
	  if((group[j]-5) < temp[i] && temp[i] < (group[j]+5)){//もし似たグループがあれば
		//グループの値と光センサの値の一つの平均を取る。
		group[j] += temp[i];
		group[j] /= 2;
		number_of_group[j]+=1;
		group_in_flg = 1;
	  }
	}
	if(group_in_flg == 0){
		//ここに新しいグループを作る。
		group[j] = temp[i];
		number_of_group[j]+=1;
		//グループを作ったためそのグループまで探索が及ぶように++
		flg++; 
	}
	group_in_flg = 0;
  }


  for(i=0; 0 < group[i]; i++){//要素の入ったgroupの要素数だけ回る
	msg_f(group[i],i+3);
  }

  int8_t soeji_of_maxnumber=0;
  for(k=0; k<=flg; k++){//number_of_groupから各groupの要素数最大の値を返す
	if(number_of_group[k] > soeji_of_maxnumber){
	  soeji_of_maxnumber = k;
	}
  }

  msg_f(group[soeji_of_maxnumber],2);


  braightness = group[soeji_of_maxnumber];

  return braightness;
}


int8_t Calibration::getColor(){
  int8_t temp[10]={0};
  int8_t group[10]={0};
  int8_t color;
  rgb_raw_t rgb;

  while(1){//タッチセンサが押されるまで待機
	clock.wait(20);
	if(true == touchSensor.isPressed()){break;}
  }

  for(int i=0; i<10; i++){
	clock.wait(20);
	colorSensor.getRawColor(rgb);
	temp[i] = rgb.r + rgb.g + rgb.b;
  }

  int flg=0;
  int group_in_flg=0;
  int number_of_group[10]={0};//各groupの要素数を持っとく
  int i=0,j=0,k=0;

  for(i=0; i<10; i++){//tempの要素数だけ回る
	for(j=0; j<=flg; j++){//グループの数だけ回る グループを見回って追加のみ行う
	  if((group[j]-10) < temp[i] && temp[i] < (group[j]+10)){//もし似たグループがあれば
		//グループの値と光センサの値の一つの平均を取る。
		group[j] += temp[i];
		group[j] /= 2;
		number_of_group[j]+=1;
		group_in_flg = 1;
	  }
	}
	if(group_in_flg == 0){
		//ここに新しいグループを作る。
		group[j] = temp[i];
		number_of_group[j]+=1;
		//グループを作ったためそのグループまで探索が及ぶように++
		flg++; 
	}
	group_in_flg = 0;
  }


  for(i=0; 0 < group[i]; i++){//要素の入ったgroupの要素数だけ回る
	msg_f(group[i],i+3);
  }


  int8_t soeji_of_maxnumber=0;
  for(k=0; k<=flg; k++){//number_of_groupから各groupの要素数最大の値を返す
	if(number_of_group[k] > soeji_of_maxnumber){
	  soeji_of_maxnumber = k;
	}
  }

  msg_f(group[soeji_of_maxnumber],2);//返り値確認のディスプレイ表示


  color = group[soeji_of_maxnumber];

  return color;
}


