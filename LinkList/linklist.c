#include"linklist.h"
void InitLinkList(pLinkList pList)    //初始化
{
	assert(pList);
	pList->pHead =NULL;
}
pLinkNode CreatNewNode(pLinkList pList,DataType x)
{
    pLinkNode NewNode=(pLinkNode)malloc(sizeof(LinkNode));
	if(NULL == NewNode)
	{exit (EXIT_FAILURE);}
     NewNode->data=x;
	 NewNode->next =NULL;
     return NewNode;
}
void PushBackLinkList(pLinkList pList,DataType x)
{
	pLinkNode NewNode=CreatNewNode(pList, x);
	if(pList->pHead == NULL)
	{pList->pHead ==NewNode;}
	
	else
	{ 
		pLinkNode cur = pList->pHead ;
		while(cur)
		{
		    cur=cur->next ;
		}
	    NewNode=cur->next ;
		NewNode->data=x;
	}
	NewNode->next =NULL;
}

void PopBackLinkList(pLinkList pList)     //尾删
{
	pLinkNode cur=NULL;
	assert(pList);
	cur=pList->pHead;
	while(cur)
	{
	   cur = cur->next;
	   if(NULL == cur)
	   {
		   free(cur);
	       cur=NULL;
		   break;
	   }
	}
}              -------------------重写
void PushFrontLinkList(pLinkList pList,DataType x)
{
	pLinkNode NewNode=CreatNewNode(pList, x);
	if(pList->pHead == NULL)
	{pList->pHead ==NewNode;}
	
	else
	{ 
		pLinkNode cur = pList->pHead ;
		pLinkNode second = NULL ;
		second = pList->pHead ->next ;
		pList->pHead ->next = NewNode;
		NewNode->next = second;
	}
	NewNode->next =NULL;
}
void PopFrontLinkList(pLinkList pList)          //头删
{
  pLinkNode first = NULL;
pLinkNode second = NULL;
	assert(pList);
	first = pList->pHead;
  first=pList->pHead ->next;
	second=pList->pHead ->next->next;
	free(first);
	first=second;
}
void PrintLinkList(pLinkList pList)       //打印
{
	pLinkNode cur=NULL;
	assert(pList);
	cur=pList->pHead ;
	while(cur)
	{
		printf("%d->",cur->data );
		cur=cur->next ;
	}
}
pLinkNode Find(pLinkList pList,DataType x)
{
	pLinkNode  cur = NULL;
	assert(pList);
	cur = pList->pHead ;
	while(cur)
	{
		cur=cur->next ;
		if((cur->data)==(x))
		{return cur;}
	}
	return NULL;
}
void Insert(pLinkList pList,pLinkNode pos,DataType x)
{
	pLinkNode cur = NULL;
	pLinkNode  cur_next = NULL;
	assert(pList);
	cur = pList->pHead;
	while(cur)
	{
		cur=cur->next;
		if(cur == pos)
		{
            cur_next=cur;
			pLinkNode NewNode=CreatNewNode(pList, x);
			cur ->data = x;
			NewNode->next = cur_next;
		}
	}
}
void Remove(pLinkList pList,DataType x)
{
	pLinkNode cur = NULL;
	assert(pList);
	cur = pList->pHead;
	while(cur)
	{
		cur=cur->next;
		if(cur->data == x)
		{   
			pLinkNode pre_cur = cur;
			cur=cur->next;
			free(pre_cur);
			pre_cur == NULL;
			break;
		}
	}
}
void RemoveAll(pLinkList pList,DataType x)
{
	pLinkNode cur = NULL;
	assert(pList);
	cur = pList->pHead;
	while(cur)
	{
		cur=cur->next;
		if(cur->data == x)
		{   
			pLinkNode pre_cur = cur;
			cur=cur->next;
			free(pre_cur);
			pre_cur == NULL;
		}
	}
}
void Erase(pLinkList pList,pLinkNode pos)
{
	pLinkNode cur=NULL;
	assert(pList);
	cur=pList->pHead ;
	cur=cur->next ;
	while(cur)
	{
		cur=cur->next;
		while(cur=pos)
		{
			cur->next =pos->next;
			free(pos);
			pos=NULL;
			break;
		}
	}
	
}
void BubbleSort(pLinkList pList)
{
	pLinkNode cur = NULL;
	pLinkNode first = NULL;
	assert(pList);
	cur = pList->pHead ;
	pLinkNode i = cur->next;
	pLinkNode j = first;
	for(i = cur ; i != NULL ; i = i->next )
	{
		for(j = i ; j != NULL ; j = j->next )
		{
			if((i->data)>(j->data))
			{
				DataType temp = i->data ;
				i->data = j->data;
				j->data = temp;
			}
		}
	}
	
}