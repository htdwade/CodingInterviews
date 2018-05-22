/* 

剑指Offer
面试题2：实现Singleton模式
题目：设计一个类，我们只能生成该类的一个实例。

*/

#include <iostream>

using namespace std;

//单例模式就是一个类只能生成一个实例
//《Effective C++》中提到的单例模式是用到local-static对象，也就是函数内部的static对象，好处就是第一次调用才生成并且生命周期一直存在
class Singleton1
{
private:
	Singleton1() {

	}
public:
	static Singleton1* getInstance()
	{
		static Singleton1* single = new Singleton1();
		return single;
	}
};

//《大话设计模式》中的就是用一个static的成员变量，但是在得到实例函数中判断这个变量是否为空
class Singleton2
{
private:
	static Singleton2 *single;
	Singleton2() {

	}
public:
	static Singleton2* getInstance()
	{
		if (single == NULL)
			single = new Singleton2();
		return single;
	}
};

Singleton2* Singleton2::single = NULL;

int main()
{
	Singleton1 *s1 = Singleton1::getInstance();
	Singleton1 *s2 = Singleton1::getInstance();
	if (s1 == s2)
		cout << "success" << endl;
	Singleton2 *s3 = Singleton2::getInstance();
	Singleton2 *s4 = Singleton2::getInstance();
	if (s3 == s4)
		cout << "success" << endl;
	return 0;
}