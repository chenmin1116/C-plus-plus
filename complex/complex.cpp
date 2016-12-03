//1.写一个复数类。
//2.看C++书籍的类和对象部分。
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<cstdio>
#include<math.h>

class Complex                  //定义Complex类；
	{
		private:
			float _real;
			float _immage;
		public:
			Complex(float real,float immage);
			
			~Complex()
			{}
			
			void print(Complex complex);
		
			void  operator+(Complex &complex2);  //运算符“+”重载，实现复数的加法；
			
		    void  operator-(Complex &complex2);     //运算符“-”重载，实现复数的减法；
			
			void  operator*(Complex &complex2);     //运算符“*”重载，实现复数的乘法；
			
			void  operator/(Complex &complex2);    //运算符“/”重载，实现复数的除法；
			 
			void  operator+=(Complex &complex2);    //运算符“+=”重载，实现复数的除法；

			void  operator-=(Complex &complex2);    //运算符“-=”重载，实现复数的除法；

			void  operator*=(Complex &complex2);    //运算符“*=”重载，实现复数的除法；

			void  operator/=(Complex &complex2);    //运算符“/=”重载，实现复数的除法；
			
			
		};
Complex::Complex(float real,float immage)
	{
		_real=real;
		_immage=immage;
	}
void Complex:: print(Complex complex)
	{
		if(complex._immage>0)
		{
			cout<<"complex"<<"="<<complex._real<<"+"<<complex._immage<<"i"<<endl;
		}
		else
		{
            cout<<"complex"<<"="<<complex._real<<complex._immage<<"i"<<endl;
		}
	}

void  Complex::operator+(Complex &complex2)  //运算符“+”重载，实现复数的加法；
	{
		Complex complex3=Complex(0.0,0.0);
		complex3._real = _real + complex2._real;
		complex3._immage = _immage + complex2._immage ;
		if(complex3._immage>0)
		{
			cout<<"加法运算为：complex1+complex2="<<complex3._real<<"+"<<complex3._immage<<"i"<<endl;
		}
		else
		{
			cout<<"加法运算为：complex1+complex2="<<complex3._real<<complex3._immage<<"i"<<endl;
		}
		complex3.~Complex ();
		
	}

void  Complex:: operator-(Complex &complex2)     //运算符“-”重载，实现复数的减法；
	{
		Complex complex3=Complex(0.0,0.0);
		complex3._real = _real - complex2._real;
		complex3._immage = _immage - complex2._immage ;
		if(complex3._immage>0.0)
		{
			cout<<"减法运算为：complex1+complex2="<<complex3._real<<"+"<<complex3._immage<<"i"<<endl;
		}
		else
		{
			cout<<"减法运算为：complex1+complex2="<<complex3._real<<complex3._immage<<"i"<<endl;
		}
		complex3.~Complex ();
	}
			
void  Complex:: operator*(Complex &complex2)     //运算符“*”重载，实现复数的乘法；
	{
		Complex complex3=Complex(0.0,0.0);
		complex3._real = (_real * complex2._real) - (_immage * complex2._immage);
		complex3._immage = (_immage * complex2._real) + (_real * complex2._immage ) ;
		if(complex3._immage>0.0)
		{
			cout<<"乘法运算为：complex1+complex2="<<complex3._real<<"+"<<complex3._immage<<"i"<<endl;
		}
		else
		{
			cout<<"乘法运算为：complex1+complex2="<<complex3._real<<complex3._immage<<"i"<<endl;
		}
		 complex3.~Complex ();

	}

void  Complex:: operator/(Complex &complex2)      //运算符“/”重载，实现复数的除法；
	{
		float k=0;
		Complex complex3=Complex(0.0,0.0);
		Complex complex4=Complex(0.0,0.0);
		k=(complex2._real* complex2._real)+(complex2._immage*complex2._immage );
		complex4._real = (_real*complex2._real )+(_immage*complex2._immage);
		complex4._immage  = (_real * -complex2._immage )+(_immage * complex2._real );
		complex3._real =complex4._real/k; 
		complex3._immage = complex4._immage /k ;
		if(complex3._immage>0.0)
		{
			cout<<"除法运算为：complex1+complex2="<<complex3._real<<"+"<<complex3._immage<<"i"<<endl;
		}
		else
		{
			cout<<"除法运算为：complex1+complex2="<<complex3._real<<complex3._immage<<"i"<<endl;
		}
		 complex3.~Complex ();
	}

void Complex:: operator+=(Complex &complex2)    //运算符“+=”重载，实现复数的加等；
{
	
	    _real = _real + complex2._real;
		_immage = _immage + complex2._immage ;
		if(_immage>0)
		{
			cout<<"加等运算为：complex1+=complex2="<<_real<<"+"<<_immage<<"i"<<endl;
		}
		else
		{
			cout<<"加等运算为：complex1+=complex2="<<_real<<_immage<<"i"<<endl;
		}
}

