#include "Vector.h"

float dot;

Vector::Vector()
{
	currentIndex = 0;
	arrSize = 0;
}

Vector::Vector(int size)
{
	//TODO: Dynamic allocate array by the size  
	arr = new float[size];
	currentIndex = 0;
	arrSize = size;
}


Vector::~Vector() {};

void Vector::AddNumbertoArr(float number)
{
	//TODO: Input number into array
	arrSize++;
	float* st;
	st = new float[arrSize - 1];

	for (int i = 0; i < arrSize - 1; i++)
		st[i] = arr[i];

	arr = new float[arrSize];
	for (int i = 0; i < arrSize - 1; i++)
		arr[i] = st[i];
	arr[arrSize - 1] = number;
}

int Vector::getSize()
{
	//TODO: Return the array size
	return arrSize;
}

float Vector::length()
{
	//TODO: Compute the length of vector and return it
	float total = 0;
	for (int i = 0; i < arrSize; i++)
		total += pow(arr[i], 2);
	return sqrt(total);
}

Vector Vector::normalize()
{
	//TODO: Normalize the vector and return it
	float num = length();
	Vector nv(arrSize);
	for (int i = 0; i < arrSize; i++)
		nv.arr[i] = arr[i] / num;
	return nv;
}


Vector & Vector::operator+(Vector v)
{
	//TODO: Overload the plus operator +. 
	//Return the result of v1 + v2
	for (int i = 0; i < arrSize; i++)
		arr[i] = arr[i] + v.arr[i];
	return *this;
}

Vector & Vector::operator=(Vector v)
{
	//TODO: Overload the assign operator =.
	arr = new float[v.arrSize];
	arrSize = v.arrSize;
	for (int i = 0; i < v.arrSize; i++)
	{
		arr[i] = v.arr[i];
	}
	return (*this);
}

Vector & Vector::operator-(Vector v)
{
	//TODO: Overload the subtract operator -.
	// the result of v1 - v2
	for (int i = 0; i < arrSize; i++)
		arr[i] = arr[i] - v.arr[i];
	return *this;
}


float & Vector::operator*(Vector v)
{   
	//TODO: Overload the operator *  dot product.
	// the dot product of two vector
	dot = 0;
	for (int i = 0; i < arrSize; i++)
		dot += arr[i] * v.arr[i];
	return dot;
}

ifstream & operator>>(ifstream & in, Vector & v)
{
	
	//TODO: Overload the >> operator.
	//Read the input.txt file and store vector in v
	int size;
	in >> size;
	v = Vector(size);
	for (int i = 0; i < v.arrSize; i++)
		in >> v.arr[i];
	return in;
}

ostream & operator<<(ostream & out, const Vector & v)
{
	//TODO: Overload the << operator.
	//Output the vector v
	out << "[";
	for (int i = 0; i < v.arrSize; i++)
	{
		out << v.arr[i];
		if (i != v.arrSize - 1) out << ",";
	}
	out << "]";
	return out;
}
