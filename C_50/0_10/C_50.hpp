//1.ʹ��C��д��������Ļ�������hello��world!��
#include<iostream>
#include<cmath>
using namespace std;

void PrintHW()
{
	char* ptr = "hello,world!";
	printf("��һ�⣺%s\n",ptr);
}

//2.(ѭ��)ʹ��C���Ա�д���򣬼���1.2.3.....100��100�������ĺͣ�

void Sum()
{
	int sum =0;
	for(int i=1;i<=100;++i)
	{
		sum = sum +i;
	}
	cout<<"�ڶ��⣺"<<sum<<endl;
}

//3.(ѭ��)ʹ��C���Ա�д��������Ļ�ϴ�ӡ�žų˷��ھ���

void PrintMultiplicationTable()
{
	cout<<"�����⣺"<<endl;
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

//4.����֧�жϣ�ʹ��C���Ա�д���������������Ľϴ�ֵ��

void FindMax2(int x,int y)
{
	cout<<"�����⣺";
	int max = x;
	if(x<y)
		max = y;
	//max = x>y?x:y;
	cout<<"The max between 2 integer is "<<max<<endl;
	
}

//5.(ѭ��)ʹ��C���Ա�д������10������������ֵ��
void FindMax10(int* arr,int size)
{
	cout<<"�����⣺";
	int max = arr[0];
	for(int i=1;i<size;++i)
	{
		if(arr[i] > max )
			max = arr[i];
	}
	cout<<"The max between 10 integer  is "<<max<<endl;
}

//6.(ѭ��.��֧)ʹ��C���Ա�д������1-100֮���������
//2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 
void Prime()
{
	cout<<"������: ";
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


//7.(շת���)ʹ��C���Ա�д�������������������Լ��
void GreatestCommonDivisor(int n1,int n2)
{}

//8.ʹ��C���Ա�д����������������С������
void LeastCommonMultiple(int n1,int n2)
{}

//9.ʹ��C���Ա�д���򣬽�������������ֵ
void Swap1(int n1,int n2)
{
	cout<<"�ھ��⣨��Ч����"<<"n1 = "<<n1<<" n2 = "<<n2<<"//";
    int temp = n1;
	n1 = n2;
	n2 = temp;
	cout<<"n1 = "<<n1<<" n2 = "<<n2<<endl;

}

void Swap2(int n1,int n2)
{
	cout<<"�ھ���(��Ч)��"<<"n1 = "<<n1<<" n2 = "<<n2<<"//";
	n1 = n1 + n2; //n1 = n1 * n2;//n1 = n1^n2;
	n2 = n1 - n2;   //n2 = n1/n2;  //n2 = *n1^n2;
	n1 = n1 - n2;   //n1 = n1/n2;  //n1 = n1^n2;
	cout<<"n1 = "<<n1<<" n2 = "<<n2<<endl;
}

//10.����ַ��ʹ��C���Ա�д�����������Ĺ��ܣ���������������ֵ��
void SwapAddress1(int* n1,int* n2)
{
	cout<<"��ʮ�⣨��Ч����"<<"n1 = "<<*n1<<" n2 = "<<*n2<<"//";
    int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
	cout<<"n1 = "<<*n1<<" n2 = "<<*n2<<endl;

}

void SwapAddress2(int* n1,int* n2)
{
	cout<<"��ʮ��(��Ч)��"<<"n1 = "<<*n1<<" n2 = "<<*n2<<"//";
	*n1 = *n1 + *n2; //*n1 = *n1 * *n2;//*n1 = *n1^*n2;
	*n2 = *n1 - *n2;   //*n2 = *n1/*n2;  //*n2 = *n1^*n2;
	*n1 = *n1 - *n2;   //*n1 = *n1/*n2;  //*n1 = *n1^*n2;
	cout<<"n1 = "<<*n1<<" n2 = "<<*n2<<endl;
}


