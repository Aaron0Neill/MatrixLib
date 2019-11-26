#include "MyVector2f.h"

MyVector2f::MyVector2f() :
	m_x(0),
	m_y(0)
{
}

MyVector2f::MyVector2f(float x, float y) : 
	m_x(x),
	m_y(y)
{
}

/// <summary>
/// gets the length of a vector by using pythagrous theorem
/// </summary>
/// <returns> the length of a vector </returns>
float MyVector2f::length() const
{
	return sqrt(this->lengthSquared());
}

/// <summary>
/// returns the lenght of the vector but squared
/// </summary>
/// <returns> the squared length of the vector </returns>
float MyVector2f::lengthSquared() const
{
	return ((m_x * m_x) + (m_y * m_y));
}

/// <summary>
/// gets the unit vector of the current instance
/// </summary>
/// <returns> the unit vector </returns>
MyVector2f MyVector2f::unitVector() const
{
	float magnitude = this->length();

	if (magnitude > 0)
		return MyVector2f(m_x / magnitude, m_y / magnitude);
	else
		return MyVector2f();
}

/// <summary>
/// change the vector so it keeps the same direction but has a magnitude of 1
/// </summary>
void MyVector2f::normalise()
{
	float magnitude = this->length();
	if (magnitude > 0)
	{
		m_x /= magnitude;
		m_y /= magnitude;
	}
}

float MyVector2f::dotProduct(MyVector2f vector) const
{
	return (m_x * vector.m_x + m_y * vector.m_y);
}

/// <summary>
/// increase the size of the vector by a given number
/// </summary>
/// <param name="scalar"> number to multiply the vector by </param>
void MyVector2f::operator*(double scalar)
{
	m_x *= scalar;
	m_y *= scalar;
}

/// <summary>
/// adds two vectors together and returns a new vector
/// </summary>
/// <param name="vector"> the vector that is being added to the current vector </param>
/// <returns> a new vector after the two were added together </returns>
MyVector2f MyVector2f::operator+(MyVector2f vector) const
{
	return MyVector2f (m_x + vector.m_x, m_y + vector.m_y);
}

/// <summary>
/// subtracts two vectors from one another
/// </summary>
/// <param name="vector"> the vector that is going to be taken from the current vector </param>
/// <returns> new vector after one is taken from the other </returns>
MyVector2f MyVector2f::operator-(MyVector2f vector) const
{
	return MyVector2f(m_x - vector.m_x, m_y - vector.m_y);
}

MyVector2f MyVector2f::operator-() const
{
	return MyVector2f(-m_x, -m_y);
}

/// <summary>
/// convert the vector into a string and return that string
/// </summary>
/// <returns> a string containing all the information on the current vector </returns>
std::string MyVector2f::toString() const
{
	return std::string("(x: " + std::to_string(m_x) + " y: " + std::to_string(m_y) + ")");
}


