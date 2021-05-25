#pragma once
#include "polinom.h"
#define MAXSIZE 256

struct hashRow
{
	std::string key;
	pol polinom;
	bool empty;

	hashRow() { empty = true; }
	hashRow(pol p, std::string s)
	{
		polinom = p;
		key = s;
	}
	bool operator ==(hashRow r)
	{
		if ((polinom == r.polinom) && (key == r.key))
			return true;
		else false;
	}
	bool GetEmpty()
	{
		return empty;
	}
};
int hashFunc(std::string s)
{
	/*int k = (int)s.length();
	int u = 0, n = 0;

	for (int i = 0; i < k; i++)
	{
		n = (int)s[i];
		u += i * n % 31;
	}
	return u % 139;*/
	/*int seed = 131;
	unsigned long hash = 0;
	for (int i = 0; i < s.length(); i++)
	{
		hash = (hash * seed) + s[i];
	}
	return hash % MAXSIZE;*/
	int sum = 0;
	for (int i = 0; i < s.length(); i++)
	{
		sum = sum + (unsigned int)s[i] + 128;
	}
	return (sum % 256);
}

class hashtab
{
private:
	hashRow mas[MAXSIZE];
	int count;
	
public:
	int count_s;
	int count_i;
	int count_d;
	hashtab()
	{
		count = 0;
		count_s = 0;
		count_d = 0;
		count_i = 0;
		//step = 0;
	}

	inline void insert(pol p, std::string key)
	{
		hashRow hr (p, key);
		//count_i = 0;
		count_i++;
		int pos = hashFunc(key);
		if (pos + 1 > MAXSIZE)
			throw "hashtab is full";
		if (mas[pos].empty)
		{
			mas[pos] = hr;
			mas[pos].empty = false;
			count++;
			//return;
		}
		else 
		{
			for (int i = 0; i < MAXSIZE; i++)
			{
				/*std::cout << "GOOD1" << std::endl;
				pos = hashFunc(key) + 2 * i;
				std::cout << "GOOD2" << std::endl;
				if (mas[pos].empty)
				{
					std::cout << "GOOD3" << std::endl;
					mas[pos] = hr;
					mas[pos].empty = false;
					std::cout << "GOOD4" << std::endl;
					count++;
					break;
					std::cout << "GOOD5" << std::endl;
				}
				else
				{
					std::cout << "GOOD6" << std::endl;
					throw "hashtab is full";
				}*/
				if (mas[pos + 3 * i].empty)
				{
					mas[pos + 3 * i] = hr;
					mas[pos + 3 * i].empty = false;
					count++;
					break;
				}
			}
		}
	}
	inline pol search(std::string s)
	{
		count_s = 0;
		count_s++;
		for (hashRow hr : mas)
		{
			if (hr.key == s)
				return hr.polinom;
		}
	}
	inline void del(std::string s)
	{
		count_d = 0;
		
		hashRow hr(search(s), s);//удаляемя сторка
		for (int i = 0; i < MAXSIZE; i++)
		{
			if (mas[i].key == hr.key)
			{
				mas[i].empty = true;
				count--;
				count_d++;
			}
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
				//std::cout << i<<"   ";
				std::cout << mas[i].key << "   ";
				mas[i].polinom.print();
				std::cout << std::endl;
			}
		}
	}
	int getPos(int k)
	{
		return hashFunc(mas[k].key);
	}
	bool getPosbool(int k)
	{
		return mas[hashFunc(mas[k].key)].empty;
	}
	int getcounth()
	{
		return count;
	}
	~hashtab()
	{
		//delete[]mas;
		this->count = 0;
	}


};