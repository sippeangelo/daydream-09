#include "Text.h"

using namespace Render::D3D;

Text::Text(Interface* d3d)
{
	// Store the pointer to our D3D class
	m_d3d = d3d;

	SetFont("Courier", 20, FW_BOLD, false);

	m_pos_x = 0;
	m_pos_y = 0;
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
	SetRect(&textbox, m_pos_x, m_pos_y, 640, 480); 

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

void Text::SetPos(int x, int y)
{
	m_pos_x = x;
	m_pos_y = y;
}

Text::Position Text::GetPos()
{
	Position pos;
	pos.x = m_pos_x;
	pos.y = m_pos_y;

	return pos;
}