#ifndef COLOR_H
#define COLOR_H

#include <d3dx9.h>

class Color
{
public:
	// Overloaded operators
	friend Color operator+(const Color &col1, const Color &col2);
	friend Color operator-(const Color &col1, const Color &col2);

	Color(int r, int g, int b);
	Color(int r, int g, int b, int a);
	D3DCOLOR GetD3D();

	// Red
	int r;
	// Green
	int g;
	// Blue
	int b;
	// Alpha
	int a;
};

#endif