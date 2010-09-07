#ifndef COLOR_H
#define COLOR_H

//#include <d3dx9.h> // HACK:: Should not depend on DirectX

class Color
{
public:
	// Overloaded operators
	friend Color operator+(const Color &col1, const Color &col2);
	friend Color operator-(const Color &col1, const Color &col2);

	Color();
	Color(float r, float g, float b);
	Color(float r, float g, float b, float a);
	void Set(float arg_r, float arg_g, float arg_b);
	void Set(float arg_r, float arg_g, float arg_b, float arg_a);
	//D3DCOLOR GetD3D(); // HACK: Should not depend on DirectX

	// Red
	float r;
	// Green
	float g;
	// Blue
	float b;
	// Alpha
	float a;
};

#endif