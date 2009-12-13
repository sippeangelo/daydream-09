#include "Color.h"

Color operator+(const Color &col1, const Color &col2)
{
	return Color(col1.r + col2.r, col1.g + col2.g, col1.b + col2.b, col1.a - col2.a);
}

Color operator-(const Color &col1, const Color &col2)
{
	return Color(col1.r - col2.r, col1.g - col2.g, col1.b - col2.b, col1.a - col2.a);
}

Color::Color(int arg_r, int arg_g, int arg_b)
{
	r = arg_r;
	g = arg_g;
	b = arg_b;
	a = 255;
}

Color::Color(int arg_r, int arg_g, int arg_b, int arg_a)
{
	r = arg_r;
	g = arg_g;
	b = arg_b;
	a = arg_a;
}