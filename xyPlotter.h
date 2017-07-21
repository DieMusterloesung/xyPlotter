#ifndef _XY_PLOTTER_H_
#define _XY_PLOTTER_H_

#include <at89c5131.h>

#define plotterPort		P0

#define xUpPin			P0_0
#define xDownPin		P0_1
#define yUpPin			P0_2
#define yDownPin		P0_3
#define drawingPin	P0_4
#define colorPin0		P0_5
#define colorPin1		P0_6
#define resetPin		P0_7



typedef enum {black, red, blue ,green} Color;

extern unsigned char currentX;
extern unsigned char currentY;


void initPlotter();
void drawLineAbs(unsigned char startX, unsigned char startY,  unsigned char endX, unsigned char endY, Color c);
void drawLineRel(signed char startX, signed char startY,  signed char endX, signed char endY, Color c);
void drawPixelAbs(unsigned char posX, unsigned char posY, Color c);
void drawPixelRel(unsigned char posX, unsigned char posY, Color c);
void moveAbs(unsigned char posX, unsigned char posY);
void moveRel(signed char posX, signed char posY);
void moveAbsSmooth(unsigned char posX, unsigned char posY);
void setColor(Color c);

#endif