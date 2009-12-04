#include "D3D.h"
#include <string>

namespace Render {
	class Text
	{
	public:
		Text(D3D* d3d);
		void Render();
		void Render(int length);
		void SetText(std::string text);
		std::string GetText();
		void SetFont(std::string font_name, int font_size, int font_weight, bool italic);
	private:
		D3D* m_d3d;
		LPD3DXFONT m_Font;
		std::string m_Text;
	};
}