#pragma once
#include <iostream>
#include <fstream>


using namespace std;

class Vector
{
private:
	float *arr;
	int currentIndex;
	int arrSize;
public:
	//constructor
	Vector();
	Vector(int size);
	~Vector();

	//setter
	void AddNumbertoArr(float number);

	//getter
	int getSize();

	float length();
	Vector normalize();

	//overload 
	Vector &operator +(Vector v);
	Vector &operator =(Vector v);
	Vector &operator -(Vector v);

	//dot product
	float &operator *(Vector v);

	//input output overload
	friend ifstream& operator >> (ifstream& in, Vector &v);
	friend ostream& operator << (ostream& out, const Vector &v);


};