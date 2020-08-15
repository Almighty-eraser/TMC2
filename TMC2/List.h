#pragma once
#include "Node.h"
#include "Random.h"
#define SIZE_OF_NAME 9
#define SIZE_OF_PHONE 12
#define SIZE_OF_ADDRESS 64

class Node;

class List
{
public:
	List(Node* Head);
	~List();

	void AddNode(char* name, char* Phone, char* Address) const;
	Node* SearchNode(int side, char* Find) const;
	
	void SaveAllNode(void) const;
	void DeleteAllNode(void) const;
	void DeleteNode(Node* Chosen) const;
	void RandomlyCreate(int amount) const;

	Node* GetHead(void) { return m_Head; }

private:
	Node* m_Head;
};

