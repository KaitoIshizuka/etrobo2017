#include "app.h"
#include "util.h"
#include "plaBoard.h"
#include "ItemMove.h"


// 一時的に
#include <string>


using namespace ev3api;

plaBoard plaBoard;
ItemMove IM;

void main_task(intptr_t unused){

	//plaBoard.init();

	IM.run();

  ext_tsk();
}

