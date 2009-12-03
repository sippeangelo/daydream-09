#include "BaseEntity.h"

BaseEntity::BaseEntity()
{
	BaseEntity("BaseEntity");
}

BaseEntity::BaseEntity(std::string classname)
{
	m_ClassName = classname;

	m_Position.x = 0;
	m_Position.y = 0;
	m_Position.z = 0;
}

int BaseEntity::AddChild(BaseEntity* child)
{
	m_Children.push_back(child);

	return 0;
}

std::string BaseEntity::GetClass()
{
	return m_ClassName;
}

Position BaseEntity::GetPos()
{
	return m_Position;
}

void BaseEntity::SetPos(float x, float y, float z)
{
	m_Position.x = x;
	m_Position.y = y;
	m_Position.z = z;
}

void BaseEntity::SetPos(Position pos)
{
	m_Position = pos;
}