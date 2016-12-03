//1.дһ�������ࡣ
//2.��C++�鼮����Ͷ��󲿷֡�
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<cstdio>
#include<math.h>

class Complex                  //����Complex�ࣻ
	{
		private:
			float _real;
			float _immage;
		public:
			Complex(float real,float immage);
			
			~Complex()
			{}
			
			void print(Complex complex);
		
			void  operator+(Complex &complex2);  //�������+�����أ�ʵ�ָ����ļӷ���
			
		    void  operator-(Complex &complex2);     //�������-�����أ�ʵ�ָ����ļ�����
			
			void  operator*(Complex &complex2);     //�������*�����أ�ʵ�ָ����ĳ˷���
			
			void  operator/(Complex &complex2);    //�������/�����أ�ʵ�ָ����ĳ�����
			 
			void  operator+=(Complex &complex2);    //�������+=�����أ�ʵ�ָ����ĳ�����

			void  operator-=(Complex &complex2);    //�������-=�����أ�ʵ�ָ����ĳ�����

			void  operator*=(Complex &complex2);    //�������*=�����أ�ʵ�ָ����ĳ�����

			void  operator/=(Complex &complex2);    //�������/=�����أ�ʵ�ָ����ĳ�����
			
			
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

void  Complex::operator+(Complex &complex2)  //�������+�����أ�ʵ�ָ����ļӷ���
	{
		Complex complex3=Complex(0.0,0.0);
		complex3._real = _real + complex2._real;
		complex3._immage = _immage + complex2._immage ;
		if(complex3._immage>0)
		{
			cout<<"�ӷ�����Ϊ��complex1+complex2="<<complex3._real<<"+"<<complex3._immage<<"i"<<endl;
		}
		else
		{
			cout<<"�ӷ�����Ϊ��complex1+complex2="<<complex3._real<<complex3._immage<<"i"<<endl;
		}
		complex3.~Complex ();
		
	}

void  Complex:: operator-(Complex &complex2)     //�������-�����أ�ʵ�ָ����ļ�����
	{
		Complex complex3=Complex(0.0,0.0);
		complex3._real = _real - complex2._real;
		complex3._immage = _immage - complex2._immage ;
		if(complex3._immage>0.0)
		{
			cout<<"��������Ϊ��complex1+complex2="<<complex3._real<<"+"<<complex3._immage<<"i"<<endl;
		}
		else
		{
			cout<<"��������Ϊ��complex1+complex2="<<complex3._real<<complex3._immage<<"i"<<endl;
		}
		complex3.~Complex ();
	}
			
void  Complex:: operator*(Complex &complex2)     //�������*�����أ�ʵ�ָ����ĳ˷���
	{
		Complex complex3=Complex(0.0,0.0);
		complex3._real = (_real * complex2._real) - (_immage * complex2._immage);
		complex3._immage = (_immage * complex2._real) + (_real * complex2._immage ) ;
		if(complex3._immage>0.0)
		{
			cout<<"�˷�����Ϊ��complex1+complex2="<<complex3._real<<"+"<<complex3._immage<<"i"<<endl;
		}
		else
		{
			cout<<"�˷�����Ϊ��complex1+complex2="<<complex3._real<<complex3._immage<<"i"<<endl;
		}
		 complex3.~Complex ();

	}

void  Complex:: operator/(Complex &complex2)      //�������/�����أ�ʵ�ָ����ĳ�����
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
			cout<<"��������Ϊ��complex1+complex2="<<complex3._real<<"+"<<complex3._immage<<"i"<<endl;
		}
		else
		{
			cout<<"��������Ϊ��complex1+complex2="<<complex3._real<<complex3._immage<<"i"<<endl;
		}
		 complex3.~Complex ();
	}

void Complex:: operator+=(Complex &complex2)    //�������+=�����أ�ʵ�ָ����ļӵȣ�
{
	
	    _real = _real + complex2._real;
		_immage = _immage + complex2._immage ;
		if(_immage>0)
		{
			cout<<"�ӵ�����Ϊ��complex1+=complex2="<<_real<<"+"<<_immage<<"i"<<endl;
		}
		else
		{
			cout<<"�ӵ�����Ϊ��complex1+=complex2="<<_real<<_immage<<"i"<<endl;
		}
}

