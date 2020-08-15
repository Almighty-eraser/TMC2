#include "Random.h"
#include <time.h>


int Random::RandomValue(int limit) const//limit �̸��� �� ��������
{
	std::mt19937_64 rng1(std::random_device{}());
	std::uniform_int_distribution<__int64> dist1(0, limit-1);
	return dist1(rng1);
}

char* Random::RCA(void) const//��⵵, ������, ��û����, ��û�ϵ�, ���󳲵�, ����ϵ�, ��󳲵�, ���ϵ�, ����Ư����ġ��
{
	char* Address = new char[SIZE_OF_ADDRESS];
	memset(Address, 0, SIZE_OF_ADDRESS);

	int ChosenDo = RandomValue(NUMBER_OF_Do);
	int ChosenSi = RandomValue(NUMBER_OF_Si);
	int ChosenUnderSi = RandomValue(NUMBER_OF_UnderSi);
	int lenofDo = strlen(Do[ChosenDo]);
	std::cout << Do[ChosenDo] << Si[ChosenDo][ChosenSi] << UnderSi[ChosenDo][ChosenSi][ChosenUnderSi];

	strcpy_s(Address, lenofDo + 1, Do[ChosenDo]);
	strcpy_s(Address + lenofDo, lenofSi, Si[ChosenDo][ChosenSi]);
	strcpy_s(Address + lenofDo + lenofSi - 1, lenofUnderSi, UnderSi[ChosenDo][ChosenSi][ChosenUnderSi]);
	/*switch (ChosenDo)
	{
	case 0://"������ ", "������ ", "���ν� ", "�Ⱦ�� ", "�Ȼ�� "
		strcpy_s(Address, lenofDo3, Do[ChosenDo]);
		strcpy_s(Address + lenofDo3 - 1, lenofSi, Si0[ChosenSi]);
		int NumberOfUnderSi = 3;
		int ChosenUnderSi = 0;
		/*switch (ChosenSi)
		{
		case 1:
			++NumberOfUnderSi;
			ChosenUnderSi = RandomValue(NumberOfUnderSi);
			const char* UnderSi[4] = { "��ȱ�", "�Ǽ���", "�ȴޱ�", "���뱸" };
			strcpy_s(Address + lenofDo3 - 1 + lenofSi, lenofGu, UnderSi[RandomValue(NumberOfUnderSi)]);
			break;
		case 2:
			ChosenUnderSi = RandomValue(NumberOfUnderSi);
			const char* UnderSi[3] = { "������", "�߿���", "�д籸" };
			strcpy_s(Address + lenofDo3 - 1 + lenofSi, lenofGu, UnderSi[RandomValue(NumberOfUnderSi)]);
			break;
		case 3:
			ChosenUnderSi = RandomValue(NumberOfUnderSi);
			const char* UnderSi[3] = { "ó�α�", "���ﱸ", "������" };
			strcpy_s(Address + lenofDo3 - 1 + lenofSi, lenofGu, UnderSi[RandomValue(NumberOfUnderSi)]);
			break;
		case 4:
			--NumberOfUnderSi;
			ChosenUnderSi = RandomValue(NumberOfUnderSi);
			const char* UnderSi[3] = { "���ȱ�", "���ȱ�" };
			strcpy_s(Address + lenofDo3 - 1 + lenofSi, lenofGu, UnderSi[RandomValue(NumberOfUnderSi)]);
			break;
		case 5:
			--NumberOfUnderSi;
			ChosenUnderSi = RandomValue(NumberOfUnderSi);
			const char* UnderSi[3] = { "��ϱ�", "�ܿ���" };
			strcpy_s(Address + lenofDo3 - 1 + lenofSi, lenofGu, UnderSi[RandomValue(NumberOfUnderSi)]);
			break;
		default:
			break;
		}
		break;
	case 1://"��õ�� ", "���ֽ� ", "���ʽ� ", "ȫõ�� ", "��â�� "
		strcpy_s(Address, lenofDo3, Do[ChosenDo]);
		strcpy_s(Address + sizeof(char) * lenofDo3 - 1, lenofSi, Si1[ChosenSi]);
		char** UnderSi[NUMBER_OF_Si] = { {}, {}, {}, {}, {} };
		break;
	case 2://"���ֽ� ", "�ƻ�� ", "õ�Ƚ� ", "���� ", "����� "
		strcpy_s(Address, lenofDo4, Do[ChosenDo]);
		strcpy_s(Address + sizeof(char) * lenofDo4 - 1, lenofSi, Si2[ChosenSi]);
		char** UnderSi[NUMBER_OF_Si] = { {}, {}, {}, {}, {} };
		break;
	case 3://"���걺 ", "��õ�� ", "û�ֽ� ", "������ ", "��õ�� "
		strcpy_s(Address, lenofDo4, Do[ChosenDo]);
		strcpy_s(Address + sizeof(char) * lenofDo4 - 1, lenofSi, Si3[ChosenSi]);
		char** UnderSi[NUMBER_OF_Si] = { {}, {}, {}, {}, {} };
		break;
	case 4://"���ֽ� ", "�س��� ", "������ ", "��õ�� ", "���籺 "
		strcpy_s(Address, lenofDo4, Do[ChosenDo]);
		strcpy_s(Address + sizeof(char) * lenofDo4 - 1, lenofSi, Si4[ChosenSi]);
		char** UnderSi[NUMBER_OF_Si] = { {}, {}, {}, {}, {} };
		break;
	case 5://"���ֽ� ", "����� ", "�ͻ걺 ", "������ ", "������ "
		strcpy_s(Address, lenofDo4, Do[ChosenDo]);
		strcpy_s(Address + sizeof(char) * lenofDo4 - 1, lenofSi, Si5[ChosenSi]);
		char** UnderSi[NUMBER_OF_Si] = { {}, {}, {}, {}, {} };
		break;
	case 6://"���ֽ� ", "â���� ", "���ؽ� ", "������ ", "���� "
		strcpy_s(Address, lenofDo4, Do[ChosenDo]);
		strcpy_s(Address + sizeof(char) * lenofDo4 - 1, lenofSi, Si6[ChosenSi]);
		char** UnderSi[NUMBER_OF_Si] = { {}, {}, {}, {}, {} };
		break;
	case 7://"���׽� ", "���ֽ� ", "��õ�� ", "�ȵ��� ", "���̽� "
		strcpy_s(Address, lenofDo4, Do[ChosenDo]);
		strcpy_s(Address + sizeof(char) * lenofDo4 - 1, lenofSi, Si7[ChosenSi]);
		char** UnderSi[NUMBER_OF_Si] = { {}, {}, {}, {}, {} };
		break;
	default:
		strcpy_s(Address, lenofDo7, Do[ChosenDo]);
		break;
	}*/


	return Address;
}

