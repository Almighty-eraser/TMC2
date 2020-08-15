#pragma once
#include <iostream>

class Node
{
public:

	Node(void);

	char* GetName(void) { return Name; }
	char* GetPhone(void) { return Phone; }
	char* GetAddress(void) { return Address; }



	Node* pNext;
private:

	char Name[9];
	char Phone[12];
	char Address[64];

};

