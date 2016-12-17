//1.使用C编写程序，在屏幕上输出“hello，world!”
#include<iostream>
#include<cmath>
using namespace std;

void PrintHW()
{
	char* ptr = "hello,world!";
	printf("第一题：%s\n",ptr);
}

//2.(循环)使用C语言编写程序，计算1.2.3.....100这100个整数的和；

void Sum()
{
	int sum =0;
	for(int i=1;i<=100;++i)
	{
		sum = sum +i;
	}
	cout<<"第二题："<<sum<<endl;
}

//3.(循环)使用C语言编写程序，在屏幕上打印九九乘法口诀表；

void PrintMultiplicationTable()
{
	cout<<"第三题："<<endl;
	for(int i =0;i<10;++i)
	{
		for(int j= 0;j<10;++j)
		{
			printf("%d*%d = %d ",i,j,i*j);
			if(i == j)
			{
				break;
			}
		}
		printf("\n");
	}
}

//4.（分支判断）使用C语言编写程序，求两个整数的较大值；

void FindMax2(int x,int y)
{
	cout<<"第四题：";
	int max = x;
	if(x<y)
		max = y;
	//max = x>y?x:y;
	cout<<"The max between 2 integer is "<<max<<endl;
	
}

//5.(循环)使用C语言编写程序，求10个整数中最大的值；
void FindMax10(int* arr,int size)
{
	cout<<"第五题：";
	int max = arr[0];
	for(int i=1;i<size;++i)
	{
		if(arr[i] > max )
			max = arr[i];
	}
	cout<<"The max between 10 integer  is "<<max<<endl;
}

//6.(循环.分支)使用C语言编写程序，求1-100之间的素数。
//2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 
void Prime()
{
	cout<<"第六题: ";
	for(int i=2;i<=100;++i)
	{
		int k= (int)sqrt((float)i);
		for(int j=0;j<=k;++j)
		{
			if(i%j == 0)
				break;
			else
			{
				if(j == k)
					cout<<i<<" ";
			}
		}
	 }

	cout<<endl;
}


//7.(辗转相除)使用C语言编写程序，求两个整数的最大公约数
void GreatestCommonDivisor(int n1,int n2)
{}

//8.使用C语言编写程序，求两个数的最小公倍数
void LeastCommonMultiple(int n1,int n2)
{}

//9.使用C语言编写程序，交换两个整数的值
void Swap1(int n1,int n2)
{
	cout<<"第九题（低效）："<<"n1 = "<<n1<<" n2 = "<<n2<<"//";
    int temp = n1;
	n1 = n2;
	n2 = temp;
	cout<<"n1 = "<<n1<<" n2 = "<<n2<<endl;

}

void Swap2(int n1,int n2)
{
	cout<<"第九题(高效)："<<"n1 = "<<n1<<" n2 = "<<n2<<"//";
	n1 = n1 + n2; //n1 = n1 * n2;//n1 = n1^n2;
	n2 = n1 - n2;   //n2 = n1/n2;  //n2 = *n1^n2;
	n1 = n1 - n2;   //n1 = n1/n2;  //n1 = n1^n2;
	cout<<"n1 = "<<n1<<" n2 = "<<n2<<endl;
}

//10.（传址）使用C语言编写函数，函数的功能：交换两个整数的值；
void SwapAddress1(int* n1,int* n2)
{
	cout<<"第十题（低效）："<<"n1 = "<<*n1<<" n2 = "<<*n2<<"//";
    int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
	cout<<"n1 = "<<*n1<<" n2 = "<<*n2<<endl;

}

void SwapAddress2(int* n1,int* n2)
{
	cout<<"第十题(高效)："<<"n1 = "<<*n1<<" n2 = "<<*n2<<"//";
	*n1 = *n1 + *n2; //*n1 = *n1 * *n2;//*n1 = *n1^*n2;
	*n2 = *n1 - *n2;   //*n2 = *n1/*n2;  //*n2 = *n1^*n2;
	*n1 = *n1 - *n2;   //*n1 = *n1/*n2;  //*n1 = *n1^*n2;
	cout<<"n1 = "<<*n1<<" n2 = "<<*n2<<endl;
}


