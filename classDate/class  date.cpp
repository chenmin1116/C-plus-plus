//��������ࣺ
//Ҫ��ʵ�֣�
//���캯��
//��������
//�������캯��
//��ֵ���������
//����+-����
//����-����
#include<iostream>
using namespace std;
#include<cstdio>

class Date
{
private:
	int _year;
	int _month;
	int _day;
public:
	~Date();                                   //��������
	void print();             //��ӡ����
	Date(int year,int month,int day  );        //���캯��
	Date(const Date &date2);                   //�������캯��
	Date& operator=(Date &date2);              //��ֵ���������
	Date operator+(int days);                  //����+������+���������
	Date operator-(int days);                  //����-������-���������
	int  operator-(Date &date2);             //����-���ڣ�-���������

};

int days_arry[12]={31,28,31,30,31,30,31,31,30,31,30,31};

Date::~Date()                                  //��������
{

}
void Date::print()
{
	cout<<this->_year <<"--"<<this->_month <<"--"<<this->_day <<endl;
}


Date::Date(int year=1999,int month=1,int day=1  )   //���캯��
{
	this->_year = year;
	this->_month = month;
	this->_day = day;
}


Date::Date(const Date &date2)                   //�������캯��
{
	this->_year = date2._year ;
	this->_month = date2._month ;
	this->_day = date2._day ;
}


Date& Date:: operator=(Date &date2)              //��ֵ���������
{
	this->_year = date2._year ;
	this->_month = date2._month ;
	this->_day = date2._day ;
	return *this;
}


Date Date:: operator+(int days)               //����+������+���������
{
	while(this->_day+days >= days_arry[this->_month -1])
	{
		this->_day = this->_day + days - days_arry[this->_month -1];
		this->_month =this->_month +1;
		if(this->_month == 12)
		{
			this->_year +=1;
		}
	}
	return *this;
}


Date Date:: operator-(int days)                //����-������-���������
{
	if(this->_day >= days)
	{
		this->_day  = this->_day - days;
		return *this;
	}
	else
	{
		this->_day = this->_day + days_arry[this->_month-1] - days;
		this->_month = this->_month -1;
		return *this;
	}

}


