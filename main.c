#include "xy-plotter.h"

void main(void){
	unsigned char p1x, p2x, p3x, p0x, p1y, p2y, p3y, p0y, n;
	initPlotter();
	p0x = 0;
	p0y = 0;
	
	p1x = 10;
	p1y = 0;
	
	p2x = 10;
	p2y = 10;
	
	p3x = 0;
	p3y = 10;
	for(n = 0; n < 8; n++){
		drawLine(p0x, p0y, p1x, p1y);
		drawLine(p1x, p1y, p2x, p2y);
		drawLine(p0x, p0y, p3x, p3y);
		drawLine(p3x, p3y, p2x, p2y);
		p0x += 10;
		p0y += 10;
		
		p1x += 10;
		p1y += 10;
		
		p2x += 10;
		p2y += 10;
		
		p3x += 10;
		p3y += 10;
	}
	
	move(40,40);
	while(1);
}


