#ifndef FONT_H
#define FONT_H

#include "Color.h"
#include "../Render/D3D.h"
#include <string>

class Font
{
public:
	Font(Render::D3D::Interface* d3d);
	Font(Render::D3D::Interface* d3d, std::string FontName, int size);

	void SetFont(std::string FontName);
	void SetSize(int size);
	void SetColor(Color col);
	LPD3DXFONT* Create();

private:
	Render::D3D::Interface* m_d3d;
	LPD3DXFONT m_Font;
	std::string m_FontName;
	Color m_Color;
	int m_Size;
};

#endif