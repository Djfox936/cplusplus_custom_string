#pragma once
#include <iostream>
using namespace std;

class CVector
{
	friend ostream &operator<<(ostream& output, const CVector& vec);

public:
	CVector();
	CVector(const CVector &vec);
	~CVector();
	size_t getSize() const;
	void resize(size_t , char c);
	size_t getCapacity() const;
	void reserve(size_t);
	void shrink_to_fit();
	void clear();
	bool empty() const;
	char& front();
	char& back();
	void push_back(char c);
	void pop_back();//okay
	
	char& operator[] (size_t pos);
	char operator[] (size_t pos) const;
	bool operator==(const CVector &str) const;
	bool operator!=(const CVector &str) const;
private:
	size_t size;
	size_t capacity;
	char *sPtr;
};