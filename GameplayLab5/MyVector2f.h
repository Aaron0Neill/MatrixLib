#pragma once
/// <summary>
/// Create a personal vector class
/// </summary>
 
#include <math.h>
#include <string>

class MyVector2f
{
public:
	MyVector2f();
	MyVector2f(float x, float y);

	float length() const;
	float lengthSquared() const;
	MyVector2f unitVector() const;
	void normalise();
	float dotProduct(const MyVector2f vector) const;

	void operator* (double scalar);
	MyVector2f operator +(const MyVector2f vector) const;
	MyVector2f operator -(const MyVector2f vector) const;
	MyVector2f operator -=(const MyVector2f vector) const;
	MyVector2f operator +=(const MyVector2f vector) const;
	MyVector2f operator *(const double scalar) const;

	bool operator == (const MyVector2f vector)const;
	bool operator != (const MyVector2f vector)const;

	MyVector2f operator -() const;

	std::string toString() const;
	std::string operator<<(const MyVector2f vec)const;
	

private:
	float m_x;
	float m_y;
};
