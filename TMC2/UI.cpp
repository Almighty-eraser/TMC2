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
			std::cout << '\n' << "이름 : " << Print->pNext->GetName() 
				<< '\n' << "전화번호 : " << Print->pNext->GetPhone()
				<< '\n' << "주소 : " << Print->pNext->GetAddress() 
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
		std::cout << "\n\n정말로 모든 데이터의 내용을 지우시겠습니까? <1> 예 <2>아니오 : ";
		std::cin >> choice;

		if (choice == 1)
			UI_main->DeleteAllNode();
		else if (choice == 2)
			break;
		else
		{
			std::cout << "\n\n다시 입력해 주세요\n";
			continue;
		}
		std::cout << "\n\n모든 데이터를 지웠습니다. Exit을 고르시면 파일 안의 내용이 사라집니다.\n\n";
		break;
	}
} 

void UI::DeleteNode(void) const
{
	int side;
	char* input;

	while (1)
	{
		std::cout << "\n\n삭제할 데이터를 검색할 영역 <1>이름 <2>전화번호 <3>주소 ";
		std::cin >> side;

		if (side == 1)
			input = new char[9];
		else if (side == 2)
			input = new char[12];
		else if (side == 3)
			input = new char[64];
		else
		{
			std::cout << "\n\n다시 입력해 주세요\n\n";
			continue;
		}

		memset(input, 0, sizeof(input));

		std::cout << "\n\n검색어 : ";
		std::cin >> input;

		Node* Result = UI_main->SearchNode(side, input);
		Node* Print = Result;

		long int counter = 0;

		while (1)
		{
			if (Print->pNext == nullptr)
			{
				std::cout << "\n\n더이상 일치하는 데이터가 없습니다.\n\n";
				break;
			}


			std::cout << "찾은 데이터 : ";
			std::cout << Print->pNext->GetName() << ' ' << Print->pNext->GetPhone() << ' ' << Print->pNext->GetAddress() << " <" << counter <<
				'>' << '\n';
			++counter;

			Print = Print->pNext;
		}
		Print = nullptr;

		int choice = 0;

		std::cout << "\n\n\n검색한 데이터들 중 삭제할 데이터를 고르시오 : ";
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
		std::cout << "\n\n검색할 영역 <1>이름 <2>전화번호 <3>주소 ";
		std::cin >> side;

		if (side == 1)
			input = new char[9];
		else if (side == 2)
			input = new char[12];
		else if (side == 3)
			input = new char[64];
		else
		{
			std::cout << "\n\n다시 입력해 주세요\n\n";
			continue;
		}

		memset(input, 0, sizeof(input));

		std::cout << "\n\n검색어 : ";
		std::cin >> input;

		Node* Result = UI_main->SearchNode(side, input);
		Node* Print = Result;

		while (1)
		{
			if (Print->pNext == nullptr)
			{
				std::cout << "\n\n더이상 일치하는 데이터가 없습니다.\n\n";
				break;
			}


			std::cout << "찾은 데이터 : ";
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
		std::cout << "\t\tWelcome to TMC2                                       파일 이름과 경로 : ""d:DATA.dat""" << '\n';
		std::cout << "" << '\n';
		std::cout << "\t\t<1> Add New Data" << '\n';
		std::cout << "\t\t<2> Print All Data" << '\n';
		std::cout << "\t\t<3> Delete All Data" << '\n';
		std::cout << "\t\t<4> Delete a Data" << '\n';
		std::cout << "\t\t<5> Search Data" << '\n';
		std::cout << "\t\t<6> Randomly Create Data" << '\n';
		std::cout << "\t\t<7> Exit" << '\n';
		std::cout << "" << '\n';
		std::cout << "\t\t입력 : ";


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
