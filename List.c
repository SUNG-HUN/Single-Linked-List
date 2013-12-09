#include <stdlib.h>
#include "List.h"

void InitList(List *plist)
{
	plist->head = NULL;
	plist->NumOfList = 0;
}

void InsertList(List *plist,void *data)
{
	Node *NewNode = (Node *)malloc(sizeof(Node));
	NewNode->next = NULL;
	NewNode->pdata = data;

	if(plist->head == NULL)
		plist->head = NewNode;

	else
		plist->tail->next = NewNode;

	plist->tail = NewNode;

	plist->NumOfList++;
}

void DeleteList(List *plist)
{
	if(plist->cur == plist->head)
	{
		plist->head = NULL;

		if(plist->NumOfList > 1)
		plist->head = plist->cur->next;

		free(plist->cur);
		plist->cur = plist->head;
	}

	else if(plist->cur == plist->tail)
	{
		Node *delNode = plist->cur;
		plist->cur = FindPrevNode(plist,delNode);
		plist->tail = plist->cur;
		free(delNode);
	}

	else
	{
		Node *delNode = plist->cur;
		plist->cur = FindPrevNode(plist,delNode);
		plist->cur->next = delNode->next;
		free(delNode);
	}

	plist->NumOfList--;
}

 void ListCount(List *plist)
{
	printf("list count : %d \n",plist->NumOfList);
}

Node* FindPrevNode(List *plist,Node *pNode)
{
	Node *CurNode;
	for(CurNode = plist->head; CurNode != plist->tail; CurNode = CurNode->next)
	{
		if(CurNode->next == pNode)
			return CurNode;
	}

	return NULL;
}