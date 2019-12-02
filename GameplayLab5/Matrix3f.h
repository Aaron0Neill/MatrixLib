#pragma once

#include "MyVector3f.h"


class Matrix3f
{
	float m_a11;
	float m_a12;
	float m_a13;
	float m_a21;
	float m_a22;
	float m_a23;
	float m_a31;
	float m_a32;
	float m_a33;
	
public:
	Matrix3f();
	Matrix3f(float a1, float a2, float a3,
		float b1, float b2, float b3, 
		float c1, float c2, float c3);
	Matrix3f(MyVector3f a, MyVector3f b, MyVector3f c);

	Matrix3f transpose(const Matrix3f m)const;
	float determinant(const Matrix3f m)const;
	MyVector3f row(int row)const;
	MyVector3f column(int col)const;
	Matrix3f inverse(const Matrix3f m)const;
	Matrix3f rotation(float angle)const;
	Matrix3f translate(float dx, float dy)const;
	Matrix3f rotateX(int angle);

	Matrix3f operator *(const MyVector3f vec)const;
	Matrix3f operator *(const float scalar)const;
	Matrix3f operator *(const Matrix3f m)const;
	Matrix3f operator +(const Matrix3f m)const;
	Matrix3f operator -(const Matrix3f m)const;
	Matrix3f operator -()const;
	

};

