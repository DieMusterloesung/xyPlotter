#include "xy-plotter.h"

unsigned char xCurrent = 0;
unsigned char yCurrent = 0;
unsigned char isDrawing = 0;

void drawLine(unsigned char xStart, unsigned char yStart, unsigned char xEnd, unsigned char yEnd){
	// todo: xStart und xEnd beliebig, bis jetzt xStart < xEnd!!!
	signed char deltaX, deltaY, space;
	unsigned char totalSteps, spaceSteps, restSteps;
	deltaX = abs(xStart - xEnd);
	deltaY = abs(yStart - yEnd);
	
	move(xStart, yStart);
	
	/*
	- berechne das verhältnis von x zu y !!!(wenn x > y, sonst y zu x)!!!
	- berechne den rest(wegen ungenauigkeit bei ganzzahlen)
	- stufen mit der größe des verhältnis x oder y mal zeichenen und jedes mal eins nach oben oder zur seite gehen
	- stufe mit der größe rest noch zeichnen
	*/
	
	if(deltaX < deltaY){
		space = deltaY / deltaX;
		totalSteps = deltaX;
		restSteps = deltaY % deltaX;
		
		while(deltaX){
			spaceSteps = space;
			while(space){
				yUp(space);
				spaceSteps--;
			}
			xUp(1);
			deltaY--;
		}
		yUp(restSteps);
		
		
	}else{
		space = deltaY / deltaX;
		//todo
	}
	
}

void drawDiagonalLineUp(unsigned char xPos, unsigned char yPos, unsigned char length, color c){
	setColor(c);
	move(xPos, yPos);
	while(length){
		DrawingPin = 1;
		DrawingPin = 0;
		xUp(1);
		yUp(1);
		length--;
	}
}

void drawDiagonalLineDown(unsigned char xPos, unsigned char yPos, unsigned char length, color c){
	setColor(c);
	move(xPos, yPos);
	while(length){
		DrawingPin = 1;
		DrawingPin = 0;
		xUp(1);
		yDown(1);
		length--;
	}
}

void drawHorizontalLine(unsigned char xPos, unsigned char yPos, unsigned char length, color c){
	move(xPos, yPos);
	setColor(c);
	DrawingPin = 1;
	xUp(length);
	DrawingPin = 0;
}

void drawVerticalLine(unsigned char xPos, unsigned char yPos, unsigned char height, color c){
	move(xPos, yPos);
	setColor(c);
	DrawingPin = 1;
	yUp(height);
	DrawingPin = 0;
}

void drawPixel(unsigned char xPos, unsigned char yPos, color c){
	move(xPos, yPos);
	setColor(c);
	DrawingPin = 1;
	DrawingPin = 0;
}

void move(unsigned char xPos, unsigned char yPos){
	signed char n;
	
	DrawingPin = 0;
	n = xPos - xCurrent;
	if(n > 0){
		xUp(n);
	}else{
		xDown(abs(n));
	}
	
	n = yPos - yCurrent;
	if(n > 0){
		yUp(n);
	}else{
		yDown(abs(n));
	}
}

void setColor(color c){
	switch(c){
		case schwarz:
			ColorPin1 = 0;
			ColorPin2 = 0;
			break;
		case rot:
			ColorPin1 = 1;
			ColorPin2 = 0;
			break;
		case blau:
			ColorPin1 = 0;
			ColorPin2 = 1;
			break;
		case gruen:
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