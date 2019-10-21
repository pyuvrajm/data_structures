struct Node
{
	int Data;
	Node *Next, *Prev;
	Node(int data)
	{
		Data = data;
		Next = nullptr;
		Prev = nullptr;
	}
	~Node()
	{
		Next = nullptr;
		Prev = nullptr;
	}
};