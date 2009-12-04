#include "Text.h"

using namespace Render;

Text::Text(D3D* d3d)
{
	// Store the pointer to our D3D class
	m_d3d = d3d;

	SetFont("Courier", 20, FW_BOLD, false);
}

void Text::SetFont(std::string font_name, int font_size, int font_weight, bool italic)
{
	D3DXCreateFont(m_d3d->m_d3ddev,    // the Direct3D Device
				   font_size, 0,    // font size twenty with the default width
				   font_weight, // normal font weight
				   1,    // no mipmap levels
				   italic,    // not italic
				   DEFAULT_CHARSET,    // default character set
				   OUT_DEFAULT_PRECIS,    // default precision
				   DEFAULT_QUALITY,    // default quality
				   DEFAULT_PITCH || FF_DONTCARE,    // more defaults...
				   font_name.c_str(),    // typeface "Arial"
				   &m_Font);    // address of the font object created above
}

void Text::Render()
{
	Render(NULL);
}

void Text::Render(int length)
{
	if (length == NULL)
		length = strlen(m_Text.c_str());

	static RECT textbox; 
	SetRect(&textbox, 0, 0, 640, 480); 

	m_Font->DrawTextA(NULL, m_Text.c_str(), length, &textbox, NULL, D3DCOLOR_ARGB(255, 0, 255, 0));
}

void Text::SetText(std::string text)
{
	m_Text = text;
}

std::string Text::GetText()
{
	return m_Text;
}