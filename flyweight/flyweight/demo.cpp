#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;

//class Gazillion
//{
//public:
//	Gazillion(int value_one)
//	{
//		m_value_one = value_one;
//		cout << "ctor: " << m_value_one << '\n';
//	}
//	~Gazillion()
//	{
//		cout << m_value_one << ' ';
//	}
//	void report(int value_two)
//	{
//		cout << m_value_one << value_two << ' ';
//	}
//private:
//	int m_value_one;
//};
//
//
//class Factory
//{
//public:
//	static Gazillion* get_fly(int in)
//	{
//		if (!s_pool[in])
//			s_pool[in] = new Gazillion(in);
//		return s_pool[in];
//	}
//	static void clean_up()
//	{
//		cout << "dtors: ";
//		for (int i = 0; i < X; ++i)
//			if (s_pool[i])
//				delete s_pool[i];
//		cout << '\n';
//	}
//	static int X, Y;
//private:
//	static Gazillion* s_pool[];
//};
//
//
//int Factory::X = 6, Factory::Y = 10;
//Gazillion* Factory::s_pool[] =
//{
//  0, 0, 0, 0, 0, 0
//};
//
//int main()
//{
//	for (int i = 0; i < Factory::X; ++i)
//	{
//		for (int j = 0; j < Factory::Y; ++j)
//			Factory::get_fly(i)->report(j);
//		cout << '\n';
//	}
//	Factory::clean_up();
//
//	system("pause");
//	return 0;
//}

class Stat
{
public:
	Stat();
	~Stat();
	Stat(int row)
	{
		a = row;
		cout << "row num" << row << endl;
	}
	void out(int b)
	{
		cout << a << b << " ";
	}
private:
     int a;
};

class mat
{
public:
	static Stat* check(int a)
	{
		if (!c[a])
		{
			c[a] = new Stat(a);
		}
		return c[a];
	}
	static int X, Y;
private:
	static Stat* c[10];
};
Stat* mat::c[] = { 0 };
int mat::X = 5; int mat::Y = 10;

int main()
{
	for (int i = 0;i < mat::Y;i++)
	{
		for (int j = 0;j < mat::X;j++)
		{
			mat::check(i)->out(j);
		}
		cout << '\n';
	}
	system("pause");
	return 0;
}