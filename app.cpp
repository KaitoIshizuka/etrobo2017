#include "app.h"
#include "util.h"
#include "plaBoard.h"


// 一時的に
#include <string>


using namespace ev3api;

plaBoard plaBoard;

void main_task(intptr_t unused){

	plaBoard.init();

  ext_tsk();
}

