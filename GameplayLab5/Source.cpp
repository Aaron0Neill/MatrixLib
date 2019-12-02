
#include "Matrix3f.h"

int main()
{
	double PI = 3.14159265359;
	//---------------------------------------------
	// matrix addition
	Matrix3f answer{ 1,2,3,4,5,6,7,8,9 };
	Matrix3f additionMatrix{ 9,8,7,6,5,4,3,2,1 };
	answer = answer + additionMatrix;
	//answer should be (10,10,10,10,10,10,10,10,10)
	std::cout << "----------------------------------------\n";
	std::cout << answer.toString() << std::endl;
	std::cout << "Addition Matrix\n";
	std::cout << "----------------------------------------\n";
	//---------------------------------------------
	// matrix subtraction
	Matrix3f subtractionMatrix{ 3,5,1,2,6,7,8,5,9 };
	answer = answer - subtractionMatrix;
	//answer should be (7,5,9,8,4,3,2,5,1)
	std::cout << "----------------------------------------\n";
	std::cout << answer.toString() << std::endl;
	std::cout << "subtraction Matrix\n";
	std::cout << "----------------------------------------\n";
	//---------------------------------------------
	// matrix and matrix multiplication
	answer = { 1,2,3,4,5,6,7,8,9 };
	Matrix3f multiplicationMatrix{ 9,8,7,6,5,4,3,2,1 };
	answer = answer * multiplicationMatrix;
	//answer should be (30,24,18,84,69,54,138,114,90)
	std::cout << "----------------------------------------\n";
	std::cout << answer.toString() << std::endl;
	std::cout << "multiplication by another matrix\n";
	std::cout << "----------------------------------------\n";
	//---------------------------------------------
	// matrix and vector multiplication
	MyVector3f multiplicationVector{ 2,4,6 };
	multiplicationVector = answer * multiplicationVector;
	std::cout << "----------------------------------------\n";
	std::cout << multiplicationVector.toString() << std::endl;
	std::cout << "multiplication by a vector\n";
	std::cout << "----------------------------------------\n";
	//---------------------------------------------
	// Scalar multiply
	multiplicationMatrix = { 1,2,3,4,5,6,7,8,9 };
	double scalar = 3.0;
	multiplicationMatrix = multiplicationMatrix * scalar;
	//expected answer = (3,6,9,12,15,18,21,24,27)
	std::cout << "----------------------------------------\n";
	std::cout << multiplicationMatrix.toString() << std::endl;
	std::cout << "matrix multiplied by a scalar\n";
	std::cout << "----------------------------------------\n";
	//---------------------------------------------
	// matrix determinant
	Matrix3f determinant{ 10,12.3,15,23,6,4,3,6,7 };
	double detAns = determinant.determinant();
	std::cout << "----------------------------------------\n";
	std::cout << detAns << std::endl;
	std::cout << "determinant of a martix \n";
	std::cout << "----------------------------------------\n";
	//---------------------------------------------
	// matrix inverse
	Matrix3f inverseMatrix{ 4,6,-5,-1,3,7,2,-9,8 };
	answer = inverseMatrix.inverse();
	std::cout << "----------------------------------------\n";
	std::cout << answer.toString() << std::endl;
	std::cout << "inverse of a martix \n";
	std::cout << "----------------------------------------\n";
	//---------------------------------------------
	// matrix Row 
	Matrix3f testMatrix{ 1,2,3,4,5,6,7,8,9 };
	MyVector3f rowOne = testMatrix.row(0);
	MyVector3f rowTwo = testMatrix.row(1);
	MyVector3f rowThree = testMatrix.row(2);
	std::cout << "----------------------------------------\n";
	std::cout << rowOne.toString() << std::endl;
	std::cout << rowTwo.toString() << std::endl;
	std::cout << rowThree.toString() << std::endl;
	std::cout << "martix Row Function \n";
	std::cout << "----------------------------------------\n";

	//---------------------------------------------
	// matrix Col
	MyVector3f colOne = testMatrix.column(0);
	MyVector3f colTwo = testMatrix.column(1);
	MyVector3f colThree = testMatrix.column(2);
	std::cout << "----------------------------------------\n";
	std::cout << colOne.toString() << std::endl;
	std::cout << colTwo.toString() << std::endl;
	std::cout << colThree.toString() << std::endl;
	std::cout << "martix Column Function \n";
	std::cout << "----------------------------------------\n";
	//---------------------------------------------
	// rotation Matrix along Z-axis
	Matrix3f rotationMatrix{ 1,2,3,
							  4,5,6,
							  7,8,9 };
	rotationMatrix = rotationMatrix * Matrix3f::rotateZ(PI);
	std::cout << "----------------------------------------\n";
	std::cout << rotationMatrix.toString() << std::endl;
	std::cout << "martix Rotation through Z-axis \n";
	std::cout << "----------------------------------------\n";
	//---------------------------------------------
	// rotation Matrix along Y-axis
	rotationMatrix = { 1,2,3,4,5,6,7,8,9 };
	rotationMatrix = rotationMatrix * Matrix3f::rotateY(PI / 2.0);
	std::cout << "----------------------------------------\n";
	std::cout << rotationMatrix.toString() << std::endl;
	std::cout << "martix Rotation through Y-axis \n";
	std::cout << "----------------------------------------\n";
	//---------------------------------------------
	// rotation Matrix along X-axis
	rotationMatrix = { 1,2,3,4,5,6,7,8,9 };
	rotationMatrix = rotationMatrix * Matrix3f::rotateX(PI / 4.0);
	std::cout << "----------------------------------------\n";
	std::cout << rotationMatrix.toString() << std::endl;
	std::cout << "martix Rotation through X-axis \n";
	std::cout << "----------------------------------------\n";
	//---------------------------------------------
	// Translation
	MyVector3f translationVector{ 5.0,6.0,0 };
	MyVector3f translationPoint{ 2.0,2.0,1.0 };
	Matrix3f translationMatrix;
	translationMatrix = translationMatrix.translate(translationVector);
	translationPoint = translationMatrix * translationPoint;
	std::cout << "----------------------------------------\n";
	std::cout << translationPoint.toString() << std::endl;
	std::cout << "translation Matrix Test \n";
	std::cout << "----------------------------------------\n";
	//---------------------------------------------
	// Scalar
	Matrix3f scalaingMatrix;
	Matrix3f matrixToBeScaled{ 3,5,1,2,4,7,9,8,6 };
	scalaingMatrix = scalaingMatrix.scale(2);
	matrixToBeScaled = matrixToBeScaled * scalaingMatrix;
	//answer should be (6,10,2,4,8,14,18,16,12)
	std::cout << "----------------------------------------\n";
	std::cout << matrixToBeScaled.toString() << std::endl;
	std::cout << "Matrix Scalaing Test \n";
	std::cout << "----------------------------------------\n";

}