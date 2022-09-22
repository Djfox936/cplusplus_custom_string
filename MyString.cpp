#pragma once
#include <iostream>
#include"MyString.h"
using namespace std;

	MyString::MyString() : CVector()
	{

	}
	// Constructs an empty string, with a length of zero characters. 
	// *default capacity = 10

	MyString::MyString(const MyString &str)
		// Constructs a copy of "str". (copy constructor)
	{
		*this = str;

	}
	MyString::MyString(const MyString &str, size_t pos, size_t len = msize) // (substring constructor)
	// Copies the portion of str that begins at the character position "pos" and spans "len" characters 
	// (or until the end of str, if either str is too short or if len is string::msize).
	{
		MyString temp = str.substr(pos, len);
		for (size_t i = 0; i < temp.getSize(); i++)
		{
			this->push_back(temp[i]);
		}
		*this = temp;
	}
	MyString::MyString(const char *s)
		// Copies the array of character (C-string) pointed by s.
		// The char *s is a pointer to a null-terminated sequence of characters. (all following char* are the same/)
		// The sequence is copied as the new value for the string.
	{

		*this = s;

	}
	MyString::~MyString()
		// Destroys the string object.
	{
		this->clear();
	}
	static const size_t msize = 999;
	//Note: maximum size.

	MyString& MyString::append(const MyString &str)
		// Appends a str on the tail of current MyString. 
		// *Return the reference of itself
	{
		for (size_t i = 0; i < str.getSize(); i++)
		{
			this->push_back(str[i]);
		}
		return *this;
	}

	MyString MyString::substr(size_t pos = 0, size_t len = msize) const//okay
	// The substring is the portion of the object that starts at character position pos and spans len characters 
	// (or until the end of the string, whichever comes first).
	// *Returns a newly constructed string object with its value initialized to a copy of a substring of this object.
	{//HELLOC++ 
	 //01234567  SIZE=8   3,3
		MyString temp;
		size_t last;
		if (pos + len > this->getSize())
		{
			last = this->getSize();
		}
		else
		{
			last = pos + len;//LAST=6
		}
		for (size_t i = pos; i < last; i++)
		{
			temp.push_back((*this)[i]);
		}
		return temp;
	}
	MyString& MyString::insert(size_t pos, const MyString &str)
		// Inserts a copy of a str at "pos".
		// example: str = "to be question", str2 = "the "
		//                 0123456789
		// str.insert(6,str2); 
		// = to be (the )question = to be the question
		// *Return the reference of itself
	{
		MyString temp;
		temp = this->substr(pos);
		for (size_t i = this->getSize() - 1; i >= pos; i--)
		{
			this->pop_back();
		}
		for (size_t i = 0; i < str.getSize(); i++)
		{
			this->push_back(str[i]);
		}
		for (size_t i = 0; i < temp.getSize(); i++)
		{
			this->push_back(temp[i]);
		}
		return *this;
	}
	MyString& MyString::insert(size_t pos, const MyString &str, size_t subpos, size_t sublen)
		// Inserts a copy of a substring of str at "pos". The substring is the portion of "str" that
		// begins at the character position subpos and spans sublen characters (or until the end of str).
		// example: str = "to be the question", str3 = "or not to be"
		// str.insert(6,str3,3,4); // to be (not )the question
		// *Return the reference of itself
	{
		insert(pos, str.substr(subpos, sublen));
		return *this;
	}
	MyString& MyString::erase(size_t subpos, size_t sublen)
		// Erases the portion of the string value that begins at the character position pos and spans len characters 
		// (or until the end of the string, if either the content is too short or if len is string::msize.)
		// *Return the reference of itself
	{//HELLOC++ 
	 //01234567  SIZE=8   3,3 3,5 3,2
		size_t last;//�쩳���a��
		if (subpos + sublen > this->getSize())
		{
			last = this->getSize();
		}
		else
		{
			last = subpos + sublen;
		}
		MyString temp = substr(last, this->getSize() - last);
		for (size_t i = this->getSize() - 1; i >= subpos; i--)
		{
			this->pop_back();
		}
		for (size_t i = 0; i < temp.getSize(); i++)
		{
			this->push_back(temp[i]);
		}
		return *this;
		//0123456 size=7
	}
	size_t MyString::find(const MyString &str, size_t pos) const
		// Searches the portion of the string value that begins at the character position "pos" until the end of the string
		// for the first occurrence of the string str.
		// Return Value: The position of the first character of the first match. If no matches were found, the function returns MyString::msize.
	{
		size_t index = MyString::msize;
		for (size_t i = pos; i < this->getSize(); i++)
		{
			if ((*this)[i] == str[0])
			{

				if (this->substr(i, str.getSize()) == str)
				{
					index = i;
					break;
				}
			}
		}

		return index;
	}
	size_t MyString::find_first_of(const MyString &str, size_t pos) const
		// Searches the portion of the string value that begins at the character position "pos" until the end of the string
		// for the first character that matches *any* of the characters of the string str.
		// Return Value: The position of the first character that matches. If no matches are found, the function returns MyString::msize.
		//Add several operators
	{
		size_t index = MyString::msize;
		for (size_t i = pos; i < this->getSize(); i++)
		{
			for (size_t j = 0; j < str.getSize(); j++)
			{
				if (str[j] == (*this)[i])
				{
					if (i < index)
					{
						index = i;
					}
				}
			}
		}
		return index;
	}
	MyString MyString::operator+ (const MyString& rhs) const
	{
		MyString temp;
		temp.clear();
		for (size_t i = 0; i < this->getSize(); i++)
		{
			temp.push_back((*this)[i]);
		}
		for (size_t i = 0; i < rhs.getSize(); i++)
		{
			temp.push_back(rhs[i]);
		}
		return temp;
	}
	MyString MyString::operator+ (const char* rhs) const
	{

		MyString thistemp;
		for (size_t i = 0; i < this->getSize(); i++)
		{
			thistemp.push_back((*this)[i]);
		}
		MyString rhstemp(rhs);

		for (size_t i = 0; i < rhstemp.getSize(); i++)
		{
			thistemp.push_back(rhs[i]);
		}

		return thistemp;

	}
	MyString& MyString::operator= (const MyString& str)
	{
		if (str.getCapacity() <= this->getCapacity())
		{
			this->clear();//�M��this���}�C
			for (size_t i = 0; i < str.getSize(); i++)
			{
				this->push_back(str[i]);
			}
			this->shrink_to_fit();//error 
			this->reserve(str.getCapacity());
			//�ϭ�Ӫ�capacity�ŦX�s��capacity 
		}
		else
		{
			this->reserve(str.getCapacity());
			this->clear();//�M��this���}�C
			for (size_t i = 0; i < str.getSize(); i++)
			{
				this->push_back(str[i]);
			}
		}
		return *this;

	}
	MyString& MyString::operator= (const char* s)
	{
		this->clear();
		for (int i = 0; s[i] != '\0'; i++)
		{
			this->push_back(s[i]);
		}
		return *this;

	}
	MyString operator+ (const char* lhs, const MyString& rhs)
	{
		MyString temp;
		temp = lhs;
		temp = temp + rhs;
		return temp;
	}
