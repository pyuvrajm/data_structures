#include "LinkedList.cpp"

int main(int argc, char **argv)
{
	LinkedList list;
	list.InsertEnd(10);
	list.InsertBeg(5);
	list.InsertAfter(10, 20);
	list.InsertBefore(20, 15);
	list.InsertBeg(25);
	list.InsertEnd(70);
	list.InsertEnd(30);
	list.InsertEnd(60);
	list.InsertEnd(20);
	list.DeleteBeg();
	list.DeleteEnd();
	list.Delete(30);
	Node *n = list.Search(20);
	bool b = list.IsEmpty();
	return 0;
}