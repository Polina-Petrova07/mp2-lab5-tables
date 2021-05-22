#pragma once
#ifndef _LIST_H_
#define _LIST_H_
#include <iostream>

struct Node
{
	double c;
	int p;
	Node* next;

};
class List
{

public:
	Node* head;
	Node* tail;
	int n;
	List()
	{
		n = 0;
		head = NULL;
		tail = head;
	}
	bool Isempty()
	{
		return(head == NULL);
	}

	void Insert_end(int val1, double val2)
	{
		n++;
		Node* c = new Node();
		c->p = val1;
		c->c = val2;
		c->next = NULL;
		if (Isempty())
			head = c;
		else
			tail->next = c;
		tail = c;

	}
	void Insert_begin(int val1, double val2)
	{
		n++;
		Node* tmp = new Node();
		tmp->p = val1;
		tmp->c = val2;
		tmp->next = head;
		if (head == NULL)
			tail = tmp;
		head = tmp;
	}
	void Del(int k)
	{
		Node* c = head;
		if (head == nullptr)
			return;

		if (head->p == k)
		{
			head = head->next;
			n--;
			return;
		}
		while (c->next != NULL)
		{
			if (c->next->p == k)
			{
				c->next = c->next->next;
				n--;
				break;
			}
			c = c->next;
		}
		c = head;
		while ((c != NULL) && (c->next != NULL))
			c = c->next;
		tail = c;

	}
	void Print(int k)
	{
		if (k >= n) {
			std::cout << "Large number" << std::endl;
			return;
		}
		Node* c = head;
		for (int i = 0; i < k; i++)
			c = c->next;
		std::cout << c->c << '(' << c->p << ')';
	}
	List operator=(List a)
	{
		head = a.head;
		tail = a.tail;
		n = a.n;
		return(*this);
	}

};
#endif
