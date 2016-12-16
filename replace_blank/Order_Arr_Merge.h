//有两个排序的数组A1和A2，内存在A1的末尾有足够的空余空间容纳A2。
//请实现一个函数，把A2中所有的数字插入到A1中并且所有的数字是排序的。
#pragma once
#include<iostream>
#include<cassert>
using namespace std;

//当arr1中的闲余空间可以容纳arr2时；
void _OrderArryMerge1(int* arr1,int* arr2,int size1,int size2)
{
	int NewSize = size1+size2;
	int* ptr1 = arr1+size1-1;
	int* ptr2 = arr2+size2-1;
	int* ptr = arr1+NewSize-1;
	while(ptr1 != arr1 && ptr2 != arr2 || ptr2 != arr2)
	{
		if(ptr1 != arr1 && ptr2 != arr2)   //如果两个数组都没有到头
		{
			if(*ptr1 >= *ptr2)
			{
				*ptr-- = *ptr1--;
			}
			else
			{
				*ptr-- = *ptr2--;
			}

		}
		else
		{
			if(ptr2 != arr2)           //如果arr1数组到头了，直接将arr2剩余元素直接拷贝过去即可；
			{
				while(ptr2 > arr2)
				{
					*ptr-- = *ptr2--;
				}
			}
			if(ptr1 != arr1)          //如果arr2数组到头了，直接停止操作即可
			{
				break;
			}
			if(ptr1 == arr1 && ptr2 == arr2)
			{
				if(*ptr1 >= *ptr2)
			    {
					*ptr-- = *ptr1;
					*ptr = *ptr2;
				}
				else
				{
					*ptr-- = *ptr2;
					*ptr = *ptr1;
				}

			}
		}
	}
    for(int i=0;i<NewSize;++i)
	{
		cout<<arr1[i]<<" ";
	}
	cout<<endl;

}

//当arr1中的闲余空间不足以容纳arr2时；
void  _OrderArryMerge2(int* arr1,int* arr2,int size1,int size2)
{
	//开辟一块可以存放arr1和arr2的空间，用来转换；
	//转换时可以从前向后也可以从后向前，但是为了代码的复用还是进行从后向前；
	//将开辟的空间赋给arr1即可；
	int NewSize =0;
	//处理arr1位空并且arr2不为空；
	if(arr1 == NULL)
	{
		cout<<"arr1为空<<";
		NewSize = size2;
		int *arr1 = new int[NewSize];
		for(int i=0;i<NewSize;++i)
		{
			arr1[i] = arr2[i];
		}
		for(int i=0;i<NewSize;++i)
		{
			cout<<arr1[i]<<" ";
		}
		cout<<endl;
	}
	//处理arr1和arr2都不为空
		
	else
	{
		NewSize = size1 + size2;
		int *tmp = new int[NewSize];
		int *ptr1 = arr1;
		int *ptr2 = arr2;
		int *ptr = tmp;
		while(ptr1 != arr1+size1 || ptr2 != arr2+size2 )  
		{
			if(ptr1 != arr1+size1 && ptr2 != arr2+size2)   //两个数组都没有到头时；
			{
				if(*ptr1 < *ptr2)
				{
					*ptr++ = *ptr1++;

				}
				else
				{
					*ptr++ = *ptr2++;
				}
			}
			else
			{
				if(ptr1 != arr1+size1)       //数组arr2走到了头
				{
					while(ptr1 != arr1+size1)
					{
						*ptr++= *ptr1++;
					}
				}
				if(ptr2 != arr2+size2)      //数组arr1走到了头
				{
					while(ptr2 != arr2+size2)
					{
						*ptr++ = *ptr2++;
					}
				}
			}
		}
		//将tmp赋给arr1;
		memcpy(arr1,tmp,sizeof(int)*NewSize);
		delete []tmp;
		tmp = NULL;
		for(int i=0;i<NewSize;++i)
		{
			cout<<arr1[i]<<" ";
		}
		cout<<endl;
	}
}

void OrderArryMerge(int *arr1,int* arr2,int size1,int size2,int capacity1)
{
	if( arr1==NULL && arr2==NULL )
	{
		cout<<"两个数组均为空"<<endl;
		return;
	}
	//当arr1中的闲余空间可以容纳arr2时；
	if(arr1 != NULL && arr2 == NULL)
	{
		cout<<"arr2为空<<";
		for(int i=0;i<size1;++i)
		{
			cout<<arr1[i]<<" ";
		}
		cout<<endl;
		return;
	}
	if(capacity1 >= size1+size2)
	{
		_OrderArryMerge1(arr1,arr2,size1,size2);
	}
	
	//当arr1中的闲余空间不足以容纳arr2时；
	else
	{
		_OrderArryMerge2(arr1,arr2,size1,size2);
	}
}

void  TestOrderArryMerge()
{
	int arr1[]={1,3,5};
	int arr2[]={0,2,4,6,8};
	int *arr3=NULL;
	int *arr4=NULL;
	int arr5[12] = {1,3,5,7,9};
	int arr6[]={0,2,4,6};
	int arr7[]={1,2,3,10};
	int *arr8 = NULL;
	int *arr9 = NULL;
	int arr10[] = {11,12,15,45};
	int size1 = sizeof(arr1)/sizeof(arr1[0]);
	int size2 = sizeof(arr2)/sizeof(arr2[0]);
	int size3 = sizeof(arr3)/sizeof(arr3[0]);
	int size4 = sizeof(arr4)/sizeof(arr4[0]);
	int size5 = sizeof(arr5)/sizeof(arr5[0]);
	int size6 = sizeof(arr6)/sizeof(arr6[0]);
	int size7 = sizeof(arr7)/sizeof(arr7[0]);
	int size8 = sizeof(arr8)/sizeof(arr8[0]);
	int size9 = sizeof(arr9)/sizeof(arr9[0]);
	int size10 = sizeof(arr10)/sizeof(arr10[0]);
    OrderArryMerge(arr1,arr2,size1,size2,size1);          //测试当arr1的数组闲余空间不足以存放arr2时；
    OrderArryMerge(arr3,arr4,size3,size4,size3);          //测试当两个数组都为空的时候；
	OrderArryMerge(arr5,arr6,5,4,12);             //测试当arr1的数组的闲余空间足以存放arr2时；
    OrderArryMerge(arr7,arr8,size7,size8,size7);             //测试当arr1不为空且arr2为空时；
    OrderArryMerge(arr9,arr10,size9,size10,size9);          //测试当arr1为空时且arr2不为空；
}	