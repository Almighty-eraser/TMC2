#include <iostream>
#include <string>
#include "List.h"
#define DATA_FILE_NAME "d:DATA.dat"
#define SUM_OF_DATA (SIZE_OF_NAME + SIZE_OF_PHONE + SIZE_OF_ADDRESS)



List::List(Node *Head)
{
	m_Head = Head;
	m_Head->pNext = nullptr;

	FILE* fp;
	fopen_s(&fp, DATA_FILE_NAME, "rb");

	if (fp == NULL)
		return;

	Node Read;
	memset(&Read, 0, sizeof(Read));
	Node* Save = m_Head;

	while (1)
	{
		
		if (fread(&Read, sizeof(char) * (9 + 12 + 64), 1, fp))
		{
			std::cout << "파일 읽어들이는 중.." << '\n';
			AddNode(Read.GetName(), Read.GetPhone(), Read.GetAddress());
		}
		else
			break;
	}

	fclose(fp);

	system("cls");
}

List::~List()
{
	SaveAllNode();
	DeleteAllNode();
}

void List::AddNode(char* Name, char* Phone, char* Address) const
{
	Node* NewNode = new Node;
	Node* Search = m_Head;

	while (1)
	{
		if (Search->pNext == nullptr)
		{

 			strcpy_s(NewNode->GetName(), SIZE_OF_NAME, Name);
			strcpy_s(NewNode->GetPhone(), SIZE_OF_PHONE, Phone);
			strcpy_s(NewNode->GetAddress(), SIZE_OF_ADDRESS, Address);
			Search->pNext = NewNode;
			
			break;
		}
		else
			Search = Search->pNext;
	}



}

Node* List::SearchNode(int side, char* Find) const
{

	Node* nNode;
	nNode = m_Head->pNext;

	Node* FoundData = new Node;
	memset(FoundData, 0, sizeof(FoundData));
	Node* Insert = FoundData;



	if (side == 1)//이름 검색
	{
		while (nNode != nullptr)
		{
			if (strstr(nNode->GetName(), Find))
			{
				Node* NewNode = new Node;

				memset(NewNode, 0, sizeof(NewNode));
				strcpy_s(NewNode->GetName(), sizeof(char) * SIZE_OF_NAME, nNode->GetName());
				strcpy_s(NewNode->GetPhone(), sizeof(char) * SIZE_OF_PHONE, nNode->GetPhone());
				strcpy_s(NewNode->GetAddress(), sizeof(char) * SIZE_OF_ADDRESS, nNode->GetAddress());

				Insert->pNext = NewNode;

				nNode = nNode->pNext;
				Insert = Insert->pNext;
			}
			else
				nNode = nNode->pNext;

		}

		return FoundData;

	}
	else if (side == 2)//전화번호 검색
	{
		while (nNode != nullptr)
		{
			if (strstr(nNode->GetPhone(), Find))
			{
				Node* NewNode = new Node;

				memset(NewNode, 0, sizeof(NewNode));
				strcpy_s(NewNode->GetName(), sizeof(char) * SIZE_OF_NAME, nNode->GetName());
				strcpy_s(NewNode->GetPhone(), sizeof(char) * SIZE_OF_PHONE, nNode->GetPhone());
				strcpy_s(NewNode->GetAddress(), sizeof(char) * SIZE_OF_ADDRESS, nNode->GetAddress());

				Insert->pNext = NewNode;

				nNode = nNode->pNext;
				Insert = Insert->pNext;
			}
			else
				nNode = nNode->pNext;

		}

		return FoundData;
	}
	else if (side == 3)//주소 검색
	{
		while (nNode != nullptr)
		{
			if (strstr(nNode->GetAddress(), Find))
			{
				Node* NewNode = new Node;

				memset(NewNode, 0, sizeof(NewNode));
				strcpy_s(NewNode->GetName(), sizeof(char) * SIZE_OF_NAME, nNode->GetName());
				strcpy_s(NewNode->GetPhone(), sizeof(char) * SIZE_OF_PHONE, nNode->GetPhone());
				strcpy_s(NewNode->GetAddress(), sizeof(char) * SIZE_OF_ADDRESS, nNode->GetAddress());

				Insert->pNext = NewNode;

				nNode = nNode->pNext;
				Insert = Insert->pNext;
			}
			else
				nNode = nNode->pNext;

		}

		return FoundData;
	}
}

void List::DeleteAllNode(void) const
{
	Node* Remove;
	Node* Tmp = m_Head->pNext;

	while (Tmp != nullptr)
	{
		Remove = Tmp;
		Tmp = Tmp->pNext;
		delete Remove;
	}
	m_Head->pNext = nullptr;
}

void List::DeleteNode(Node* Chosen) const
{
	Node* tmp = m_Head;
	Node* Delete;

	while (1)
	{
		if (strstr(tmp->pNext->GetName(), Chosen->GetName()) != nullptr && strstr(tmp->pNext->GetPhone(), Chosen->GetPhone()) != nullptr && strstr(tmp->pNext->GetAddress(), Chosen->GetAddress()) != nullptr)
		{
			Delete = tmp->pNext;
			tmp->pNext = tmp->pNext->pNext;
			Delete->pNext = nullptr;
 			delete Delete;
			break;
		}
		else
			tmp = tmp->pNext;
	}

}

void List::RandomlyCreate(int amount) const
{
	Random* random = new Random;
	char Name[SIZE_OF_NAME];
	char Phone[SIZE_OF_PHONE];
	char Address[SIZE_OF_ADDRESS];

	for (int i = 0; i < amount; ++i)
	{
		memset(Name, 0, SIZE_OF_NAME);
		memset(Phone, 0, SIZE_OF_PHONE);
		memset(Address, 0, SIZE_OF_ADDRESS);

		//strcpy_s(Name, SIZE_OF_NAME - 2, random->RCN());
		//strcpy_s(Phone, SIZE_OF_PHONE, random->RCP());
		//strcpy_s(Address, SIZE_OF_ADDRESS, random->RCA());
		char* NewName = random->RCN();
		char* NewPhone = random->RCP();
		char* NewAddress = random->RCA();
		memcpy_s(Name, SIZE_OF_NAME, NewName, SIZE_OF_NAME);
		memcpy_s(Phone, SIZE_OF_PHONE, NewPhone, SIZE_OF_PHONE);
		memcpy_s(Address, SIZE_OF_ADDRESS, NewAddress, SIZE_OF_ADDRESS);

		AddNode(Name, Phone, Address);

		delete NewName;
		delete NewPhone;
		delete NewAddress;
	}
	delete random;
}

void List::SaveAllNode(void) const
{
	FILE* fp;
	fopen_s(&fp, DATA_FILE_NAME, "wb");

	if (fp == NULL)
		return;

	Node* Save = m_Head->pNext;

	while (1)
	{
		if (Save == nullptr)
			break;

		fwrite(Save, sizeof(char) * SUM_OF_DATA, 1, fp);
		Save = Save->pNext;
	}

	fclose(fp);
}