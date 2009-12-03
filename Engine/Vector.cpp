#include "Vector.h"

namespace Engine
{

Vector operator+(const Vector &vec1, const Vector &vec2)
{
	return Vector(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z);
}

Vector operator-(const Vector &vec1, const Vector &vec2)
{
	return Vector(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
}

Vector operator-(const Vector &vec)
{
	return Vector(-vec.x, -vec.y, -vec.z);
}

Vector operator*(const Vector &vec, const float mul)
{
	return Vector(vec.x * mul, vec.y * mul, vec.z * mul);
}

Vector operator*(const float mul, const Vector &vec)
{
	return Vector(vec.x * mul, vec.y * mul, vec.z * mul);
}

Vector operator/(const Vector &vec, const float div)
{
	return Vector(vec.x / div, vec.y / div, vec.z / div);
}

Vector operator/(const float div, const Vector &vec)
{
	return Vector(vec.x / div, vec.y / div, vec.z / div);
}

bool operator>(const Vector &vec1, const Vector &vec2)
{
	return (vec1.x > vec2.x && vec1.y > vec2.y && vec1.z > vec2.z);
}

bool operator>=(const Vector &vec1, const Vector &vec2)
{
	return (vec1.x >= vec2.x && vec1.y >= vec2.y && vec1.z >= vec2.z);
}

bool operator<(const Vector &vec1, const Vector &vec2)
{
	return (vec1.x < vec2.x && vec1.y < vec2.y && vec1.z < vec2.z);
}

bool operator<=(const Vector &vec1, const Vector &vec2)
{
	return (vec1.x <= vec2.x && vec1.y <= vec2.y && vec1.z <= vec2.z);
}

bool operator==(const Vector &vec1, const Vector &vec2)
{
	return (vec1.x == vec2.x && vec1.y == vec2.y && vec1.z == vec2.z);
}

bool operator!=(const Vector &vec1, const Vector &vec2)
{
	return !(vec1 == vec2);
}

bool operator!(const Vector &vec)
{
	return (vec.x == 0.0f && vec.y == 0.0f && vec.z == 0.0f);
}

std::ostream& operator<<(std::ostream &out, Vector &vec)
{
	out << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
	return out;
}

Vector &Vector::operator+=(Vector &vec)
{
	this->x += vec.x;
	this->y += vec.y;
	this->z += vec.z;

	return *this;
}

Vector &Vector::operator+=(float add)
{
	this->x += add;
	this->y += add;
	this->z += add;

	return *this;
}

Vector &Vector::operator-=(Vector &vec)
{
	this->x -= vec.x;
	this->y -= vec.y;
	this->z -= vec.z;

	return *this;
}

Vector &Vector::operator-=(float sub)
{
	this->x -= sub;
	this->y -= sub;
	this->z -= sub;

	return *this;
}

/*

	FUNCTIONLAND

*/

Vector::Vector()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;	
}

Vector::Vector(float x, float y)
{
	this->x = x;
	this->y = y;
	this->z = 0;
}

Vector::Vector(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

float Vector::Dot(Vector vec)
{
	return (this->x * vec.x + this->y * vec.y + this->z * vec.z);
}

Vector Vector::Cross(Vector vec)
{
	return Vector((this->y * vec.z - this->z * vec.y), (this->z * vec.x - this->x * vec.z), (this->x * vec.y - this->y * vec.x));
}

float Vector::Magnitude()
{
	return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

Vector Vector::Normalize()
{
	float magnitude = this->Magnitude();

	return Vector(this->x / magnitude, this->y / magnitude, this->z / magnitude);
}

Vector::~Vector()
{

}

}