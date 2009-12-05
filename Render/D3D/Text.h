#include "D3D.h"
#include <string>

namespace Render {


	class Text
	{
	public:
		struct Position
		{
			int x;
			int y;
		};

		Text(D3D* d3d);
		void Render();
		void Render(int length);
		void SetText(std::string text);
		std::string GetText();
		void SetFont(std::string font_name, int font_size, int font_weight, bool italic);
		void SetPos(int x, int y);
		Position GetPos();
	private:
		D3D* m_d3d;
		LPD3DXFONT m_Font;
		std::string m_Text;

		int m_pos_x;
		int m_pos_y;
	};
}