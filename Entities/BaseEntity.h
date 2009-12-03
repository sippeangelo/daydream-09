#ifndef BASEENTITY_H
#define BASEENTITY_H

#include <iostream>
#include <vector>
#include <string>

struct Position
{
	float x;
	float y;
	float z;
};

class BaseEntity
{
public:
	BaseEntity();
	BaseEntity(std::string classname);

	std::vector<BaseEntity*> m_Children;
	BaseEntity* m_Parent;
	int AddChild(BaseEntity* child);

	std::string GetClass();

	Position GetPos();
	void BaseEntity::SetPos(float x, float y, float z);
	void BaseEntity::SetPos(Position pos);
private:
	std::string m_ClassName;

	Position m_Position;
};

#endif