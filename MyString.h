#pragma once
#include <iostream>
#include"CVector.h"
using namespace std;

class MyString : public CVector
{
	friend MyString operator+ (const char*, const MyString&);
	
public:
	MyString();
	MyString(const MyString &);
	MyString(const MyString &, size_t, size_t);
	MyString(const char *);
	~MyString();
	MyString& append(const MyString &);
	MyString substr(size_t , size_t) const;
	MyString& insert(size_t , const MyString &);
	MyString& insert(size_t, const MyString &, size_t, size_t);
	MyString& erase(size_t, size_t);
	size_t find(const MyString &,size_t=0) const;
	size_t find_first_of(const MyString &,size_t=0) const;
	MyString operator+ (const char*) const;
	MyString operator+ (const MyString&)const;
	MyString& operator= (const MyString& );
	MyString& operator= (const char* );
	static const size_t msize = 999;
	
}; // end class MyString
