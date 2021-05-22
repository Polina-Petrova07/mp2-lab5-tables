#pragma once
#include <iostream>
#include <string>
#include <algorithm>

enum class color {NONE, RED, BLACK};
struct rowRB
{
	void print()
	{
		std::cout << "{" << key << ":";
		polinom.print();
		std::cout << "[";
		if (left == NULL) std::cout << "NULL";
		else left->print();
		std::cout << ",";
		if (right == NULL) std::cout << "NULL";
		else right->print();
		std::cout << "]}";

	}
	color col;
	std::string key;
	pol polinom;
	struct rowRB* left, * right;
	struct rowRB* parent;
	rowRB() 
	{
		left = NULL;
		right = NULL;
		parent = NULL;
		col = color::NONE;
	}
	rowRB(pol p):rowRB()
	{
		polinom = p;
	}
};

class tree
{	
private:
	rowRB* root;
	int size;
public:
	tree()
	{
		rowRB* ph = new rowRB();
		root = ph;
		size = 10;
	}
	struct rowRB* grandparent(rowRB *n)
	{
		if ((n != NULL) && (n->parent != NULL))
			return n->parent->parent;
		else
			return NULL;
	}
	struct rowRB* uncle(rowRB *n)
	{
		struct rowRB* g = grandparent(n);
		if (g == NULL)
			return NULL;
		if (n->parent == g->left)
			return g->right;
		else
			return g->left;
	}
	void rotate_right(rowRB *n)
	{
		n->parent = n->left;
		n->left = n->parent->right;
		n->parent->right = n;
		n = n->parent;	
	}
	void rotate_left(struct rowRB *n)
	{
		n->parent = n->right;
		n->right = n->parent->left;
		n->parent->left = n;
		n = n->parent;

	}
	void insert_case1(struct rowRB *n,std::string s)
	{
		if (root->parent == NULL)
		{
			root->col = color::BLACK;
			root->key = s;
			root->polinom = n->polinom;
		}
		else
			insert_case2(n,s);
	}
	void insert_case2(struct rowRB *n,std::string s)
	{
		if (root->parent->col != color::BLACK)
		    insert_case3(n,s);
	}
	void insert_case3(struct rowRB *n, std::string s)
	{
		struct rowRB* u = uncle(root), * g;
		if ((u != NULL) && (u->col == color::RED) && (root->parent->col == color::RED))
		{
			root->parent->col = color::BLACK;
			u->col = color::BLACK;
			g = grandparent(n);
			g->col = color::RED;
			insert_case1(g,s);
			root->key = s;
		}
		else
			insert_case4(n,s);
	}
	void insert_case4(struct rowRB *n, std::string s)
	{
		struct rowRB* g = grandparent(n);
		if ((root == root->parent->right) && (root->parent == g->left))
		{
			rotate_left(root->parent);
			root = root->left;
			root->key = s;
		}
		else
			if ((root == root->parent->left) && (root->parent == g->left))
			{
				rotate_right(root->parent);
				root = root->right;
				root->key = s;
			}
		insert_case5(n,s);
	}
	void insert_case5(struct rowRB *n, std::string s)
	{
		struct rowRB* g = grandparent(root);
		root->parent->col = color::BLACK;
		g->col = color::RED;
		if ((root == root->parent->left) && (root->parent == g->left))
		{
			rotate_right(g);
			root->key = s;
		}
		else
		{
			rotate_left(g);
			root->key = s;
		}
	}

	struct rowRB* sibling(struct rowRB *n)
	{
		if (n == n->parent->left)
			return n->parent->right;
		else
			return n->parent->left;
	}
	void delete_case1(struct rowRB *n)
	{
		if (n->parent != NULL)
			delete_case2(n);
	}
	void delete_case2(struct rowRB *n)
	{
		struct rowRB *s = sibling(n);
		if (s->col == color::RED)
		{
			n->parent->col = color::RED;
			s->col = color::BLACK;
			if (n = n->parent->left)
				rotate_left(n->parent);
			else
				rotate_right(n->parent);
		}
		delete_case3(n);
	}
	void delete_case3(struct rowRB *n)
	{
		struct rowRB *s = sibling(n);
		if ((n->parent->col == color::BLACK) && (s->col == color::BLACK) && (s->right->col == color::BLACK))
		{
			s->col = color::RED;
			delete_case1(n->parent);
		}
		else
			delete_case4(n);
	}
	void delete_case4(struct rowRB* n)
	{
		struct rowRB* s = sibling(n);
		if ((n->parent->col == color::RED) && (s->col == color::BLACK) && (s->left->col == color::BLACK) && (s->right->col == color::BLACK))
		{
			s->col = color::RED;
			n->parent->col = color::BLACK;
		}
		else
			delete_case5(n);
	}
	void delete_case5(struct rowRB *n)
	{
		struct rowRB *s = sibling(n);
		if (s->col == color::BLACK)
		{
			if ((n == n->parent->left) && (s->right->col == color::BLACK) && (s->left->col == color::RED))
			{
				s->col = color::RED;
				s->left->col = color::BLACK;
				rotate_right(s);
			}
			else
			{
				if ((n == n->parent->right) && (s->left->col == color::BLACK) && (s->right->col == color::RED))
					s->col = color::RED;
				s->right->col = color::BLACK;
				rotate_left(s);
			}
		}
		delete_case6(n);
	}
	void delete_case6(struct rowRB *n)
	{
		struct rowRB *s = sibling(n);
		s->col = n->parent->col;
		n->parent->col = color::BLACK;
		if (n == n->parent->left)
		{
			s->right->col = color::BLACK;
			rotate_left(n->parent);
		}
		else
		{
			s->left->col = color::BLACK;
			rotate_right(n->parent);
		}
	}
	pol search(rowRB *&p,std::string s)
	{
		if (root->key == s)
		{
			return root->polinom;
		}
		if (s < root->key)
		{
			return search(root->left, s);
		}
		else
		{
			return search(root->right, s);
		}
	}
	void print()
	{
		if (root->left == NULL) std::cout << "NULL";
		else root->left->print();
		std::cout << std::endl;
		if (root->right == NULL) std::cout << "NULL";
		else root->right->print();
	}
	
};