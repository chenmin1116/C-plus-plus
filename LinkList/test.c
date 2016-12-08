#include"linklist.h"
void menu()
{
	printf("***** 0.Exit                1.Init         ------****\n");
	printf("***** 2.CreatNewNode        3.PushBack     ------****\n");
	printf("***** 4.PopBack             5.PushFront    ------****\n");
	printf("***** 6..Popfront           7.Print        ------****\n");
	printf("***** 8.Find                9.Insert       ------****\n");
	printf("*****10.Remove            11.RemoveAll     ------****\n");
	printf("*****12.Erase             13.BubbleSort    ------****\n");
}
 void test1()
 {
	pLinkList pList;
	InitLinkList(pList);
	CreatNewNode(pList, 1);
	CreatNewNode(pList, 2);
	CreatNewNode(pList, 3);
	CreatNewNode(pList, 4);
	CreatNewNode(pList, 5);
	PushBackLinkList(pList,1);
	PushBackLinkList(pList,2);
	PushBackLinkList(pList,3);
	PushBackLinkList(pList,4);
	PushBackLinkList(pList,5);
	PrintLinkList(pList);
 }
int main()
{
	test1();
	pLinkList pList;
	DataType input = 1;
	DataType  x=10;
	pLinkNode pos = CreatNewNode(pList, x);
    ////printf("%d",&x);
	while(input)
	{
		menu();
		printf("ÇëÑ¡Ôñ>:");
		scanf("%d",&input);
		switch(input)
		{
		case INIT:
			InitLinkList(pList);
			break;
		case CREATNEWNODE:
			CreatNewNode(pList,12);
			break;
		case PUSHBACK:
			PushBackLinkList(pList, 12);
			break;
		case POPBACK:
			 PopBackLinkList(pList);
			break;
		case PUSHFRONT:
			PushFrontLinkList(pList, 12);
			break;
		case POPFRONT:
			PopFrontLinkList(pList);
			break;
		case PRINT:
			PrintLinkList(pList);
			break;
		case FIND:
			Find(pList, 10);
			break;
		case INSERT:
			Insert( pList, pos, 10);
			break;
		case REMOVE:
            Remove(pList, 5);
			break;
		case REMOVEALL:
			RemoveAll( pList, 12);
			break;
		case ERASE:
			Erase(pList, pos);
			break;
		case BUBBLESORT:
			BubbleSort(pList);
			break;
		case EXIT:
			exit(EXIT_FAILURE);
		default:
			printf("Ñ¡Ôñ´íÎó\n");
			break;
		}
	}
	system("pause");
	return 0;
}



