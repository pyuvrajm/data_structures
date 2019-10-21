#include "LinkedList.h"

LinkedList::LinkedList()
: Head(nullptr)
{
}

// copy c'tor
LinkedList::LinkedList(const LinkedList& ll)
{
	if(ll.IsEmpty())
		return;
	Node *itr = ll.Head;
	do
	{
		InsertEnd(itr->Data);
		itr = itr->Next;
	}while(itr != ll.Head);
}

// move c'tor
LinkedList::LinkedList(LinkedList&& ll)
	:Head(ll.Head)
{
	ll.Head = nullptr;
}

// copy assignment operator
LinkedList& LinkedList::operator=(const LinkedList& ll)
{
	// self-assignment detection
	if(&ll == this)
		return *this;
	
	// delete current nodes
	if(Head)
	{
		Node *itr = Head;
		do
		{
			Node* tmp = itr;
			itr = itr->Next;
			delete tmp;
		}while(itr != Head);
	}
	Head = nullptr;
	
	// copy from ll
	if(ll.IsEmpty())
		return *this;
	Node *itr = ll.Head;
	do
	{
		InsertEnd(itr->Data);
	}while(itr != Head);
	return *this;
}

//move assignment operator
LinkedList& LinkedList::operator=(LinkedList&& ll)
{
		// self-assignment detection
	if(&ll == this)
		return *this;
	
	// delete current nodes
	if(Head)
	{
		Node *itr = Head;
		do
		{
			Node* tmp = itr;
			itr = itr->Next;
			delete tmp;
		}while(itr != Head);
	}
	Head = nullptr;
	
	// take ownership from ll
	if(ll.IsEmpty())
		return *this;
	Head = ll.Head;
	ll.Head = nullptr;
	return *this;
}

LinkedList::~LinkedList()
{
	if(!Head)
		return;
	Node *itr = Head;
	do
	{
		Node *tmp = itr;
		itr = itr->Next;
		delete tmp;
	}while(itr != Head);
}

void LinkedList::Insert(Node *beg, Node *mid, Node *end)
{
	if(mid)
	{
		mid->Next = end;
		mid->Prev = beg;
	}
	if(beg)
		beg->Next = mid;
	if(end)
		end->Prev = mid;
}

void LinkedList::Delete(Node *node)
{
	if(node)
	{
		if(node->Next)
			node->Next->Prev = node->Prev;
		if(node->Prev)
			node->Prev->Next = node->Next;
	}
	
	delete node;
	node = nullptr;
}

void LinkedList::InsertBeg(int data)
{
	Node *node = new Node(data);
	if(!Head)
	{
		Insert(nullptr, node, Head);
		Head = node;
		Head->Next = Head;
		Head->Prev = Head;
	}
	else
	{
		Insert(Head->Prev, node, Head->Next);
		Head = node;
	}
}

void LinkedList::InsertEnd(int data)
{
	Node *node = new Node(data);
	if(!Head)
	{
		Insert(nullptr, node, Head);
		Head = node;
		Head->Next = Head;
		Head->Prev = Head;
	}
	else
	{
		Insert(Head->Prev, Head, Head);
	}
}

void LinkedList::InsertBefore(int listData, int newData)
{
	if(!Head)
		return;
	Node *listNode = Search(listData);
	if(!listNode)
		return;
	Node *newNode = new Node(newData);
	Insert(listNode->Prev, newNode, listNode);
}

void LinkedList::InsertAfter(int listData, int newData)
{
	if(!Head)
		return;
		Node *listNode = Search(listData);
	if(!listNode)
		return;
	Node *newNode = new Node(newData);
	Insert(listNode, newNode, listNode->Next);
}

void LinkedList::DeleteBeg()
{
	if(!Head)
		return;
	Delete(Head);
}

void LinkedList::DeleteEnd()
{
	if(!Head)
		return;
	Delete(Head->Prev);
}

void LinkedList::Delete(int data)
{
	Node *node = Search(data);
	if(node)
		Delete(node);
}

Node* LinkedList::Search(int data)
{
	if(!Head)
		return nullptr;
	Node *itr = Head;
	do
	{
		if(itr->Data == data)
			return itr;
	}while(itr != Head);
	return nullptr;
}

bool LinkedList::IsEmpty() const
{
	bool ret = false;
	if (!Head)
		ret = true;
	return ret;
}

int LinkedList::GetLength() const
{
	int len = 0;
	if(!Head)
		return len;
	Node *itr = Head;
	do
	{
		len = len + 1;
		itr = itr->Next;
	}while(itr != Head);
	return len;
}