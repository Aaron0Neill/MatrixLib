#pragma once

#include "MyVector3f.h"

class Quaternion
{
	double x, y, z, w;

public:
	Quaternion();
	Quaternion(double t_w, double t_x, double t_y, double t_z);
	Quaternion(double t_w, MyVector3f vec);
	~Quaternion();

	std::string toString();
	std::string operator<<(Quaternion q);

	double lengthSquared()const;
	double length()const;
	Quaternion unitVector()const;
	void normalize();
	Quaternion conjugate()const;

	Quaternion operator-()const;
	Quaternion operator-(Quaternion const rhs)const;
	Quaternion operator+(Quaternion const rhs)const;
	Quaternion operator*(Quaternion const rhs)const;
	Quaternion operator*(double const s)const;
	Quaternion operator*(float const s)const;
	Quaternion operator*(int const s)const;

	void fromAxisAngle(MyVector3f axis, double angleRadians);
	Quaternion multiply(Quaternion q)const;
	MyVector3f rotate(MyVector3f pt, int angle);
};

