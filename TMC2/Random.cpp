#include "Random.h"
#include <time.h>


int Random::RandomValue(int limit) const//limit 미만의 수 랜덤생성
{
	std::mt19937_64 rng1(std::random_device{}());
	std::uniform_int_distribution<__int64> dist1(0, limit-1);
	return dist1(rng1);
}

char* Random::RCA(void) const//경기도, 강원도, 충청남도, 충청북도, 전라남도, 전라북도, 경상남도, 경상북도, 제주특별자치도
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
	case 0://"수원시 ", "성남시 ", "용인시 ", "안양시 ", "안산시 "
		strcpy_s(Address, lenofDo3, Do[ChosenDo]);
		strcpy_s(Address + lenofDo3 - 1, lenofSi, Si0[ChosenSi]);
		int NumberOfUnderSi = 3;
		int ChosenUnderSi = 0;
		/*switch (ChosenSi)
		{
		case 1:
			++NumberOfUnderSi;
			ChosenUnderSi = RandomValue(NumberOfUnderSi);
			const char* UnderSi[4] = { "장안구", "권선구", "팔달구", "영통구" };
			strcpy_s(Address + lenofDo3 - 1 + lenofSi, lenofGu, UnderSi[RandomValue(NumberOfUnderSi)]);
			break;
		case 2:
			ChosenUnderSi = RandomValue(NumberOfUnderSi);
			const char* UnderSi[3] = { "수정구", "중원구", "분당구" };
			strcpy_s(Address + lenofDo3 - 1 + lenofSi, lenofGu, UnderSi[RandomValue(NumberOfUnderSi)]);
			break;
		case 3:
			ChosenUnderSi = RandomValue(NumberOfUnderSi);
			const char* UnderSi[3] = { "처인구", "기흥구", "수지구" };
			strcpy_s(Address + lenofDo3 - 1 + lenofSi, lenofGu, UnderSi[RandomValue(NumberOfUnderSi)]);
			break;
		case 4:
			--NumberOfUnderSi;
			ChosenUnderSi = RandomValue(NumberOfUnderSi);
			const char* UnderSi[3] = { "만안구", "동안구" };
			strcpy_s(Address + lenofDo3 - 1 + lenofSi, lenofGu, UnderSi[RandomValue(NumberOfUnderSi)]);
			break;
		case 5:
			--NumberOfUnderSi;
			ChosenUnderSi = RandomValue(NumberOfUnderSi);
			const char* UnderSi[3] = { "상록구", "단원구" };
			strcpy_s(Address + lenofDo3 - 1 + lenofSi, lenofGu, UnderSi[RandomValue(NumberOfUnderSi)]);
			break;
		default:
			break;
		}
		break;
	case 1://"춘천시 ", "원주시 ", "속초시 ", "홍천군 ", "평창군 "
		strcpy_s(Address, lenofDo3, Do[ChosenDo]);
		strcpy_s(Address + sizeof(char) * lenofDo3 - 1, lenofSi, Si1[ChosenSi]);
		char** UnderSi[NUMBER_OF_Si] = { {}, {}, {}, {}, {} };
		break;
	case 2://"공주시 ", "아산시 ", "천안시 ", "논산시 ", "서산시 "
		strcpy_s(Address, lenofDo4, Do[ChosenDo]);
		strcpy_s(Address + sizeof(char) * lenofDo4 - 1, lenofSi, Si2[ChosenSi]);
		char** UnderSi[NUMBER_OF_Si] = { {}, {}, {}, {}, {} };
		break;
	case 3://"괴산군 ", "제천시 ", "청주시 ", "영동군 ", "제천시 "
		strcpy_s(Address, lenofDo4, Do[ChosenDo]);
		strcpy_s(Address + sizeof(char) * lenofDo4 - 1, lenofSi, Si3[ChosenSi]);
		char** UnderSi[NUMBER_OF_Si] = { {}, {}, {}, {}, {} };
		break;
	case 4://"나주시 ", "해남군 ", "보성군 ", "순천시 ", "남양군 "
		strcpy_s(Address, lenofDo4, Do[ChosenDo]);
		strcpy_s(Address + sizeof(char) * lenofDo4 - 1, lenofSi, Si4[ChosenSi]);
		char** UnderSi[NUMBER_OF_Si] = { {}, {}, {}, {}, {} };
		break;
	case 5://"전주시 ", "군산시 ", "익산군 ", "남원군 ", "정읍군 "
		strcpy_s(Address, lenofDo4, Do[ChosenDo]);
		strcpy_s(Address + sizeof(char) * lenofDo4 - 1, lenofSi, Si5[ChosenSi]);
		char** UnderSi[NUMBER_OF_Si] = { {}, {}, {}, {}, {} };
		break;
	case 6://"진주시 ", "창원시 ", "김해시 ", "거제시 ", "양산시 "
		strcpy_s(Address, lenofDo4, Do[ChosenDo]);
		strcpy_s(Address + sizeof(char) * lenofDo4 - 1, lenofSi, Si6[ChosenSi]);
		char** UnderSi[NUMBER_OF_Si] = { {}, {}, {}, {}, {} };
		break;
	case 7://"포항시 ", "경주시 ", "김천시 ", "안동시 ", "구미시 "
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