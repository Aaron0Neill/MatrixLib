#include "Quaternion.h"

Quaternion::Quaternion() : 
	w(0),
	x(0),
	y(0),
	z(0)
{
}

Quaternion::Quaternion(double t_w, double t_x, double t_y, double t_z) : 
	w(t_w),
	x(t_x),
	y(t_y),
	z(t_z)
{
}

Quaternion::Quaternion(double t_w, MyVector3f vec) : 
	w(t_w),
	x(vec.getX()),
	y(vec.getY()),
	z(vec.getZ())
{
}

Quaternion::~Quaternion()
{
}

std::string Quaternion::toString()
{
	return std::string("w: " + std::to_string(w) + " x: " + std::to_string(x) + " y: " + std::to_string(y) + " z: " + std::to_string(z));
}

std::string Quaternion::operator<<(Quaternion q)
{
	return q.toString();
}

double Quaternion::lengthSquared()const
{
	return (w * w + x*x + y*y + z*z);
}

double Quaternion::length()const
{
	return sqrt(this->lengthSquared());
}

Quaternion Quaternion::unitVector()const
{
	double len = this->lengthSquared();
	if (len > 0)
	{
		len = sqrt(len);
		return Quaternion(w / len, x / len, y / len, z / len);
	}
	return Quaternion(1,0,0,0);
}

void Quaternion::normalize()
{
	double l = this->length();
	if (l > 0)
	{
		l = sqrt(l);
		w /= l;
		x /= l;
		y /= l;
		z /= l;
	}
}

Quaternion Quaternion::conjugate() const
{
	return Quaternion(w,-x,-y,-z);
}

Quaternion Quaternion::operator-() const
{
	return Quaternion(-w,-x,-y,-z);
}

Quaternion Quaternion::operator-(Quaternion const rhs) const
{
	return Quaternion(w - rhs.w, x - rhs.x, y - rhs.y, z - rhs.z);
}

Quaternion Quaternion::operator+(Quaternion const rhs) const
{
	return Quaternion(w + rhs.w, x + rhs.x, y + rhs.y, z + rhs.z);
}

Quaternion Quaternion::operator*(Quaternion const rhs) const
{
	return this->multiply(rhs);
}

Quaternion Quaternion::operator*(double const s) const
{
	return Quaternion(w*s, x*s, y*s, z*s);
}

Quaternion Quaternion::operator*(float const s) const
{
	return this->operator*(static_cast<double>(s));
}

Quaternion Quaternion::operator*(int const s) const
{
	return this->operator*(static_cast<double>(s));
}

void Quaternion::fromAxisAngle(MyVector3f axis, double angleRadians)
{
	double l = axis.lenghtSquared();
	if (l > 0)
	{
		l = sqrt(l);
		double ca = cos(angleRadians / 2.0);
		double sa = sin(angleRadians / 2.0);
		x = axis.getX() / l * sa;
		y = axis.getY() / l * sa;
		z = axis.getZ() / l * sa;
		w = ca;
	}
	else
	{
		w = 1; w = 0; y = 0; z = 0;
	}
}

Quaternion Quaternion::multiply(Quaternion q)const
{
	double nw = q.w * w - q.x * x - q.y * y - q.z * z;
	double nx = q.w * x + q.x * w + q.y * z - q.z * y;
	double ny = q.w * y + q.y * w + q.z * x - q.x * z;
	double nz = q.w * z + q.z * w + q.x * y - q.y * x;
	return Quaternion(nw,nx,ny,nz);
}

MyVector3f Quaternion::rotate(MyVector3f pt, int angle)
{
	Quaternion axis = unitVector();
	double angleRad = 3.14159 / 180 * angle;
	double sa = sin(angleRad / 2.0);
	Quaternion rotate = { cos(angleRad / 2.0), sa * axis.x, sa * axis.y, sa * axis.z };
	Quaternion conj = rotate.conjugate();
	Quaternion qNode = { 0,pt.getX(),pt.getY(),pt.getZ() };
	qNode = rotate * qNode * conj;
	return MyVector3f(qNode.x,qNode.y,qNode.z);
}
