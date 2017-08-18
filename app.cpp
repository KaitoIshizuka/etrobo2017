#include "app.h"
#include "util.h"
#include "plaBoard.h"
#include "SumouMove.h"


// 一時的に
#include <string>


using namespace ev3api;

plaBoard plaBoard;
SumouMove SM;

void main_task(intptr_t unused){

	//plaBoard.init();

	SM.run(0);

  ext_tsk();
}

