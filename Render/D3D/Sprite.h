#ifndef SPRITE_H
#define SPRITE_H

#include "Interface.h"
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
		void Render();

	private:
		Interface* m_d3d;
		LPDIRECT3DTEXTURE9 m_Texture;
		D3DXVECTOR3 m_Center;
		D3DXVECTOR3 m_Position;
	};
}}

#endif