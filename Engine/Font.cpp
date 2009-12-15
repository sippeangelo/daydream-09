#include "Font.h"

Font::Font(Render::D3D::Interface* d3d)
{
	m_d3d = d3d;
}

Font::Font(Render::D3D::Interface* d3d, std::string font_name, int size, Color col)
{
	m_d3d = d3d;
	m_FontName = font_name;
	m_Color = col;
	m_Size = size;

	Create();
}

void Font::SetFont(std::string font_name)
{
	m_FontName = font_name;	
}

void Font::SetSize(int size)
{
	m_Size = size;
}

void Font::SetColor(Color col)
{
	m_Color = col;
}

LPD3DXFONT* Font::Create()
{
	D3DXCreateFont(d3d->m_d3ddev,    // the Direct3D Device
				   m_Size, 0,    // font size twenty with the default width
				   NULL, // normal font weight
				   1,    // no mipmap levels
				   NULL,    // not italic
				   DEFAULT_CHARSET,    // default character set
				   OUT_DEFAULT_PRECIS,    // default precision
				   DEFAULT_QUALITY,    // default quality
				   DEFAULT_PITCH || FF_DONTCARE,    // more defaults...
				   m_FontName.c_str(),    // typeface "Arial"
				   &m_Font);    // address of the font object created abovev

	return &m_Font;
}