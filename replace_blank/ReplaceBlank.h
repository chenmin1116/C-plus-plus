#include<iostream>
#include<cassert>
#include<string>
using namespace std;
//˼·������
//1.�����ַ������飬�����г��ֵĿո��û�Ϊ%20��Ҳ����%�Ϳո��ASCII��ֵ��
//1.�ж�����Ĵ�С�Ƿ�����ַ��ĸ���+2*CountSize�Ĵ�С��
//2.����ͳ�Ƴ��ַ�������Ӧ�ո���Ŀ��
//3.�������ݣ�AddCapacity = CountBlank * 3;
//4.һ��ָ��ָ�����ݺ�Ŀռ�ĩβ��һ��ָ���ַ�����β��


//����������Ĵ�С�����ڵ����ַ��ĸ���+2*CountSize;
void _ReplaceBlank(char ptr[],int size)
{
    int CountBlank = 0;
	for(int i=0;i<size;++i)
	{
		if(ptr[i] == ' ')
			CountBlank++;
	}
    int NewSize = size + 2*CountBlank;
	char* tmp = new char[NewSize];
	for(int i = 0;i<size;++i)
	{
		tmp[i] = ptr[i];
	}
	char* first = tmp+size-1;
	char* second = tmp+NewSize-1;
	while( first < second && CountBlank--)
	{
		while(*first != ' ')
		{
			*second = *first;
			--first;
			--second;
		}
		if(*first-- = ' ')
		{
			*second-- = '0';
		    *second-- = '2';
		    *second-- = '%';
		}
	}
	ptr = new char[NewSize];
	memcpy(ptr,tmp,sizeof(char)*NewSize);
	for(int i=0;i<NewSize;++i)
	{
		cout<<ptr[i];
	}
	cout<<endl;
}

void ReplaceBlank(char ptr[],int size,int capacity)
{
	assert(ptr);     //ptrΪ������ʱ��������
	int CountBlank = 0;
	for(int i=0;i<size;++i)
	{
		if(ptr[i] == ' ')
			CountBlank++;
	}
    int NewSize = size + 2*CountBlank;
	if(capacity >=NewSize)
	{
		//ʹ������ָ����д���
		char* first = ptr+size-1;
		char*second = ptr+NewSize-1;
		while( first < second && CountBlank--)
	    {
			while(*first != ' ')
			{
				*second = *first;
				--first;
				--second;
			}
			if(*first-- = ' ')
			{
				*second-- = '0';
				*second-- = '2';
				*second-- = '%';
			}
	   }
		for(int i=0;i<NewSize;++i)
	    {
		    cout<<ptr[i];
	    }
	    cout<<endl;
	}
	else
	{
		_ReplaceBlank(ptr,size);
	}
}

void TestReplaceBlank()
{
	char ptr[19]="we are happy.";
    char ptr1[] = "   ";//�����ո�
	char ptr2[] = "we are happpy   .   ";//ǰ��һ���ո�happy����3���ո�.����3���ո�
	char ptr3[] = "";
	int size = strlen(ptr);
	int size1 = strlen(ptr1);
	int size2 = strlen(ptr2);
	int size3 = strlen(ptr3);
    ReplaceBlank(ptr,size,19);
    ReplaceBlank(ptr1,size1,size1);
	ReplaceBlank(ptr2,size2,size2);
	ReplaceBlank(ptr2,size3,size3);

}