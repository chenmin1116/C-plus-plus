#include"Spare_matrix_Triple.h"

void TestSpareMartix()
{
	int arr[3][3]={{1,0,0},
				   {0,2,0},
				   {0,0,5}};

	SpareMarix<int> sm1(3,3,(int *)arr,0);
	cout<<"ԭʼϡ�����"<<endl;
	sm1.Display();
	cout<<"ת���Ժ�ľ���"<<endl;
	SpareMarix<int> sm2=sm1.Ttransport();
	sm2.Display();
	cout<<"����ת���Ժ�ľ���"<<endl;
	SpareMarix<int> sm3=sm1.FastTransport();
	sm3.Display();
}

int main()
{
	TestSpareMartix();
	system("pause");
	return 0;
}