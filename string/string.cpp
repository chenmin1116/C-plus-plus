#include<iostream>
using namespace std;
#include<string>
#include<cstdio>
#include<cstdlib>

class String
{
private:
	char *_str;
public:
	friend ostream& operator<<(ostream&os,String&str)
	{
		os<<str._str;
		return os;
	}
	String(const char *str);
	String(const String&s);
	String& operator= (const String&s);          //赋值运算符的重载（笨拙写法）
	/*String& operator =(String s);   */             //赋值运算符的重载（现代写法）
	/*String operator+(const String&s);*/
	~String();

};
String::String (const char *str="")              //构造函数的定义
{
	this->_str =new (char[strlen(str)+1]);
	strcpy(this->_str,str);
	cout<<"String(const char *str)"<<endl;
}
String::String (const String&s)                   //拷贝构造函数的定义
{
	this->_str = new (char[strlen(s._str)+1]);
	strcpy(this->_str ,s._str );
	cout<<"String (const String&s)"<<endl;
}
String& String:: operator=(const String&s)        //赋值运算符的重载(笨拙写法）
{
	if(this == &s)
	{return *this;}
	else
	{
		delete[] this->_str ;
		this->_str = new (char[strlen(s._str)+1]);
		strcpy(this->_str ,s._str );
		return *this;
	}
	cout<<"operator=(const String&s)"<<endl;
}
//String& String::operator=(String s)               //赋值运算法的现代写法
//{
//	if(this==&s)
//	{return *this;}
//	else
//	{
//		std::swap(this->_str,s._str);
//		return *this;
//	}
//}
//String String:: operator+(const String&s)
//{
//  String tmp(this->_str);
//  delete[]this->_str ;
//  this->_str = new (char[strlen(this->_str)+strlen(s._str )+1]);
//  strcpy(this->_str ,tmp._str );
//
//}
String::~String()
{
	if(this != NULL)
	{
		delete[] this->_str ;
		this->_str = NULL;
    	cout<<"~string()"<<endl;
	}

}


void test1()
{
	String str1="hello,world";
	String str2(str1);
	cout<<str1<<endl;
	cout<<str2<<endl;
	str1.~String ();
	str2.~String ();
	
}
int main()
{
   test1();
   system("pause");
   return 0;
}
	