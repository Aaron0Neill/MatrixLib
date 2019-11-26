#pragma once

#include <math.h>

class MyVector3f
{
public:
	MyVector3f();
	MyVector3f(float x, float y, float z);

	float length() const;
	float lenghtSquared() const;
	MyVector3f unitVector() const;
	void normalise();
	float dotProduct(MyVector3f vec)const;

	MyVector3f operator+(MyVector3f vec)const;
	MyVector3f operator*(MyVector3f vec)const;
	MyVector3f operator-()const;



private:
	float m_x;
	float m_y;
	float m_z;
};

