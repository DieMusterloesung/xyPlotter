#include "xyPlotter.h"
#include <at89c5131.h>


void main(){
	initPlotter();
	drawLineRel(10, 10, 30, 10);
	moveAbs(0, 0);
	while(1);
}