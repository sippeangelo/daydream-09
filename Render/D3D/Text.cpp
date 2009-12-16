#include "Text.h"

using namespace Render::D3D;

Text::Text(Interface* d3d)
{
	// Store the pointer to our Interface class
	m_d3d = d3d;

	//SetFont("Courier", 20, FW_BOLD, false);
	SetFont(Font(d3d, "Courier", 20, Color(255, 255, 255)));

	m_pos_x = 0;
	m_pos_y = 0;
}

void Text::SetFont(Font font)
{
	m_Font = font.GetD3D();
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

	m_Font->DrawTextA(NULL, m_Text.c_str(), length, &textbox, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
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