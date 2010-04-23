#ifndef FONT_H
#define FONT_H

#include "../../Engine/Color.h"
#include "Interface.h"
#include <string>

class Font
{
public:
	Font();
	Font(Render::D3D::Interface* d3d);
	Font(Render::D3D::Interface* d3d, std::string FontName, int size, Color col);

	void SetFont(std::string FontName);
	std::string GetFont();
	void SetSize(int size);
	int GetSize();
	void SetColor(Color col);
	Color GetColor();
	LPD3DXFONT Create();
	LPD3DXFONT GetD3D();
private:
	Render::D3D::Interface* m_d3d;
	LPD3DXFONT m_Font;
	std::string m_FontName;
	Color m_Color;
	int m_Size;
};

#endif