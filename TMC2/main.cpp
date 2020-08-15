#include <iostream>
#include "List.h"
#include "Node.h"
#include "UI.h"

int main()
{
	Node Head;
	List Main(&Head);
	UI Start(&Main);
	Start.choosemenu();

	return 0;
}