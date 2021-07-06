#include <iostream>
#include "UI.h"

UI::UI(List* main)
	: UI_main(main)
{

}
void UI::Add(void) const
{
	char Name[9] = { 0 };
	char Phone[12] = {0};
	char Address[64] = { 0 };

	std::cout << "Input name : ";
	std::cin >> Name;
	std::cout << "Input Phone number : ";
	std::cin >> Phone;
	std::cout << "Input Address : ";
	std::cin >> Address;

	UI_main->AddNode(Name, Phone, Address);
}

void UI::PrintAllNode(void) const
{
	Node* Print = UI_main->GetHead();
	while (1)
	{
		if (Print->pNext != nullptr)
		{
			std::cout << '\n' << "Name : " << Print->pNext->GetName() 
				<< '\n' << "Phone number : " << Print->pNext->GetPhone()
				<< '\n' << "Address : " << Print->pNext->GetAddress() 
				<< '\n';
			Print = Print->pNext;
		}
		else
			break;
		
	}
}

void UI::DeleteAllNode(void) const
{
	int choice = 0;
	while (1)
	{
		std::cout << "\n\nAre you sure you wanna delete all data? <1> yes <2>no : ";
		std::cin >> choice;

		if (choice == 1)
			UI_main->DeleteAllNode();
		else if (choice == 2)
			break;
		else
		{
			std::cout << "\n\nTry Again\n";
			continue;
		}
		std::cout << "\n\nAll data deleted. If you choose EXIT, All data in File will be deleted\n\n";
		break;
	}
} 

void UI::DeleteNode(void) const
{
	int side;
	char* input;

	while (1)
	{
		std::cout << "\n\nChoose Area to delete <1>Name <2>Phone number <3>Address ";
		std::cin >> side;

		if (side == 1)
			input = new char[9];
		else if (side == 2)
			input = new char[12];
		else if (side == 3)
			input = new char[64];
		else
		{
			std::cout << "\n\nTry Again\n\n";
			continue;
		}

		memset(input, 0, sizeof(input));

		std::cout << "\n\nSearch : ";
		std::cin >> input;

		Node* Result = UI_main->SearchNode(side, input);
		Node* Print = Result;

		long int counter = 0;

		while (1)
		{
			if (Print->pNext == nullptr)
			{
				std::cout << "\n\nNo more data searched\n\n";
				break;
			}


			std::cout << "Found Data : ";
			std::cout << Print->pNext->GetName() << ' ' << Print->pNext->GetPhone() << ' ' << Print->pNext->GetAddress() << " <" << counter <<
				'>' << '\n';
			++counter;

			Print = Print->pNext;
		}
		Print = nullptr;

		int choice = 0;

		std::cout << "\n\n\nChoose data to delete : ";
		std::cin >> choice;

		Node* ChosenNode;
		Node* Search = Result->pNext;

		while (1)
		{
			if (choice == 0)
				break;

			Search = Search->pNext;
			--choice;
		}

		ChosenNode = Search;

		UI_main->DeleteNode(ChosenNode);

		Node* Delete;
		Node* tmp = Result;

		do
		{
			Delete = tmp;
			tmp = tmp->pNext;
			delete Delete;

		} while (tmp != nullptr);

		break;
	}
}

void UI::Search(void) const
{
	int side;
	char* input;

	while (1)
	{
		std::cout << "\n\nChoose Area to search <1>Name <2>Phone number <3>Address ";
		std::cin >> side;

		if (side == 1)
			input = new char[9];
		else if (side == 2)
			input = new char[12];
		else if (side == 3)
			input = new char[64];
		else
		{
			std::cout << "\n\nTry Again\n\n";
			continue;
		}

		memset(input, 0, sizeof(input));

		std::cout << "\n\nSearch : ";
		std::cin >> input;

		Node* Result = UI_main->SearchNode(side, input);
		Node* Print = Result;

		while (1)
		{
			if (Print->pNext == nullptr)
			{
				std::cout << "\n\nNo more data searched\n\n";
				break;
			}


			std::cout << "Found Data : ";
			std::cout << Print->pNext->GetName() << ' ' << Print->pNext->GetPhone() << ' ' << Print->pNext->GetAddress() << '\n';

			Print = Print->pNext;
		}
		Print = nullptr;
		Node* Delete;
		Node* tmp = Result;

		do
		{
			Delete = tmp;
			tmp = tmp->pNext;
			delete Delete;

		} while (tmp != nullptr);

		break;
	}
}

void UI::Random(void) const
{
	int amount;
	std::cout << "\n\nHow Many Data of One Person do you want to randomly create? : ";
	std::cin >> amount;

	UI_main->RandomlyCreate(amount);
}

void UI::choosemenu(void) const
{
	int answer;
	while (1)
	{
		fflush(stdin);
		std::cout << '\n' << '\n';
		std::cout << "\t\tWelcome to KoreanDatabase                                       File name and Path : ""d:DATA.dat""" << '\n';
		std::cout << "" << '\n';
		std::cout << "\t\t<1> Add New Data" << '\n';
		std::cout << "\t\t<2> Print All Data" << '\n';
		std::cout << "\t\t<3> Delete All Data" << '\n';
		std::cout << "\t\t<4> Delete a Data" << '\n';
		std::cout << "\t\t<5> Search Data" << '\n';
		std::cout << "\t\t<6> Randomly Create Data" << '\n';
		std::cout << "\t\t<7> Exit" << '\n';
		std::cout << "" << '\n';
		std::cout << "\t\tÀÔ·Â : ";


		std::cin >> answer;
		
		switch (answer)
		{
		case 1:
			Add();
			break;
		case 2:
			PrintAllNode();
			break;
		case 3:
			DeleteAllNode();
			break;
		case 4:
			DeleteNode();
			break;
		case 5:
			Search();
			break;
		case 6:
			Random();
			break;
		default:
			break;
		}

		if (answer == 7)
			break;
		
	}
}
