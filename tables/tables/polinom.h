#pragma once
#ifndef _POLINOM_H_
#define _POLINOM_H_
#include "list.h"
//#include "tree.h"

class pol
{
public:
	List a;
	pol()
	{
		a.n = 0;
		a.head = NULL;
		a.tail = a.head;
	}
	pol(List b)
	{
		a = b;
	}
	pol operator=(pol b)
	{
		a = b.a;
		return(*this);
	}
//	pol operator=(const struct node *n)
//	{
//		a = n->key.a;
//	}
	pol(int pow, double c)
	{
		a.Insert_begin(pow, c);
	}
	pol& Mull(double k)
	{
		pol b;
		b = (*this);
		Node* tmp = b.a.head;
		while (tmp->next != NULL)
		{
			tmp->c *= k;
			tmp = tmp->next;
		}
		tmp->c *= k;
		b.DelZero();
		return(b);
	}
	void DelDups()
	{
		int k;
		Node* tmp = a.head;
		Node* tmp1;
		while (tmp->next != NULL)
		{
			tmp1 = tmp->next;
			while (tmp1 != NULL)
			{
				k = 0;
				if (tmp->p == tmp1->p)
				{
					tmp1->c += tmp->c;
					k = tmp->p;
					tmp = tmp->next;
					a.Del(k);
					break;
				}
				tmp1 = tmp1->next;
			}
			if (!k)
				tmp = tmp->next;
		}
	}
	void DelZero()
	{
		int k = 0;
		Node* tmp = a.head;
		Node* tmp1 = tmp;
		while (tmp1->next != NULL)
		{
			if (tmp1->c == 0)
				k++;
			tmp1 = tmp1->next;
		}
		if (tmp1->c == 0)
			k++;
		while ((a.head != NULL) && (a.head->c == 0))
		{
			a.head = a.head->next;
			a.n--;
			k--;
		}
		while (k != 0)
		{

			tmp = a.head;

			while ((tmp != NULL) && (tmp->next != NULL))
			{
				if (tmp->next->c == 0)
				{
					a.n--;
					k--;
					tmp->next = tmp->next->next;
					break;
				}
				tmp = tmp->next;
			}
		}
		tmp = a.head;
		while ((tmp != NULL) && (tmp->next != NULL))
			tmp = tmp->next;
		a.tail = tmp;
	}
	pol& operator+(pol b)
	{
		Node* tmp1 = a.head;
		Node* tmp2 = b.a.head;
		a.tail->next = b.a.head;
		a.tail = b.a.tail;

		a.n += b.a.n;
		DelDups();
		DelZero();
		return(*this);
		/*Node* tmp1 = a.head;
		Node* tmp2 = b.a.head;
		while (tmp1->next != NULL)
		{
			tmp2 = b.a.head;
			while (tmp2->next != NULL)
			{
				if (tmp1->p == tmp2->p)
				{
					tmp1->c += tmp2->c;
					b.a.Del(tmp2->p);
				}
				tmp2 = tmp2->next;
			}
			if (tmp1->p == tmp2->p)
			{
				tmp1->c += tmp2->c;
				b.a.Del(tmp2->p);
			}
			tmp1 = tmp1->next;
		}
		tmp2 = b.a.head;
		while (tmp2->next != NULL)
		{
			if (tmp1->p == tmp2->p)
			{
				tmp1->c += tmp2->c;
				b.a.Del(tmp2->p);
			}
			tmp2 = tmp2->next;
		}
		if (tmp1->p == tmp2->p)
		{
			tmp1->c += tmp2->c;
			b.a.Del(tmp2->p);
		}
		a.tail->next = b.a.head;
		if (b.a.head != NULL)
			a.tail = b.a.tail;

		a.n += b.a.n;
		DelZero();
		return(*this);*/
	}
	pol& operator*(pol b)
	{
		pol c;
		Node* tmp1 = a.head;
		Node* tmp2 = b.a.head;
		while (tmp1->next != NULL)
		{
			tmp2 = b.a.head;
			while (tmp2->next != NULL)
			{
				if ((((tmp1->p) / 100 + (tmp2->p) / 100) > 9) || ((((tmp1->p) % 100) / 10 + ((tmp2->p) % 100) / 10) > 9) || (((tmp1->p) % 10 + (tmp2->p) % 10) > 9))
					throw "Incorrect power";
				c.a.Insert_end(tmp1->p + tmp2->p, tmp1->c * tmp2->c);
				tmp2 = tmp2->next;
			}
			if ((((tmp1->p) / 100 + (tmp2->p) / 100) > 9) || ((((tmp1->p) % 100) / 10 + ((tmp2->p) % 100) / 10) > 9) || (((tmp1->p) % 10 + (tmp2->p) % 10) > 9))
				throw "Incorrect power";
			c.a.Insert_end(tmp1->p + tmp2->p, tmp1->c * tmp2->c);
			tmp1 = tmp1->next;
		}
		tmp2 = b.a.head;
		while (tmp2->next != NULL)
		{
			if ((((tmp1->p) / 100 + (tmp2->p) / 100) > 9) || ((((tmp1->p) % 100) / 10 + ((tmp2->p) % 100) / 10) > 9) || (((tmp1->p) % 10 + (tmp2->p) % 10) > 9))
				throw "Incorrect power";
			c.a.Insert_end(tmp1->p + tmp2->p, tmp1->c * tmp2->c);
			tmp2 = tmp2->next;
		}
		if ((((tmp1->p) / 100 + (tmp2->p) / 100) > 9) || ((((tmp1->p) % 100) / 10 + ((tmp2->p) % 100) / 10) > 9) || (((tmp1->p) % 10 + (tmp2->p) % 10) > 9))
			throw "Incorrect power";
		c.a.Insert_end(tmp1->p + tmp2->p, tmp1->c * tmp2->c);
		c.DelZero();
		return(c);
	}
	pol& operator-(pol b)
	{
		pol c;
		c = b;
		c.Mull(-1);
		return(*this + c);
	}

	bool operator==(const pol &b) const
	{
		Node* tmp1 = a.head;
		Node* tmp2 = b.a.head;
		if (a.n != b.a.n)
			return false;
		else
		{
			bool f;
			while (tmp1->next)
			{
				if ((tmp1->next->p != tmp2->next->p) || (tmp1->next->c != tmp2->next->c))
				{
					f = false;
				}
				tmp1 = tmp1->next;
				tmp2 = tmp2->next;
			}
		}
	}
	bool operator !=(const pol& b)
	{
		return!(*this == b);
	}
	void print()
	{
		std::cout << "(";
		for (int i = 0; i < a.n; i++)
		{
			a.Print(i);
			if (i != a.n - 1)
				std::cout << "  +  ";
		}
		std::cout << ")";
	}

};


#endif
