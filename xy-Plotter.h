#ifndef _XY_PLOTTER_H_
#define _XY_PLOTTER_H_
#include <at89c5131.h>
#include <math.h>


#define xUpPin			P0_0			/* High activ */		
#define xDownPin		P0_1			/* "" */
#define yUpPin			P0_2			/* "" */
#define yDownPin		P0_3			/* "" */
#define DrawingPin	P0_4			/* 0=Up, 1=Down */
#define ColorPin1		P0_5			
#define ColorPin2		P0_6			/* 00 = schwarz; 10 = rot; 01 = blau; 11= grün  */
#define ResetPin		P0_7			/* Reset */

typedef enum {schwarz, rot, blau, gruen} color;
/*
enemun for color
*/

static unsigned char WIDTH = 80;
static unsigned char HEIGTH = 80;

static unsigned char WIDTH_HALF = 40;
static unsigned char HEIGTH_HALF = 40;
/*
size(pixels) of the plotter
*/

void drawLine(unsigned char xStart, unsigned char yStart, unsigned char xEnd, unsigned char yEnd);

void drawPixel(unsigned char xPos, unsigned char yPos, color c);
/*
xPos: 	x position
yPos: 	y position
c:			color of pixel
*/

void move(unsigned char xPos, unsigned char yPos);
/*
xPos: 	moves to x
yPos: 	moves to y
	!!! disables drawing !!!
*/

void setColor(color c);
/*
c:			color to set
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


