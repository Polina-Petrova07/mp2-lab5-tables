#pragma once
#ifndef _TABLE_H_
#define _TABLE_H_
#include "polinom.h"
#include <string>
//#include <list>
#include <algorithm>
#include <iterator>
#define MAXSIZE 256
struct row 
{
//  private:
//	std::string key;
//	pol polinom;
public:
	std::string key;
	pol polinom;
	bool empty;

	row() { empty = true; };
	row(pol b, std::string s)
	{
		polinom = b;
		key = s;
	}
	bool operator==(row b)
	{
		if ((polinom == b.polinom)&& (key==b.key))
			return 1;
		return 0;
	}
};
class tablemas
{
protected:
	row mas[MAXSIZE];
	int count;
public:
	int count_s;
	int count_i;
	int count_d;
	tablemas()
	{
		count = 0;
		count_s = 0;
		count_d = 0;
		count_i = 0;
	}
	inline void insert(pol b, std::string s)
	{
		row r(b, s);
		//count_i = 0;
		count_i++;
		if (count + 1 > MAXSIZE)
			throw "table is full";
		int pos = count++;
		mas[pos] = r;
		mas[pos].empty = false;
	}
	inline pol search(std::string s)
	{
		count_s = 0;
		count_s++;
		for (row r : mas)
		{
			if (r.key == s)
				return r.polinom;
		}
		throw "not found";
	}
	inline void del(std::string s)
	{
		if (!count_i)
			throw "table is empty";
		count_d = 0;
		count_d++;
		row r(search(s), s);
		for (int i=0;i<MAXSIZE;i++)
			if (mas[i] == r)
			{
				mas[i] = mas[count--];
				//count_d++;
			
			}
	}
	void print()
	{
		if (!count)
			throw "table is empty";
		for (int i = 0; i < MAXSIZE; i++)
		{
			if (mas[i].empty == false)
			{
				//std::cout << i << "   ";
				std::cout << mas[i].key << "   ";
				mas[i].polinom.print();
				std::cout << std::endl;
			}
		}
	}
	row* get_vec()
	{
		return mas;
	}
	~tablemas()
	{
		//delete[]mas;
		this->count = 0;
	}
	int getCount()
	{
		return count;
	}
};




#endif