void  Complex:: operator-=(Complex &complex2)    //�������-=�����أ�ʵ�ָ����ļ��ȣ�
{
	    _real = _real - complex2._real;
		_immage = _immage - complex2._immage ;
		if(_immage>0)
		{
			cout<<"��������Ϊ��complex1-=complex2="<<_real<<"+"<<_immage<<"i"<<endl;
		}
		else
		{
			cout<<"��������Ϊ��complex1-=complex2="<<_real<<_immage<<"i"<<endl;
		}
}

void  Complex:: operator*=(Complex &complex2)    //�������*=�����أ�ʵ�ָ����ĳ˵ȣ�
{
	
	     _real = (_real * complex2._real) - (_immage * complex2._immage);
		 _immage = (_immage * complex2._real) + (_real * complex2._immage ) ;
		if(_immage>0.0)
		{
			cout<<"�˵�����Ϊ��complex1*=complex2="<<_real<<"+"<<_immage<<"i"<<endl;
		}
		else
		{
			cout<<"�˵�����Ϊ��complex1*=complex2="<<_real<<_immage<<"i"<<endl;
		}
		
}

void  Complex:: operator/=(Complex &complex2)    //�������/=�����أ�ʵ�ָ����ĳ��ȣ�
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
			cout<<"��������Ϊ��complex1/=complex2="<<_real<<"+"<<_immage<<"i"<<endl;
		}
		else
		{
			cout<<"��������Ϊ��complex1/=complex2="<<_real<<_immage<<"i"<<endl;
		}
}

void test1()   //���Ը���"+"���غ���
{
	Complex complex1=Complex(3.0,-5.00);
	Complex complex2=Complex(-1.0,-2.0);
	complex1.print(complex1);
	complex2.print(complex2);
    complex1.operator+(complex2);
	complex1.~Complex();
	complex2.~Complex();
}
void test2()    //���Ը�����-�����غ���
{
    Complex complex1=Complex(3.0,-5.0);
	Complex complex2=Complex(-1.0,-2.0);
	complex1.print(complex1);
	complex2.print(complex2);
	complex1.operator-(complex2);
	complex1.~Complex();
	complex2.~Complex();
}
void test3()    //���Ը��� ��*�����غ���
{
	Complex complex1=Complex(3.0,-5.0);
	Complex complex2=Complex(-1.0,-2.0);
	complex1.print(complex1);
	complex2.print(complex2);
	complex1.operator*(complex2);
	complex1.~Complex();
	complex2.~Complex();
}
void test4()     //���Ը�����/�����غ�����
{
    Complex complex1=Complex(3.0,-5.0);
	Complex complex2=Complex(-1.0,-2.0);
	complex1.print(complex1);
	complex2.print(complex2);
	complex1.operator/(complex2);
	complex1.~Complex();
	complex2.~Complex();
}
void test5()           //���Ը�����+=�����غ���
{
	Complex complex1=Complex(3.0,-5.0);
	Complex complex2=Complex(-1.0,-2.0);
	complex1.print(complex1);
	complex2.print(complex2);
	complex1.operator+=(complex2);
	complex1.~Complex();
	complex2.~Complex();
}
void test6()               //���Ը�����-=�����غ���
{
	Complex complex1=Complex(3.0,-5.0);
	Complex complex2=Complex(-1.0,-2.0);
	complex1.print(complex1);
	complex2.print(complex2);
	complex1.operator-=(complex2);
	complex1.~Complex();
	complex2.~Complex();
}

void test7()              //���Ը�����*=�����غ���
{
	Complex complex1=Complex(3.0,-5.0);
	Complex complex2=Complex(-1.0,-2.0);
	complex1.print(complex1);
	complex2.print(complex2);
	complex1.operator*=(complex2);
	complex1.~Complex();
	complex2.~Complex();
}

void test8()                   //���Ը�����/=�����غ���
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


