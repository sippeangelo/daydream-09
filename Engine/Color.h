#ifndef COLOR_H
#define COLOR_H

//#include <d3dx9.h> // HACK: Should not depend on DirectX

class Color
{
public:
	// Overloaded operators
	friend Color operator+(const Color &col1, const Color &col2);
	friend Color operator-(const Color &col1, const Color &col2);

	Color();
	Color(int r, int g, int b);
	Color(int r, int g, int b, int a);
	void Set(int arg_r, int arg_g, int arg_b);
	void Set(int arg_r, int arg_g, int arg_b, int arg_a);
	//D3DCOLOR GetD3D(); // HACK: Should not depend on DirectX

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