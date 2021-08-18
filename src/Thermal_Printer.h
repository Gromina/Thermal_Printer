//
// Thermal Printer Library
// written by Larry Bank
// Copyright (c) 2020 BitBank Software, Inc.
//
// Copyright 2020 BitBank Software, Inc. All Rights Reserved.
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//    http://www.apache.org/licenses/LICENSE-2.0
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//===========================================================================
//

#ifndef __THERMAL_PRINTER_H__
#define __THERMAL_PRINTER_H__

#define FONT_SMALL 0
#define FONT_LARGE 1
#define FONT_12x24 0
#define FONT_9x17  1
//
// Select one of 2 available text fonts along with attributes
// FONT_12x24 or FONT_9x17
// Each option is either 0 (disabled) or 1 (enabled)
// These are the text attributes offered by the standard printer spec
//
void tpSetFont(int iFont, int iUnderline, int iDoubleWide, int iDoubleTall, int iEmphasized);

//
// Provide a back buffer for your printer graphics
// This allows you to manage the RAM used on
// embedded platforms like Arduinos
// The memory is laid out horizontally (384 pixels across = 48 bytes)
// So a 384x384 buffer would need to be 48x384 = 18432 bytes
//
void tpSetBackBuffer(uint8_t *pBuffer, int iWidth, int iHeight);
//
// Print plain text immediately
//
// Pass a C-string (zero terminated char array)
// If the text doesn't reach the end of the line
// it will not be printed until the printer receives
// a CR (carriage return) or new text which forces
// it to wrap around
//
int tpPrint(char *pString);
//
// Print plain text immediately
// Pass a C-string (zero terminated char array)
// A CR (carriage return) will be added at the end
// to cause the printer to print the text and advance
// the paper one line
//
int tpPrintLine(char *pString);
//
// Draw text into the graphics buffer
//
int tpDrawText(int x, int y, char *pString, int iFontSize, int bInvert);
//
// Load a 1-bpp Windows bitmap into the back buffer
// Pass the pointer to the beginning of the BMP file
// along with a x and y offset (upper left corner)
//
int tpLoadBMP(uint8_t *pBMP, int bInvert, int iXOffset, int iYOffset);

//
// Fill the frame buffer with a byte pattern
// e.g. all off (0x00) or all on (0xff)
//
void tpFill(unsigned char ucData);
//
// Set (or clear) an individual pixel
//
int tpSetPixel(int x, int y, uint8_t ucColor);
//
// Send the graphics to the printer (must be connected over BLE first)
//
void tpPrintBuffer(void);
//
// Draw a line between 2 points
//
void tpDrawLine(int x1, int y1, int x2, int y2, uint8_t ucColor);
//
// Scan for compatible printers
// returns true if found
// and stores the printer address internally
// for use with the tpConnect() function
// szName is the printer device name to match
// iSeconds = how many seconds to scan for devices
//
int tpScan(const char *szName, int iSeconds);
//
// After a successful scan, connect to the printer
// returns 1 if successful, 0 for failure
//
int tpConnect(void);
void tpDisconnect(void);
#endif // __THERMAL_PRINTER_H__
