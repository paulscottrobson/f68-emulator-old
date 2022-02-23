// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		rendertext.cpp
//		Purpose:	Render text display
//		Created:	23rd February 2022
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************


#include <stdio.h>
#include "sys_processor.h"
#include "sys_debug_system.h"
#include "hardware.h"
#include "m68k.h"
#include "setup.h"
#include <gfx.h>

// *******************************************************************************************************************************
//											Convert a Vicky LUT to our RGB format
// *******************************************************************************************************************************

int HWConvertVickyLUT(BYTE8 *lut) {
	int parts[4];
	for (int i = 0;i < 4;i++) {
		parts[i] = (lut[i]) >> 4;
		if (parts[i] < 0) parts[i] = 0;
		if (parts[i] > 15) parts[i] = 15;
	}
	return parts[3]+(parts[2] << 4)+(parts[1] << 8);		// ARGB Bigendian
}

// *******************************************************************************************************************************
//													Render text screen
// *******************************************************************************************************************************

void HWRenderTextScreen(BYTE8 *vicky,BYTE8 *charMem,BYTE8 *colMem,BYTE8 *lutMem,BYTE8 *fontMem,int width,int height) {
	int pWidth = 768;
	int pHeight = 568;
	int scaleX = width/pWidth;
	int scaleY = height/pHeight;

	int cWidth = pWidth/8; 								// Chars per line
	int cHeight = pHeight/8; 							// Lines per screen
	int cBWidth = 100; 									// Byte lines per width
	int cSize = (scaleX < scaleY) ? scaleX : scaleY;	// Char Size in pixels.
	if (cSize < 1) cSize = 1;

	int colours[32];

	for (int i = 0;i < 32;i++) {
		colours[i] = HWConvertVickyLUT(lutMem+i*4);
	}

	SDL_Rect rc,rcp; 
	rc.w = width;rc.h = height; 						// Erase window space.
	rc.x = WIN_WIDTH/2 - rc.w/2;rc.y = WIN_HEIGHT/2-rc.h/2;
	GFXRectangle(&rc,0x840); 							// TODO: Correct background.

	int xOrg = WIN_WIDTH/2-cWidth*8*cSize/2; 			// Work out character origin.
	int yOrg = WIN_HEIGHT/2-cHeight*8*cSize/2;

	rc.x = xOrg;rc.y = yOrg; 							// Erase the screen background space to black default
	rc.w = cWidth * 8 * cSize;rc.h = cHeight * 8 * cSize;
	GFXRectangle(&rc,0x000);

	for (int x = 0;x < cWidth;x++) {
		for (int y = 0;y < cHeight;y++) {
			rc.x = xOrg+x*8*cSize;
			rc.y = yOrg+y*8*cSize;
			rc.w = rc.h = cSize;
			int ch = charMem[x+y*cBWidth];
			int col = colMem[x+y*cBWidth];
			int fgr = colours[col >> 4];
			int bgr = colours[(col & 0x0F)+16];
			for (int yc = 0;yc < 8;yc++) {
				int bitLine = fontMem[ch * 8 + yc];
				rcp = rc;
				rc.y += cSize;
				for (int xc = 0;xc < 8;xc++) {					
					GFXRectangle(&rcp,bitLine & 0x80 ? fgr:bgr);
					rcp.x += cSize;
					bitLine <<= 1;
				}
			}
		}
	}
}