char* Random::RCN(void) const
{
	
	char* Name = new char[SIZE_OF_NAME];

	memset(Name, 0, SIZE_OF_NAME);


	memcpy_s(Name, SIZE_OF_NAME, FirstName[RandomValue(NUMBER_OF_FIRSTNAME)], lenofFirstName);

	memcpy_s(Name + lenofFirstName - 1, sizeof(char) * lenofRestName, RestName[RandomValue(NUMBER_OF_RESTNAME)], sizeof(char) * lenofRestName);


	Name[lenofFirstName + lenofRestName - 2] = '\0';

	return Name;
}

char* Random::RCP(void) const
{
	char Numbers[11] = { "0123456789" };
	char* Phone = new char[SIZE_OF_PHONE];
	char RestPhone[SIZE_OF_PHONE - 3];

	memset(RestPhone, 0, sizeof(char) * (SIZE_OF_PHONE - 3));
	memset(Phone, 0, sizeof(char) * SIZE_OF_PHONE);

	strcpy_s(Phone, sizeof("010"), "010");

	for (int i = 3; i < SIZE_OF_PHONE - 1; ++i)
	{
		*(Phone + i) = *(Numbers + RandomValue(lenofNumbers - 1));
	}
	Phone[SIZE_OF_PHONE - 1] = '\0';

	std::cout << Phone;

	


	return Phone;
}