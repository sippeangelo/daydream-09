#ifndef VECTOR_H
#define VECTOR_H

#include <ostream>
#include <math.h>
//#include <d3d9.h> // HACK: Should not depend on DirectX
//#include <d3dx9core.h> // HACK: Should not depend on DirectX

namespace Engine
{

class Vector
{
public:
	// Overloaded operators
	friend Vector operator+(const Vector &vec1, const Vector &vec2);
	friend Vector operator-(const Vector &vec1, const Vector &vec2);
	friend Vector operator-(const Vector &vec);
	friend Vector operator*(const Vector &vec, const float mul);
	friend Vector operator*(const float mul, const Vector &vec);
	friend Vector operator/(const Vector &vec, const float div);
	friend Vector operator/(const float div, const Vector &vec);
	friend bool operator>(const Vector &vec1, const Vector &vec2);
	friend bool operator>=(const Vector &vec1, const Vector &vec2);
	friend bool operator<(const Vector &vec1, const Vector &vec2);
	friend bool operator<=(const Vector &vec1, const Vector &vec2);
	friend bool operator==(const Vector &vec1, const Vector &vec2);
	friend bool operator!=(const Vector &vec1, const Vector &vec2);
	friend bool operator!(const Vector &vec);
	friend std::ostream& operator<<(std::ostream &out, Vector &vec);
	Vector &operator+=(Vector &vec);
	Vector &operator+=(float add);
	Vector &operator-=(Vector &vec);
	Vector &operator-=(float sub);
	//Vector &operator=(D3DXVECTOR3 &vec); // HACK: Should not depend on DirectX
 
	// Functions
	Vector();
	Vector(float x, float y);
	Vector(float x, float y, float z);
	~Vector();

	float Dot(Vector vec);
	Vector Cross(Vector vec);
	float Magnitude();
	Vector Normalize();

	// Axises
	float x;
	float y;
	float z;
};

}

#endif