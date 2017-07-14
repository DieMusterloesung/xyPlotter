#include "xy-plotter.h"

unsigned char xCurrent = 0;
unsigned char yCurrent = 0;
unsigned char isDrawing = 0;


void initPlotter(){
	plotterPort = 0x00;
}

void drawLine(unsigned char xStart, unsigned char yStart, unsigned char xEnd, unsigned char yEnd){
	// todo: xStart und xEnd beliebig, bis jetzt xStart < xEnd!!!
	signed char deltaX, deltaY, space;
	unsigned char totalSteps, spaceSteps, restSteps;
	deltaX = abs(xStart - xEnd);
	deltaY = abs(yStart - yEnd);
	
	move(xStart, yStart);
	
	/*
	- berechne das verh�ltnis von x zu y !!!(wenn x > y, sonst y zu x)!!!
	- berechne den rest(wegen ungenauigkeit bei ganzzahlen)
	- stufen mit der gr��e des verh�ltnis x oder y mal zeichenen und jedes mal eins nach oben oder zur seite gehen
	- stufe mit der gr��e rest noch zeichnen
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