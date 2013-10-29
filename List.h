typedef struct _node
{
	struct _node *next;
	void *pdata;
}Node;

typedef struct _list
{
	Node *head;
	Node *cur;
	Node *tail;
	int NumOfList;
}List;

void InitList(List *plist);
void InsertList(List *plist,void *data);
void DeleteList(List *plist);

Node* FindPrevNode(List *plist,Node *pNode);


