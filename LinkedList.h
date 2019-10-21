#include "Node.h"

class LinkedList
{
	private:
		// data members
		Node *Head;
		
		// methods
		void Insert(Node *beg, Node *mid, Node *end);
		void Delete(Node *node);
		
	public:
		LinkedList();
		LinkedList(const LinkedList& ll);
		LinkedList(LinkedList&& ll);
		~LinkedList();
		
		LinkedList& operator=(const LinkedList& ll);
		LinkedList& operator=(LinkedList&& ll);
		
		void InsertBeg(int data);
		void InsertEnd(int data);
		void InsertBefore(int nodeData, int insertData);
		void InsertAfter(int nodeData, int insertData);
		
		void DeleteBeg();
		void DeleteEnd();
		void Delete(int data);
		
		Node* Search(int data);
		bool IsEmpty() const;
		int GetLength() const;
};