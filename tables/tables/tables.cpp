// tables.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "table.h"
#include "tree.h"
#include "hash.h"

int main()
{
	int r, j, k=0, p;
	double c;
	//List a;
	std::string s;
	tablemas t1;
	hashtab t2;

	std::cout << "Enter number of polynomials" << std::endl;
	std::cin >> r;
	for (int i = 0; i < r; i++)
	{
		List a;
		std::cout << "Enter name for polynomial" << std::endl;
		std::cin >> s;
		std::cout << "Entering polynomial" << std::endl;
		std::cout << "Enter number of monomials" << std::endl;
		std::cin >> k;
		std::cout << std::endl;
		for (int j = 0; j < k; j++)
		{
			std::cout << "Enter power of monom" << " " << j + 1 << std::endl;
			std::cin >> p;
			std::cout << std::endl;
			while (p > 999)
			{
				std::cout << "Incorrect power, try again" << std::endl;
				std::cin >> p;
				std::cout << std::endl;
			}
			std::cout << "Enter coefficient of monom" << " " << j + 1 << std::endl;
			std::cin >> c;
			std::cout << std::endl;
			a.Insert_end(p, c);
		}
		pol b(a);
		t1.insert(b, s);
		t2.insert(b, s);
		std::cout << "t1.insert:" << t1.count_i << std::endl;
		std::cout << "t2.insert:" << t2.count_i << std::endl;
	}
	std::cout << std::endl;
	t1.print();
	std::cout << std::endl << "====================================" << std::endl << std::endl;
	t2.print();
	std::cout << std::endl;

	while (k)
	{
		std::cout << "1 Delete" << std::endl;
		std::cout << "2 Search" << std::endl;
		std::cout << "3.Change" << std::endl;
		std::cout << "4.Show tables" << std::endl;
		std::cout << "0.Exit" << std::endl;
		std::cin >> k;
		switch (k)
		{
		case 1:
		{
			std::cout << "name of polinom" << std::endl;
			std::cin >> s;
			t1.del(s);
			t2.del(s);
			std::cout << "t1.delete:" << t1.count_d << std::endl;
			std::cout << "t2.delete:" << t2.count_d << std::endl;
			std::cout << std::endl;
			break;
		}
		case 2:
		{
			std::cout << "name of polinom" << std::endl;
			std::cin >> s;
			pol p = t1.search(s);
			t2.search(s);
			std::cout << "t1.search:" << t1.count_s << std::endl;
			std::cout << "t2.search:" << t2.count_s << std::endl;
			std::cout << std::endl;
			p.print();
			std::cout << std::endl;
			break;
		}
		case 3:
		{
			std::cout << "name of polinom" << std::endl;
			std::cin >> s;
			pol b1 = t1.search(s);
			b1.print();
			pol b2;
			std::cout << std::endl;
			std::cout << "If you want to perform the operations witn new polynomial enter 1, with table polynomial enter 0" << std::endl;
			std::cin >> k;
			if (k) {
				List a;
				std::cout << "Entering 2-nd polynomial" << std::endl;
				std::cout << "Enter number of monomials" << std::endl;
				std::cin >> k;
				std::cout << std::endl;
				for (int i = 0; i < k; i++)
				{
					std::cout << "Enter power of monom" << " " << i + 1 << std::endl;
					std::cin >> p;
					std::cout << std::endl;
					while (p > 999)
					{
						std::cout << "Incorrect power, try again" << std::endl;
						std::cin >> p;
						std::cout << std::endl;
					}
					std::cout << "Enter coefficient of monom" << " " << i + 1 << std::endl;
					std::cin >> c; std::cout << std::endl;
					a.Insert_end(p, c);
				}
				std::cout << "Entering of polynomials is complited";
				pol b(a);
				b2 = b;
			}
			else
			{
				std::string s1;
				std::cout << "Enter his name" << std::endl;
				std::cin >> s1;
				pol b = t1.search(s1);
				b2 = b;
			}
			std::cout << std::endl;
			std::cout << "Choose operation" << std::endl;
			std::cout << "1. Add polynomials" << std::endl;
			std::cout << "2. Subtract polynomials" << std::endl;
			std::cout << "3. Multiply polynomials" << std::endl;
			std::cout << "4. Multiply 1-st polynomial on const" << std::endl;
			pol b3;
			std::cin >> k;
			std::cout << std::endl;
			switch (k)
			{
			case 1:
			{
				b3 = b1 + b2;
				t1.del(s);
				t2.del(s);
				t1.insert(b3, s);
				t2.insert(b3, s);
				break;
			}
			case 2:
			{
				b3 = b1 - b2;
				t1.del(s);
				t2.del(s);
				t1.insert(b3, s);
				t2.insert(b3, s);
				break;
			}
			case 3:
			{
				b3 = b1 * b2;
				t1.del(s);
				t2.del(s);
				t1.insert(b3, s);
				t2.insert(b3, s);
				break;
			}
			case 4:
			{
				std::cout << "Enter constant" << std::endl;
				std::cin >> c;
				std::cout << std::endl;
				b3 = b1.Mull(c);
				t1.del(s);
				t2.del(s);
				t1.insert(b3, s);
				t2.insert(b3, s);
				break;
			}
			default:
				break;
			}
			break;
		}
		case 4:
		{
			std::cout << "tables:" << std::endl;
			t1.print();
			std::cout << std::endl;
			std::cout << "=====================================" << std::endl;
			t2.print();
			break;
		}
		default:
			break;
		}
	}
	//system("pause");

/*
tree t;
List a;
int k,p,c;
std::cout << "Entering 2-nd polynomial" << std::endl;
std::cout << "Enter number of monomials" << std::endl;
std::cin >> k;
std::cout << std::endl;
for (int i = 0; i < k; i++)
{
	std::cout << "Enter power of monom" << " " << i + 1 << std::endl;
	std::cin >> p;
	std::cout << std::endl;
	while (p > 999)
	{
		std::cout << "Incorrect power, try again" << std::endl;
		std::cin >> p;
		std::cout << std::endl;
	}
	std::cout << "Enter coefficient of monom" << " " << i + 1 << std::endl;
	std::cin >> c;
	std::cout << std::endl;
	a.Insert_end(p, c);
}
pol b(a);
rowRB* r = new rowRB(b);
t.insert_case1(r, "asdfgh");
t.insert_case1(r, "qwerty");

t.print();*/

return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
