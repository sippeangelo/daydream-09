#ifndef SPRITE_H
#define SPRITE_H

#include "Interface.h"
#include "../../Engine/Color.h"
#include "../../Engine/Vector.h"
#include <string>

namespace Render { namespace D3D {
	class Sprite
	{
	public:
		Sprite(Interface* d3d);
		void SetTexture(std::string file);
		void SetPos(Engine::Vector vec);
		void SetPos(float x, float y);
		void SetPos(float x, float y, float z);
		void SetCenter(Engine::Vector vec);
		void SetCenter(float x, float y);
		void SetCenter(float x, float y, float z);
		void SetColor(Color col);
		void SetColor(int r, int g, int b, int a);
		void SetColor(D3DCOLOR col);
		void Render();

	private:
		LPDIRECT3DTEXTURE9 m_Texture;
		D3DXVECTOR3 m_Center;
		D3DXVECTOR3 m_Position;
		D3DCOLOR m_Color;
		Interface* m_d3d;
	};
}}

#endif