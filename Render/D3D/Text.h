#ifndef TEXT_H
#define TEXT_H

#include "Interface.h"
#include "Font.h"
#include <string>
#include "../../Engine/Color.h"

namespace Render { namespace D3D {
	class Text
	{
	public:
		struct Position
		{
			int x;
			int y;
		};

		Text(Interface* d3d);
		void Render();
		void Render(int length);
		void SetText(std::string text);
		std::string GetText();
		void SetFont(Font font);
		void SetPos(int x, int y);
		Position GetPos();
	private:
		Interface* m_d3d;
		Font m_Font;
		std::string m_Text;

		int m_pos_x;
		int m_pos_y;
	};
} }

#endif