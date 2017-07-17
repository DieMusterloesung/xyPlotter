#include "xy-plotter.h"

unsigned char xCurrent = 0;
unsigned char yCurrent = 0;
unsigned char isDrawing = 0;


void initPlotter(){
	plotterPort = 0x00;
}

void drawLine(unsigned char xStart, unsigned char yStart, unsigned char xEnd, unsigned char yEnd){
	// todo: xStart und xEnd beliebig, bis jetzt xStart < xEnd!!!
	unsigned char deltaX, deltaY;
	unsigned char n, ratio, rest, swap;
	//unsigned char directionHorizontal, directionVertical;
	
	deltaX = abs((signed char)xStart - (signed char)xEnd);
	deltaY = abs((signed char)yStart - (signed char)yEnd);
	
	move(xStart, yStart);
	
	/*
	- berechne das verhältnis von x zu y !!!(wenn x > y, sonst y zu x)!!!
	- berechne den rest(wegen ungenauigkeit bei ganzzahlen)
	- stufen mit der größe des verhältnis x oder y mal zeichenen und jedes mal eins nach oben oder zur seite gehen
	- stufe mit der größe rest noch zeichnen
	*/
	
	if(deltaX <= deltaY){
		deltaX++;
		// Line is heigher than wider
		ratio = deltaY / deltaX;
		rest = deltaY % deltaX;
		if(yStart <= yEnd){
			// Line goes up
			n = deltaX;
			while(n){
				DrawingPin = 1;
				yUp(ratio);
				DrawingPin = 0;
				xUp(1);
				n--;
			}
			++xEnd;
		}else{
			// Line goes down
			n = deltaX;
			while(n){
				DrawingPin = 1;
				yDown(ratio);
				DrawingPin = 0;
				xUp(1);
				n--;
			}
			--xEnd;
		}
	}else{
		deltaY++;
		// Line is wider than heigher
		ratio = deltaX / deltaY;
		rest = deltaX % deltaY;
		if(yStart <= yEnd){
			// Line goes up
			n = deltaY;
			while(n){
				DrawingPin = 1;
				xUp(ratio);
				DrawingPin = 0;
				yUp(1);
				n--;
			}
			++yEnd;
		}else{
			//Line goes down
			n = deltaY;
			while(n){
				DrawingPin = 1;
				xUp(ratio);
				DrawingPin = 0;
				yDown(1);
				n--;
			}
			--yEnd;
		}
	}
	xCurrent = xEnd;
	yCurrent = yEnd;
	
}

void drawPixel(unsigned char xPos, unsigned char yPos, Color c){
	move(xPos, yPos);
	setColor(c);
	DrawingPin = 1;
	DrawingPin = 0;
}

void move(unsigned char xPos, unsigned char yPos){
	signed char dif;
	
	DrawingPin = 0;
	dif = (signed char)xPos - (signed char)xCurrent;
	if(dif > 0){
		xUp(dif);
	}else{
		xDown(abs(dif));
	}
	
	dif = (signed char)yPos - (signed char)yCurrent;
	if(dif > 0){
		yUp(dif);
	}else{
		yDown(abs(dif));
	}
	
	xCurrent = xPos;
	yCurrent = yPos;
}

void setColor(Color c){
	switch(c){
		case black:
			ColorPin1 = 0;
			ColorPin2 = 0;
			break;
		case red:
			ColorPin1 = 1;
			ColorPin2 = 0;
			break;
		case blue:
			ColorPin1 = 0;
			ColorPin2 = 1;
			break;
		case green:
			ColorPin1 = 1;
			ColorPin2 = 1;
			break;
		default:
			break;
	}
}

void xUp(unsigned char n){
	while(n){
		xUpPin = ~xUpPin;
		xUpPin = ~xUpPin;
		n--;
	}
}

void xDown(unsigned char n){
	while(n){
		xDownPin = ~xDownPin;
		xDownPin = ~xDownPin;
		n--;
	}
}
	
void yUp(unsigned char n){
	while(n){
		yUpPin = ~yUpPin;
		yUpPin = ~yUpPin;
		n--;
	}
}

void yDown(unsigned char n){
	while(n){
		yDownPin = ~yDownPin;
		yDownPin = ~yDownPin;
		n--;
	}
}