int  Date:: operator-(Date &date2)               //����-���ڣ�-���������
{
	int days=0;
	int i=0;
	if(this->_year == date2._year )             //ͬ���������
	{
		if((this->_year %4 == 0&&this->_year%100 != 0) ||(this->_year %400 == 0 ))  //ͬ����Ϊ����
		{
			for(i = date2._month ;i>this->_month ;i--)
			{
				days = days + days_arry[i-1];

			}
			if((this->_month <= 2) && (date2._month >2))
			{
				days = days + date2._day - this->_day +1;//��һ�Ǵ���������¶������һ��
			}
			else
			{
				days = days + date2._day - this->_day;
			}
			return days;
		}
		else                                                 //ͬһ����Ϊƽ��
		{
			for(i = date2._month ;i>this->_month ;i--)
			{
				days = days + days_arry[i-1];

			}
			days = days + date2._day - this->_day ;

			return days;
		}

	}
	if(this->_year < date2._year)
	{
		if((this->_month >2)&&(date2._month <2))
		{
			for(i = this->_month;i <= 12;i++)
			{
				days =days + days_arry[i-1];
			}
			days = days +days_arry[0];
			days = days+date2._day -this->_day ;
			return days;
		}
		if((this->_month >2)&&(date2._month=2))
		{
			if(((date2._year %4 == 0)&&(date2._year %100 != 0))||(date2._year % 400 ==0))    //������
			{
				for(i = this->_month ;i <= 12; i++)
				{
					days = days_arry[i-1];
				}
				days = days + days_arry[0]+days_arry[1]+1;
				days = days + date2._day -this->_day ;
				return days;
			}
			else
			{
				for(i = this->_month ;i<=12; i++)
				{
					days = days_arry[i-1];
				}
				days = days + days_arry[0]+days_arry[1];
				days = days + date2._day -this->_day ;
				return days;
			}
		}
		if((this->_month >2)&&(date2._month >2))
		{
			if(((date2._year %4 == 0)&&(date2._year %100 != 0))||(date2._year % 400 ==0))   //������
			{
				for(i = this->_month ;i<=12;i++)
				{
					days = days + days_arry[i-1] ;
				}
				for(i = date2._month ;i>0;i--)
				{
					days = days + days_arry[i-1];
				}
				days = days + date2._day -this->_day+1 ;
				return days;
			}
			else
			{
				for(i=this->_month ;i<=12;i++)
				{
					days=days + days_arry[i-1];
				}
				for(i=date2._month ;i>0;i--)
				{
					days = days +days_arry[i-1];
				}
				days = days +date2._day - this->_day;
				return days;
			}
		}
		if((this->_month <= 2)&&(date2._month < 2))
		{
			if(((this->_year %4 == 0)&&(this->_year %100 != 0))||(this->_year % 400 ==0))  //������
			{
				for(i = this->_month ;i<=12;i++)
				{
					days = days + days_arry[i-1];
				}
				for(i=this->_month ;i>0;i--)
				{
					days = days + days_arry[i-1];
				}
				days = days+date2._day -this->_day+1 ;
				return days;
			}
			else
			{
				for(i = this->_month ;i<=12;i++)
				{
					days = days + days_arry[i-1];
				}
				for(i=this->_month ;i>0;i--)
				{
					days = days + days_arry[i-1];
				}
				days = days+date2._day -this->_day ;
				return days;
			}
		}
		if((this->_month <= 2)&&(date2._month = 2))
		{
           if(((this->_year %4 == 0)&&(this->_year %100 != 0))||(this->_year % 400 ==0))  //this->_year������
		   {
			   if(((date2._year %4 == 0)&&(date2._year %100 != 0))||(date2._year % 400 ==0))   //date2._year������
			   {
				   for(i = this->_month ;i<=12;i++)
				   {
					   days = days + days_arry[i];
				   }
				   for(i=date2._month ;i>0;i--)
				   {
					   days=days + days_arry[i];
				   }
				   days = days +date2._day - this->_day +2;
				   return days;
			   }
			   else                 //date2._year ��������
			   {
                   for(i = this->_month ;i<=12;i++)
					{
						days = days + days_arry[i];
					}
				   for(i=date2._month ;i>0;i--)
				   {
					   days=days + days_arry[i];
				   }
				   days = days +date2._day - this->_day +1;
				   return days;
			   }
		   }
		   else
		   {
                 for(i = this->_month ;i<=12;i++)
					{
						days = days + days_arry[i];
					}
				   for(i=date2._month ;i>0;i--)
				   {
					   days=days + days_arry[i];
				   }
				   days = days +date2._day - this->_day +1;
				   return days;
		   }
		}
		if((this->_month <= 2)&&(date2._month > 2))
		{
           if(((this->_year %4 == 0)&&(this->_year %100 != 0))||(this->_year % 400 ==0))  //this->_year������
		   {
		    for(i = this->_month ;i<=12;i++)
					{
						days = days + days_arry[i];
					}
				   for(i=date2._month ;i>0;i--)
				   {
					   days=days + days_arry[i];
				   }
				   days = days +date2._day - this->_day +1;
				   return days;
		   }
		}
		else
		{
			 for(i = this->_month ;i<=12;i++)
					{
						days = days + days_arry[i];
					}
				   for(i=date2._month ;i>0;i--)
				   {
					   days=days + days_arry[i];
				   }
				   days = days +date2._day - this->_day ;
				   return days;
		}
    }
}

void test1()
{
    Date ret1=Date();
	Date date1=Date(2016,7,28);
	ret1=date1.operator+(10);
	ret1.print ();
}

void test2()
{
	Date ret2=Date();
	Date date1=Date(2016,7,28);
	ret2=date1.operator-(5);
	ret2.print ();
}

void test3()
{
	int ret3 = 0;
	Date date1=Date(2016,1,28);
	Date date2=Date(2016,2,8);
	ret3=date1.operator-(date2);
	cout<<"date1-date2������Ϊ��"<<ret3<<endl;
}

int main()
{
	test1();
	test2();
	test3();
	system("pause");
	return 0;
}

