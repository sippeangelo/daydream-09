#include "Sprite.h"

using namespace Render::D3D;

Sprite::Sprite(Interface* d3d)
{
	// Store the pointer to our Interface class
	m_d3d = d3d;
	
	if (d3d->m_d3dspt == NULL)
	{
		D3DXCreateSprite(d3d->m_d3ddev, &d3d->m_d3dspt);
	}

	m_Position = D3DXVECTOR3(0, 0, 0);
	m_Center = D3DXVECTOR3(0, 0, 0);
}

void Sprite::SetTexture(std::string file)
{
	D3DXCreateTextureFromFile(m_d3d->m_d3ddev, file.c_str(), &m_Texture);
}

/*
	Sprite::SetPos(Engine::Vector vec)
*/
void Sprite::SetPos(Engine::Vector vec)
{
	m_Position = D3DXVECTOR3(vec.x, vec.y, vec.z);
}
void Sprite::SetPos(float x, float y)
{
	m_Position = D3DXVECTOR3(x, y, 0);
}
void Sprite::SetPos(float x, float y, float z)
{
	m_Position = D3DXVECTOR3(x, y, z);
}

/*
	Sprite::SetCenter(Engine::Vector vec)
*/
void Sprite::SetCenter(Engine::Vector vec)
{
	m_Center = D3DXVECTOR3(vec.x, vec.y, vec.z);
}
void Sprite::SetCenter(float x, float y)
{
	m_Center = D3DXVECTOR3(x, y, 0);
}
void Sprite::SetCenter(float x, float y, float z)
{
	m_Center = D3DXVECTOR3(x, y, z);
}

void Sprite::Render()
{
	m_d3d->m_d3dspt->Draw(m_Texture, NULL, &m_Center, &m_Position, D3DCOLOR_XRGB(255, 255, 255));  // draw it!
}