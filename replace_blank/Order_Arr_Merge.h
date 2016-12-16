//���������������A1��A2���ڴ���A1��ĩβ���㹻�Ŀ���ռ�����A2��
//��ʵ��һ����������A2�����е����ֲ��뵽A1�в������е�����������ġ�
#pragma once
#include<iostream>
#include<cassert>
using namespace std;

//��arr1�е�����ռ��������arr2ʱ��
void _OrderArryMerge1(int* arr1,int* arr2,int size1,int size2)
{
	int NewSize = size1+size2;
	int* ptr1 = arr1+size1-1;
	int* ptr2 = arr2+size2-1;
	int* ptr = arr1+NewSize-1;
	while(ptr1 != arr1 && ptr2 != arr2 || ptr2 != arr2)
	{
		if(ptr1 != arr1 && ptr2 != arr2)   //����������鶼û�е�ͷ
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
			if(ptr2 != arr2)           //���arr1���鵽ͷ�ˣ�ֱ�ӽ�arr2ʣ��Ԫ��ֱ�ӿ�����ȥ���ɣ�
			{
				while(ptr2 > arr2)
				{
					*ptr-- = *ptr2--;
				}
			}
			if(ptr1 != arr1)          //���arr2���鵽ͷ�ˣ�ֱ��ֹͣ��������
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

//��arr1�е�����ռ䲻��������arr2ʱ��
void  _OrderArryMerge2(int* arr1,int* arr2,int size1,int size2)
{
	//����һ����Դ��arr1��arr2�Ŀռ䣬����ת����
	//ת��ʱ���Դ�ǰ���Ҳ���ԴӺ���ǰ������Ϊ�˴���ĸ��û��ǽ��дӺ���ǰ��
	//�����ٵĿռ丳��arr1���ɣ�
	int NewSize =0;
	//����arr1λ�ղ���arr2��Ϊ�գ�
	if(arr1 == NULL)
	{
		cout<<"arr1Ϊ��<<";
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
	//����arr1��arr2����Ϊ��
		
	else
	{
		NewSize = size1 + size2;
		int *tmp = new int[NewSize];
		int *ptr1 = arr1;
		int *ptr2 = arr2;
		int *ptr = tmp;
		while(ptr1 != arr1+size1 || ptr2 != arr2+size2 )  
		{
			if(ptr1 != arr1+size1 && ptr2 != arr2+size2)   //�������鶼û�е�ͷʱ��
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
				if(ptr1 != arr1+size1)       //����arr2�ߵ���ͷ
				{
					while(ptr1 != arr1+size1)
					{
						*ptr++= *ptr1++;
					}
				}
				if(ptr2 != arr2+size2)      //����arr1�ߵ���ͷ
				{
					while(ptr2 != arr2+size2)
					{
						*ptr++ = *ptr2++;
					}
				}
			}
		}
		//��tmp����arr1;
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
		cout<<"���������Ϊ��"<<endl;
		return;
	}
	//��arr1�е�����ռ��������arr2ʱ��
	if(arr1 != NULL && arr2 == NULL)
	{
		cout<<"arr2Ϊ��<<";
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
	
	//��arr1�е�����ռ䲻��������arr2ʱ��
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
    OrderArryMerge(arr1,arr2,size1,size2,size1);          //���Ե�arr1����������ռ䲻���Դ��arr2ʱ��
    OrderArryMerge(arr3,arr4,size3,size4,size3);          //���Ե��������鶼Ϊ�յ�ʱ��
	OrderArryMerge(arr5,arr6,5,4,12);             //���Ե�arr1�����������ռ����Դ��arr2ʱ��
    OrderArryMerge(arr7,arr8,size7,size8,size7);             //���Ե�arr1��Ϊ����arr2Ϊ��ʱ��
    OrderArryMerge(arr9,arr10,size9,size10,size9);          //���Ե�arr1Ϊ��ʱ��arr2��Ϊ�գ�
}	