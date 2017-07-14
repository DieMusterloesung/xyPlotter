#ifndef _XY_PLOTTER_H_
#define _XY_PLOTTER_H_
#include <at89c5131.h>
#include <math.h>

#define plotterPort	P0

#define xUpPin			P0_0			/* High activ */		
#define xDownPin		P0_1			/* "" */
#define yUpPin			P0_2			/* "" */
#define yDownPin		P0_3			/* "" */
#define DrawingPin	P0_4			/* 0=Up, 1=Down */
#define ColorPin1		P0_5			
#define ColorPin2		P0_6			/* 00 = schwarz; 10 = rot; 01 = blau; 11= grün  */
#define ResetPin		P0_7			/* Reset */

typedef enum {black, red, blue, green} Color;
/*
	Color typ with 4 constants for each of the 4 supported colors
*/

static unsigned char WIDTH = 80;
static unsigned char HEIGTH = 80;

static unsigned char WIDTH_HALF = 40;
static unsigned char HEIGTH_HALF = 40;
/*
	pixel width and height of the plotter and half
*/

void initPlotter();

void drawLine(unsigned char xStart, unsigned char yStart, unsigned char xEnd, unsigned char yEnd);
/*
	draw a Line from start cords to end cords with given color
*/

void drawPixel(unsigned char xPos, unsigned char yPos, Color c);
/*
	draw a Pixel at given cord with given color
*/

void move(unsigned char xPos, unsigned char yPos);
/*
	moves the plotter to the given cords
*/

void setColor(Color c);
/*
	set the given Color
*/

void xUp(unsigned char n);
void xDown(unsigned char n);
void yUp(unsigned char n);
void yDown(unsigned char n);

extern unsigned char xCurrent;
extern unsigned char yCurrent;
extern unsigned char isDrawing;
/*
	global variables for plotter pos and draw mode
*/

#endif


