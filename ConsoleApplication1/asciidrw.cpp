#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream>
#include "asciidrw.h"
#include <ctype.h>
#include "windows.h"

asciidrw::asciidrw()
{

}

void asciidrw::draw(const char txtname[100])
{
	FILE * f;
	char n;
	f = fopen(txtname, "rt");
	//HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//CONSOLE_FONT_INFOEX font;//CONSOLE_FONT_INFOEX is defined in some windows header
	//GetCurrentConsoleFontEx(out_handle, false, &font);//PCONSOLE_FONT_INFOEX is the same as CONSOLE_FONT_INFOEX*
	//font.cbSize = sizeof(font);
	//font.dwFontSize.X = 4;
	//font.dwFontSize.Y = 4;
	//font.FontFamily = FF_DONTCARE;
	//font.FontWeight = FW_NORMAL;
	//SetCurrentConsoleFontEx(out_handle, false, &font);
	while (!feof(f))
	{
		int res = fscanf(f, "%c", &n);
		if (res == EOF)
			break;
		printf("%c", n);
	}
	
}

//void asciidrw::drawtext(const char txtname[100])
//{
//	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
//	CONSOLE_FONT_INFOEX font;//CONSOLE_FONT_INFOEX is defined in some windows header
//	GetCurrentConsoleFontEx(out_handle, false, &font);//PCONSOLE_FONT_INFOEX is the same as CONSOLE_FONT_INFOEX*
//	font.cbSize = sizeof(font);
//	font.dwFontSize.X = 8;
//	font.dwFontSize.Y = 16;
//	font.FontFamily = FF_DONTCARE;
//	font.FontWeight = FW_NORMAL;
//	SetCurrentConsoleFontEx(out_handle, false, &font);
//	/*FILE * f;
//	char n;
//	f = fopen(txtname, "rt");
//	while (!feof(f))
//	{
//		int res = fscanf(f, "%c", &n);
//		if (res == EOF)
//			break;
//		printf("%c", n);
//	}*/
//}

int asciidrw::checknumber(char* inputnumber)
{
	//char *string = (char*)malloc(sizeof(char) * sizeof(inputnumber));
	//_itoa(inputnumber, string, 10);
	int i = 0;
	while(inputnumber[i])
	{
		if (isalpha(inputnumber[i]))
		{
			return 1;
		}
		
		i++;
	}
	int newnumber = atoi(inputnumber);
	return newnumber;
}

asciidrw::~asciidrw()
{
}
