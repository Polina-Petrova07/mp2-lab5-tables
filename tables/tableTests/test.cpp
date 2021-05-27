#include "pch.h"
#include "../tables/table.h"
#include "../tables/hash.h"
#include "../tables/tree.h"

TEST(row, can_create_row_0)
{
	row r();
	ASSERT_NO_THROW();
}
TEST(row, can_create_row_1)
{
	List a;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 14);
	pol p(a);
	std::string s = "Vasy";
	row r(p, s);
	ASSERT_NO_THROW();
}
TEST(row, can_create_row_2)
{
	List a;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 14);
	a.Insert_begin(122, 25);
	a.Insert_begin(123, 48);
	pol p(a);
	std::string s = "qwertyuiop";
	row r(p, s);
	ASSERT_NO_THROW();
}
TEST(tablemas, can_create_tab_0)
{
	tablemas t();
	ASSERT_NO_THROW();
}
TEST(tablemas, can_insert_tab_0)
{
	List a;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 14);
	pol p(a);
	std::string s = "Vasy";
	tablemas t1;
	t1.insert(p, s);
	ASSERT_NO_THROW();
}
TEST(tablemas, can_insert_tab_1)
{
	tablemas t;
	List a;
	List b;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 14);
	b.Insert_begin(120, 14);
	b.Insert_begin(121, 14);
	pol p(a);
	pol p1(b);
	std::string s = "Vasy";
	t.insert(p, s);
	t.insert(p1, s);
	EXPECT_EQ(t.count_i, 2);
}
TEST(tablemas, can_insert_2)
{
	tablemas t;
	List a;
	List b;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 14);
	b.Insert_begin(120, 14);
	b.Insert_begin(121, 14);
	pol p(a);
	pol p1(b);
	std::string s = "Vasy";
	std::string s1 = "Koly";
	t.insert(p, s);
	t.insert(p1, s1);
	int n = t.getCount();
	EXPECT_EQ(n, 2);
}
TEST(tablemas, can_insert_3)
{
	tablemas t;
	List a;
	List b;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 14);
	b.Insert_begin(120, 14);
	b.Insert_begin(121, 14);
	pol p(a);
	pol p1(b);
	std::string s = "Vasy";
	std::string s1 = "Vasy";
	t.insert(p, s);
	t.insert(p1, s1);
	EXPECT_EQ(t.count_i, 2);
}
TEST(tablemas, can_del_tab_0)
{
	tablemas t;
	List a;
	List b;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 14);
	b.Insert_begin(120, 14);
	b.Insert_begin(121, 14);
	pol p(a);
	pol p1(b);
	std::string s = "Vasy";
	std::string s1 = "Koly";
	t.insert(p, s);
	t.insert(p1, s1);
	t.del(s);
	EXPECT_EQ(t.count_d, 1);//0
}
TEST(tablemas, can_del_tab_1)
{
	tablemas t;
	List a;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 14);
	pol p(a);
	std::string s = "Vasy";
	//std::string s1 = "Koly";
	t.insert(p, s);
	t.del(s);
	ASSERT_NO_THROW();
}
TEST(tablemas, can_search_tab_0)
{
	tablemas t;
	List a, b;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 14);
	b.Insert_begin(120, 14);
	b.Insert_begin(121, 14);
	std::string s = "Vasy";
	std::string s1 = "Koly";
	pol p(a);
	pol p1(b);
	t.insert(p, s);
	t.insert(p1, s1);
	pol u = t.search("Koly");
	EXPECT_EQ(t.count_s, 1);
}
TEST(hashRow, can_create_hashRow_0)
{
	hashRow r();
	ASSERT_NO_THROW();
}
TEST(hashtab, can_create_hashtab_0)
{
	hashtab t;
	ASSERT_NO_THROW();
}
TEST(hashRow, can_create_hashRow_1)
{
	List a;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 14);
	pol p(a);
	std::string s = "Vasy";
	hashRow hr(p, s);
	ASSERT_NO_THROW();
}
TEST(hashtab, can_insert_hashtab_0)
{
	List a;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 14);
	pol p(a);
	std::string s = "Pavel";
	hashtab t;
	t.insert(p, s);
	EXPECT_EQ(t.count_i, 1);
}
TEST(hashtab, can_insert_hashtab_1)
{
	List a;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 14);
	pol p(a);
	std::string s = "Pavel";
	hashtab t;
	t.insert(p, s);
	t.insert(p, s);
	EXPECT_EQ(t.count_i, 2);
}
TEST(hashtab, can_insert_hashtab_2)
{
	List a;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 14);
	pol p(a);
	std::string s = "Pavel";
	hashtab t;
	t.insert(p, s);
	int k = hashFunc(s);
	EXPECT_EQ(t.getPosbool(k), false);
}
TEST(hashtab, can_insert_hashtab_3)
{
	List a;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 14);
	pol p(a);
	std::string s = "Pavel";
	hashtab t;
	t.insert(p, s);
	t.insert(p, s);
	int k = hashFunc(s) + 3;
	EXPECT_EQ(t.getPosbool(k), false);
}
TEST(hashtab, can_insert_hashtab_4)
{
	List a;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 14);
	pol p(a);
	std::string s = "Pavel";
	hashtab t;
	t.insert(p, s);
	t.insert(p, s);
	int k = hashFunc(s)+3;
	EXPECT_EQ(k,123);
}
TEST(hashtab, correct_hashfunc_0)
{
	std::string s = "Pavel";
	int k = hashFunc(s);
	EXPECT_EQ(k, 120);
}
TEST(hashtab, correct_hashfunc_1)
{
	std::string s = "jkfgh8798dsfhsk";
	int k = hashFunc(s);
	EXPECT_EQ(k, 237);
}
TEST(hashtab, can_del_hashtab_0)
{
	hashtab ht;
	List a;
	List b;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 14);
	b.Insert_begin(120, 14);
	b.Insert_begin(121, 14);
	pol p(a);
	pol p1(b);
	std::string s = "Vasy";
	std::string s1 = "Koly";
	ht.insert(p, s);
	ht.insert(p1, s1);
	ht.del(s);
	EXPECT_EQ(ht.count_d, 1);
}
TEST(hashtab, can_del_hashtab_1)
{
	hashtab ht;
	List a;
	List b;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 14);
	b.Insert_begin(120, 14);
	b.Insert_begin(121, 14);
	pol p(a);
	pol p1(b);
	std::string s = "Vasy";
	std::string s1 = "Koly";
	ht.insert(p, s);
	ht.insert(p1, s1);
	ht.del(s);
	EXPECT_EQ(ht.getcounth(), 1);
}
TEST(hashtab, can_del_hashtab_2)
{
	hashtab ht;
	List a;
	List b;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 14);
	b.Insert_begin(120, 14);
	b.Insert_begin(121, 14);
	pol p(a);
	pol p1(b);
	std::string s = "Vasy";
	std::string s1 = "Koly";
	ht.insert(p, s);
	ht.insert(p1, s1);
	ht.del(s);
	ht.del(s1);
	EXPECT_EQ(ht.getcounth(), 0);
}
TEST(hashtab, can_del_hashtab_3)
{
	hashtab hht;
	List a;
	List b;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 14);
	b.Insert_begin(120, 14);
	b.Insert_begin(121, 14);
	pol p(a);
	pol p1(b);
	std::string s = "Alexandr";
	std::string s1 = "Alexandr";
	hht.insert(p, s);
	hht.insert(p1, s1);
	hht.del(s);
	EXPECT_EQ(hht.getcounth(), 0);
}
TEST(hashtab, can_del_hashtab_4)
{
	hashtab hht;
	List a;
	List b;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 14);
	b.Insert_begin(120, 14);
	b.Insert_begin(121, 14);
	pol p(a);
	pol p1(b);
	std::string s = "Alexandr";
	std::string s1 = "Kirill";
	hht.insert(p, s);
	hht.insert(p1, s1);
	hht.del(s);
	EXPECT_EQ(hht.getPosbool(hashFunc(s)), true);
}
TEST(hashtab, can_search_hashtab_0)
{
	hashtab ht;
	List a;
	List b;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 14);
	b.Insert_begin(120, 14);
	b.Insert_begin(121, 14);
	pol p(a);
	pol p1(b);
	std::string s = "Grigogy";
	std::string s1 = "Viktor";
	ht.insert(p, s);
	ht.insert(p1, s1);
	ht.search(s);
	EXPECT_EQ(ht.count_s, 1);
}
TEST(hashtab, can_search_hashtab_1)
{
	hashtab ht;
	List a;
	List b;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 14);
	b.Insert_begin(120, 14);
	b.Insert_begin(121, 14);
	pol p(a);
	pol p1(b);
	std::string s = "Grigogy";
	std::string s1 = "Viktor";
	ht.insert(p, s);
	ht.insert(p1, s1);
	hashRow r(ht.search(s),s);
	int k = hashFunc(r.key);
	int pos = ht.getPos(k);
	EXPECT_EQ(pos, hashFunc(s));
}









