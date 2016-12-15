#include<iostream>
#include<cassert>
#include<string>
using namespace std;
//思路分析：
//1.对于字符串数组，将其中出现的空格置换为%20，也就是%和空格的ASCII码值；
//1.判断数组的大小是否大于字符的个数+2*CountSize的大小；
//2.首先统计出字符串所对应空格数目；
//3.进行增容，AddCapacity = CountBlank * 3;
//4.一个指针指向增容后的空间末尾，一个指向字符串的尾；


//当所给数组的大小不大于等于字符的个数+2*CountSize;
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
	assert(ptr);     //ptr为空数组时，不处理
	int CountBlank = 0;
	for(int i=0;i<size;++i)
	{
		if(ptr[i] == ' ')
			CountBlank++;
	}
    int NewSize = size + 2*CountBlank;
	if(capacity >=NewSize)
	{
		//使用两个指针进行处理
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
    char ptr1[] = "   ";//三个空格
	char ptr2[] = "we are happpy   .   ";//前面一个空格，happy后面3个空格，.后面3个空格。
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