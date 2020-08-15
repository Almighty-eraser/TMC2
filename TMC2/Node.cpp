#include "Node.h"
#include <iostream>

Node::Node(void)
{
	memset(Name, 0, sizeof(Name));
	memset(Phone, 0, sizeof(Phone));
	memset(Address, 0, sizeof(Address));
	pNext = nullptr;
}