void  Complex:: operator-=(Complex &complex2)    //运算符“-=”重载，实现复数的减等；
{
	    _real = _real - complex2._real;
		_immage = _immage - complex2._immage ;
		if(_immage>0)
		{
			cout<<"减等运算为：complex1-=complex2="<<_real<<"+"<<_immage<<"i"<<endl;
		}
		else
		{
			cout<<"减等运算为：complex1-=complex2="<<_real<<_immage<<"i"<<endl;
		}
}

void  Complex:: operator*=(Complex &complex2)    //运算符“*=”重载，实现复数的乘等；
{
	
	     _real = (_real * complex2._real) - (_immage * complex2._immage);
		 _immage = (_immage * complex2._real) + (_real * complex2._immage ) ;
		if(_immage>0.0)
		{
			cout<<"乘等运算为：complex1*=complex2="<<_real<<"+"<<_immage<<"i"<<endl;
		}
		else
		{
			cout<<"乘等运算为：complex1*=complex2="<<_real<<_immage<<"i"<<endl;
		}
		
}

void  Complex:: operator/=(Complex &complex2)    //运算符“/=”重载，实现复数的除等；
{
	    float k=0;
		
		Complex complex4=Complex(0.0,0.0);
		k=(complex2._real* complex2._real)+(complex2._immage*complex2._immage );
		complex4._real = (_real*complex2._real )+(_immage*complex2._immage);
		complex4._immage  = (_real * -complex2._immage )+(_immage * complex2._real );
		_real =complex4._real/k; 
		_immage = complex4._immage /k ;
		if(_immage>0.0)
		{
			cout<<"除等运算为：complex1/=complex2="<<_real<<"+"<<_immage<<"i"<<endl;
		}
		else
		{
			cout<<"除等运算为：complex1/=complex2="<<_real<<_immage<<"i"<<endl;
		}
}

void test1()   //测试复数"+"重载函数
{
	Complex complex1=Complex(3.0,-5.00);
	Complex complex2=Complex(-1.0,-2.0);
	complex1.print(complex1);
	complex2.print(complex2);
    complex1.operator+(complex2);
	complex1.~Complex();
	complex2.~Complex();
}
void test2()    //测试复数“-”重载函数
{
    Complex complex1=Complex(3.0,-5.0);
	Complex complex2=Complex(-1.0,-2.0);
	complex1.print(complex1);
	complex2.print(complex2);
	complex1.operator-(complex2);
	complex1.~Complex();
	complex2.~Complex();
}
void test3()    //测试复数 “*”重载函数
{
	Complex complex1=Complex(3.0,-5.0);
	Complex complex2=Complex(-1.0,-2.0);
	complex1.print(complex1);
	complex2.print(complex2);
	complex1.operator*(complex2);
	complex1.~Complex();
	complex2.~Complex();
}
void test4()     //测试复数“/”重载函数；
{
    Complex complex1=Complex(3.0,-5.0);
	Complex complex2=Complex(-1.0,-2.0);
	complex1.print(complex1);
	complex2.print(complex2);
	complex1.operator/(complex2);
	complex1.~Complex();
	complex2.~Complex();
}
void test5()           //测试复数“+=”重载函数
{
	Complex complex1=Complex(3.0,-5.0);
	Complex complex2=Complex(-1.0,-2.0);
	complex1.print(complex1);
	complex2.print(complex2);
	complex1.operator+=(complex2);
	complex1.~Complex();
	complex2.~Complex();
}
void test6()               //测试复数“-=”重载函数
{
	Complex complex1=Complex(3.0,-5.0);
	Complex complex2=Complex(-1.0,-2.0);
	complex1.print(complex1);
	complex2.print(complex2);
	complex1.operator-=(complex2);
	complex1.~Complex();
	complex2.~Complex();
}

void test7()              //测试复数“*=”重载函数
{
	Complex complex1=Complex(3.0,-5.0);
	Complex complex2=Complex(-1.0,-2.0);
	complex1.print(complex1);
	complex2.print(complex2);
	complex1.operator*=(complex2);
	complex1.~Complex();
	complex2.~Complex();
}

void test8()                   //测试复数“/=”重载函数
{
	Complex complex1=Complex(3.0,-5.0);
	Complex complex2=Complex(-1.0,-2.0);
	complex1.print(complex1);
	complex2.print(complex2);
	complex1.operator/=(complex2);
	complex1.~Complex();
	complex2.~Complex();
}


int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
system("pause");
return 0;
}


