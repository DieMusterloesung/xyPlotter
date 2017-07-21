#include "xyPlotter.h"

unsigned char currentX = 0;
unsigned char currentY = 0;


void initPlotter(){
	plotterPort = 0x00;
}


void drawLineAbs(unsigned char startX, unsigned char startY,  unsigned char endX, unsigned char endY, Color c){
	moveAbs(startX, startY);
	setColor(c);
	drawingPin = 1;
	moveAbs(endX, endY);
	drawingPin = 0;
}
void drawLineRel(signed char startX, signed char startY,  signed char endX, signed char endY, Color c){
	drawLineAbs( currentX + startX, currentY + startY, currentX + startX + endX, currentY + startY + endY, c );
}

void drawPixelAbs(unsigned char posX, unsigned char posY, Color c){
	moveAbs(posX, posY);
	setColor(c);
	drawingPin = 1;
	drawingPin = 0;
}
void drawPixelRel(unsigned char posX, unsigned char posY, Color c){
	drawPixelAbs( currentX + posX, currentY + posY, c );
}

void moveAbs(unsigned char posX, unsigned char posY){
	signed char offsetX, offsetY;
	
	
	offsetX = posX - currentX;
	offsetY = posY - currentY;
	
	currentX = posX;
	currentY = posY;
	
	
	while( offsetX || offsetY ){
		if(offsetX > 0){
				xUpPin = ~xUpPin;
				xUpPin = ~xUpPin;
				offsetX--;
		}else if(offsetX<0){
				xDownPin = ~xDownPin;
				xDownPin = ~xDownPin;
				offsetX++;
		}
		
		if(offsetY > 0){
				yUpPin = ~yUpPin;
				yUpPin = ~yUpPin;
				offsetY--;
		}else if(offsetY<0){
				yDownPin = ~yDownPin;
				yDownPin = ~yDownPin;
				offsetY++;
			}
	}
}

void moveAbsSmooth(unsigned char posX, unsigned char posY) {
	signed char offsetX, offsetY;
	
	
	offsetX = posX - currentX;
	offsetY = posY - currentY;
	
	currentX = posX;
	currentY = posY;
	if(offsetY%offsetX==0||offsetX%offsetY==0){
		if(offsetX<offsetY){
			unsigned char yMove=offsetY/offsetX;
			unsigned char step = offsetY/yMove;
			
		}
	}else{
		
	}
}

void moveRel(signed char posX, signed char posY){
	moveAbs(currentX + posX, currentY + posY);
}

void setColor(Color c){
	switch(c){
		case black:
			colorPin0 = 0;
			colorPin1 = 0;
			break;
		case red:
			colorPin0 = 1;
			colorPin1 = 0;
			break;
		case blue:
			colorPin0 = 0;
			colorPin1 = 1;
			break;
		case green:
			colorPin0 = 1;
			colorPin1 = 1;
			break;
	};
}
