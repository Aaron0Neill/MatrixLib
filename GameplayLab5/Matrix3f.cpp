#include "Matrix3f.h"

Matrix3f::Matrix3f() :
	m_a11(0.f),
	m_a12(0.f),
	m_a13(0.f),
	m_a21(0.f),
	m_a22(0.f),
	m_a23(0.f),
	m_a31(0.f),
	m_a32(0.f),
	m_a33(0.f)
{
}

Matrix3f::Matrix3f(float a1, float a2, float a3, float b1, float b2, float b3, float c1, float c2, float c3) :
	m_a11(a1),
	m_a12(a2),
	m_a13(a3),
	m_a21(b1),
	m_a22(b2),
	m_a23(b3),
	m_a31(c1),
	m_a32(c2),
	m_a33(c3)
{
}

Matrix3f::Matrix3f(MyVector3f a, MyVector3f b, MyVector3f c) : 
	m_a11(a.getX()),
	m_a12(a.getY()),
	m_a13(a.getZ()),
	m_a21(b.getX()),
	m_a22(b.getY()),
	m_a23(b.getZ()),
	m_a31(c.getX()),
	m_a32(c.getY()),
	m_a33(c.getZ())
{
}