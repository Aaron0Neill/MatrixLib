#include "MyVector3f.h"

MyVector3f::MyVector3f() : 
	m_x(0),
	m_y(0),
	m_z(0)
{
}

MyVector3f::MyVector3f(float x, float y, float z) : 
	m_x(x),
	m_y(y),
	m_z(z)
{
}

float MyVector3f::length() const
{
	return sqrt(this->lenghtSquared());
}

float MyVector3f::lenghtSquared() const
{
	return (m_x * m_x + m_y * m_y + m_z * m_z);
}

MyVector3f MyVector3f::unitVector() const
{
	float magnitude = this->length();
	if (magnitude > 0)
		return MyVector3f(m_x / magnitude, m_y / magnitude, m_z / magnitude);
	else
		return MyVector3f();
}

void MyVector3f::normalise()
{
	float magnitude = this->length();
	if (magnitude > 0)
	{
		m_x /= magnitude;
		m_y /= magnitude;
		m_z /= magnitude;
	}
}

float MyVector3f::dotProduct(MyVector3f vec) const
{
	return 0.0f;
}

MyVector3f MyVector3f::operator+(MyVector3f vec) const
{
	return MyVector3f(m_x + vec.m_x, m_y + vec.m_y, m_z + vec.m_z);
}

MyVector3f MyVector3f::operator*(MyVector3f vec) const
{
	return MyVector3f();
}

MyVector3f MyVector3f::operator-() const
{
	return MyVector3f(-m_x, -m_y, -m_z);
}
