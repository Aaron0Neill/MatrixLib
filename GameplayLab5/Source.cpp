
#include "Matrix3f.h"
#include "Quaternion.h"

int main()
{
	double PI = 3.14159265359;

	MyVector3f vec1{ 0 , 2,-5 };
	MyVector3f vec2{-2 ,-2,-5 };
	MyVector3f vec3{ 2 ,-2,-5 };

	//v1 len
	std::cout << vec1.length() << std::endl;
	//v2 len2
	std::cout << vec2.lenghtSquared() << std::endl;
	//v3  rotateZ 23.21
	vec3 = Matrix3f::rotateZ(-23.21) * vec3;
	std::cout << vec3.toString() << std::endl;
	//v4 v3 rotated z by 5
	vec3 = { 2,-2,-5 };
	Quaternion rotation{0,0,0,1};
	vec3 = rotation.rotate(vec3, 23.21);
	std::cout << vec3.toString() << std::endl;
}