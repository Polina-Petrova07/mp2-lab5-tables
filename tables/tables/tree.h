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
	//Node* root;
	rowRB* nil_node;
public:
	explicit tree() {
		this->nil_node = new rowRB();
		this->nil_node->col = color::BLACK;
		this->nil_node->parent = this->nil_node;
		this->root = this->nil_node;
	}

	/*tree()
	{
		//rowRB* ph = new rowRB();
		root = new rowRB();
		size = 10;
	}*/
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
	/*void rotate_right(rowRB *n)
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
/*	void insert_case1(struct rowRB *n, std::string s)
	{
		if (root->parent == NULL)
		{
			root->col = color::BLACK;
			root->key = s;
			root->polinom = n->polinom;
			//root->parent!=NULL;
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
			root->polinom = n->polinom;
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
			root->polinom = n->polinom;
		}
		else
			if ((root == root->parent->left) && (root->parent == g->left))
			{
				rotate_right(root->parent);
				root = root->right;
				root->key = s;
				root->polinom = n->polinom;
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
			root->polinom = n->polinom;
		}
		else
		{
			rotate_left(g);
			root->key = s;
			root->polinom = n->polinom;
		}
	}
*/

	void rotateLeft(rowRB* node) {
		rowRB* temp = node->right;
		node->right = temp->left;

		if (temp->left != this->nil_node)
			temp->left->parent = node;
		temp->parent = node->parent;

		if (node->parent == this->nil_node)
			this->root = temp;
		else if (node == node->parent->left)
			node->parent->left = temp;
		else
			node->parent->right = temp;
		temp->left = node;
		node->parent = temp;
	}

	void rotateRight(rowRB* node) {
		rowRB* temp = node->left;
		node->left = temp->right;

		if (temp->right != this->nil_node)
			temp->right->parent = node;
		temp->parent = node->parent;

		if (node->parent == this->nil_node)
			this->root = temp;
		else if (node == node->parent->right)
			node->parent->right = temp;
		else
			node->parent->left = temp;
		temp->right = node;
		node->parent = temp;
	}

	void insert(std::string s, pol value) {
		rowRB* node = new rowRB();
		rowRB* y = this->nil_node;
		rowRB* x = this->root;
		while (x != this->nil_node) {
			y = x;
			if (node->polinom.a.head < x->polinom.a.head)
				x = x->left;
			else
				x = x->right;
		}

		node->parent = y;
		if (y == this->nil_node)
			this->root = node;
		else if (node->polinom.a.head < y->polinom.a.head)
			y->left = node;
		else
			y->right = node;
		node->key = s;
		node->left = this->nil_node;
		node->right = this->nil_node;
		node->col = color::RED;
		insertFixup(node);
	}
	void insertFixup(rowRB* node) {
		rowRB* temp;
		while (node->parent->col == color::RED) {
			if (node->parent == node->parent->parent->left) {
				temp = node->parent->parent->right;
				if (temp->col == color::RED) {
					node->parent->col = color::BLACK;
					temp->col = color::BLACK;
					node->parent->parent->col = color::RED;
					node = node->parent->parent;
				}
				else {
					if (node == node->parent->right) {
						node = node->parent;
						rotateLeft(node);
					}
					node->parent->col = color::BLACK;
					node->parent->parent->col = color::RED;
					rotateRight(node->parent->parent);
				}
			}
			else {
				temp = node->parent->parent->left;
				if (temp->col == color::RED) {
					node->parent->col = color::BLACK;
					temp->col = color::BLACK;
					node->parent->parent->col = color::RED;
					node = node->parent->parent;
				}
				else {
					if (node == node->parent->left) {
						node = node->parent;
						rotateRight(node);
					}
					node->parent->col = color::BLACK;
					node->parent->parent->col = color::RED;
					rotateLeft(node->parent->parent);
				}
			}
		}
		this->root->col = color::BLACK;
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
				rotateLeft(n->parent);
			else
				rotateRight(n->parent);
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
				rotateRight(s);
			}
			else
			{
				if ((n == n->parent->right) && (s->left->col == color::BLACK) && (s->right->col == color::RED))
					s->col = color::RED;
				s->right->col = color::BLACK;
				rotateLeft(s);
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
			rotateLeft(n->parent);
		}
		else
		{
			s->left->col = color::BLACK;
			rotateRight(n->parent);
		}
	}
	pol search(std::string s)
	{
		if (root->key == s)
		{
			return root->polinom;
		}
		if (s < root->key)
		{
			return search(s);
		}
		else
		{
			return search(s);
		}
	}
	void print()
	{
		root->print();
		/*
		if (root->left == NULL) std::cout << "NULL";
		else root->left->print();
		std::cout << std::endl;
		if (root->right == NULL) std::cout << "NULL";
		else root->right->print();
		*/
	}
	
};