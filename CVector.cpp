#pragma once
#include <iostream>
#include"CVector.h"
using namespace std;

CVector::CVector()
{
	sPtr = new char[10];
	size = 0;
	capacity = 10;
	for (size_t i = 0; i < capacity; i++)//��l�Ƥ���
	{
		sPtr[i] = '\0';
	}
}

CVector::CVector(const CVector &vec) :size(vec.size), capacity(vec.capacity)
{

	sPtr = new char[size];
	for (size_t i = 0; i < size; i++)
	{
		sPtr[i] = vec.sPtr[i];
	}

}
CVector::~CVector()
{

	delete[]sPtr;
}
size_t CVector::getSize() const//okay
{
	return size;
}
void CVector::resize(size_t n, char c = '\0')//okay
{
	if (n <= size)
	{
		n = size;
	}
	else
	{
		for (size_t i = this->getSize(); i < n; i++)
		{
			this->push_back(c);
		}
	}
}
size_t CVector::getCapacity() const
{
	return capacity;
}
void CVector::reserve(size_t n = 0)//okay
{

	if (n > capacity)
	{
		char *tempptr;
		tempptr = new char[n];
		for (size_t i = 0; i < size; i++)
		{
			tempptr[i] = sPtr[i];
		}
		delete[]sPtr;
		sPtr = new char[n];
		for (size_t i = 0; i < size; i++)
		{
			sPtr[i] = tempptr[i];
		}//012345\0\0\0
		for (size_t i = size; i < n; i++)
		{
			sPtr[i] = '\0';
		}
		delete[]tempptr;
		capacity = n;
	}

}
void CVector::shrink_to_fit()//okay
{

	char *tempptr;
	tempptr = new char[size];
	for (size_t i = 0; i < size; i++)
	{
		tempptr[i] = sPtr[i];
	}
	delete[]sPtr;
	sPtr = new char[size];
	capacity = size;
	for (size_t i = 0; i < size; i++)
	{
		sPtr[i] = tempptr[i];
	}
	delete[]tempptr;



}

void CVector::clear()//okay
{
	size = 0;
	for (size_t i = 0; i < capacity; i++)//���������w�]��\0
	{
		sPtr[i] = '\0';
	}
}
bool CVector::empty() const//okay
{
	if (size == 0)
	{
		return true;
	}
	else
		return false;
}
char& CVector::front()
{

	return sPtr[0];

}

char& CVector::back()
{
	return sPtr[size - 1];

}
void CVector::push_back(char c)//
{
	if (size == capacity - 1 || size >= capacity - 1)
	{
		reserve(capacity * 2);

	}
	sPtr[size] = c;
	size++;

}
void CVector::pop_back()//okay
{
	if (size != 0)
		size--;
	sPtr[size] = '\0';
}

char& CVector::operator[] (size_t pos)//okay
{

	return sPtr[pos];

}
char CVector::operator[] (size_t pos) const//okay

{


	return sPtr[pos];

}
bool CVector::operator==(const CVector &str) const//okay
{
	if (size != str.size)
	{
		return false;
	}
	for (size_t i = 0; i < size; i++)
	{
		if (sPtr[i] != str.sPtr[i])
			return false;
	}
	return true;
}
bool CVector::operator!=(const CVector &str) const//�Q��operator == overloading�����P�_//okay
{
	if (*this == str)
	{
		return false;
	}
	else
	{
		return true;
	}
}

ostream &operator<<(ostream& output, const CVector& vec)//okay
{
	for (size_t i = 0; i < vec.getSize(); i++)
	{
		output << vec[i];
	}

	return output;
}