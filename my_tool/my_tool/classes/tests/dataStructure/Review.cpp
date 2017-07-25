#include "Review.h"
#include <iostream>
#include <assert.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

TestReview::TestReview()
{
}


TestReview::~TestReview()
{
}

int func(int x){
	int count = 0;
	while (x){
		count++;
		x = x & (x - 1);
	}
	return count;
}

char* mystrcpy(char* dest, const char* src)
{
	assert(dest != nullptr && src != nullptr);

	char* result = dest;
	while ((*result++ = *src++) != '\0');
	*result = '\0';
	return dest;
}

int Strlen(char* src)
{
	assert(src != nullptr);
	char* szEnd = src;
	while (*szEnd++ != '\0');
	return szEnd - src - 1;
}

char *MyReserse(char* src)
{
	if (src)
	{
		char * pTemp = src;

		int nLenth = Strlen(src);
		char temp;
		for (int i = 0; i < nLenth / 2 ; i++ )
		{
			temp = src[i];
			src[i] = src[nLenth - i - 1];
			src[nLenth - i - 1] = temp;
		}
		/*int nCount = (nLenth ) / 2;
		int i = 0;
		char cTemp = '\0';
		while (i <= nCount)
		{
			cTemp = *(src + i);
			*(src + i) = *(pTemp - i);
			*(pTemp - i) = cTemp;
			i++;

		}*/
		
	}
	return src;
}



char* reverseString(char* src)
{
	assert(src != nullptr);
	char* szStart = src;
	char* szEnd = src + Strlen(src);
	char temp;
	for (; szStart != szEnd && szStart != --szEnd ; szStart++ )
	{
		temp = *szStart;
		*szStart = *szEnd;
		*szEnd = temp;
	}
	return src;
}

char* reverseStringEx(char* src)
{
	assert(src != nullptr);
	char* szStart = src;
	char* szEnd = src + strlen(src) - 1;
	char temp;
	while ( szStart < szEnd )
	{
		temp = *szStart;
		*szStart = *szEnd;
		*szEnd = temp;
		szStart++;
		szEnd--;
	}
	return src;
}

char* replace(char * szSrc, char *szOut, char *szCmp, char *szReplaceChar)
{
	assert(szSrc != nullptr && szOut != nullptr && szCmp != nullptr && szReplaceChar != nullptr);
	char* pCurSrc, *pCurCmp, *pCurReplaceChar,*szResult = szOut;
	
	while( *szSrc != '\0' )
	{
		pCurCmp = szCmp;
		if ( *szSrc == *pCurCmp )
		{
			for (pCurSrc = szSrc, pCurCmp = szCmp; (*pCurSrc == *pCurCmp && *pCurCmp != '\0');pCurSrc++,pCurCmp++)
			{
				*szOut++ = *szSrc++;
				if ( *(pCurCmp + 1) == '\0' )
				{
					szOut -= strlen(szCmp);
					for (pCurReplaceChar = szReplaceChar; *pCurReplaceChar != '\0';)
					{
						*szOut++ = *pCurReplaceChar++;
					}
				}
			}
		}
		else
		{
			*szOut++ = *szSrc++;
		}
		
	}
	*szOut = '\0';
	return szResult;
}


#define myswap( a , b ){\
	(a) = (a) ^ (b);\
	(b) = (a) ^ (b);\
	(a) = (a) ^ (b);\
}

#define MySwap( a , b ){\
	(a) ^= (b);\
	(b) ^= (a);\
	(a) ^= (b);\
}


class Animal  
{
public: 
	virtual char * getType() const 
	{return "Animal";} 
	virtual char * getVoice() const 
	{return "Voice";} 
};    
class Dog:public Animal 
{
public: 
	virtual char *getType() const 
	{return "Dog";} 
	virtual char *getVoice() const 
	{return "Woof";} 
};  
void type(Animal &a) 
{cout<<a.getType();} // ��������: Animal �����ö���a void speak(Animal a) {cout<<a.getVoice();}//��������������ʲô����? Animal�����a    int main() { Dog d;type(d); cout<<"speak";speak(d);cout<<endl; return 0; } ���н����: DogspeaksVoice �����ʵ���,Ϊʲô������� DogspeaksWoof Ҳ����˵ void type(Animal &a) {cout<<a.getType();}  void speak(Animal a) {cout<<a.getVoice();}  

//Сдת��д
char* upperCase(char* src)
{
	assert(src != nullptr);

	char* result = src;
	while ( *result != '\0' )
	{
		if (*result >= 'a' && *result <= 'z')
		{
			*result -= 'a' - 'A';
		}
		result++;
	}
	return src;
}

char* lowerCase(char* src)
{
	assert(src != nullptr);
	char* result = src;
	while (*result != '\0')
	{
		if (*result >= 'A' && *result <= 'Z')
		{
			*result += 'a' - 'A';
		}
		result++;
	}
	return src;
}

//ת��������
string vec_tostring(vector<int>& vec)
{
	int i = 0;
	//���������ǰ���0����100 * 10 = 1000 ����ʱ������Ԫ�ؽṹΪ{0,1,0,0,0}
	while (i < vec.size())
	{
		if (vec[i] > 0)
			break;
		i++;
	}
	string result = "";
	while (i < vec.size())
	{
		result += static_cast<char>(vec[i++] + '0');
	}

	return result;
}

//�˷�
string multiply(string num1, string num2)
{
	//��ʼ��������ݵ����ݴ�С
	//�������������Ϊ�ҵ�������λ�õ����� ��99 * 99 = 9801
	auto numSize1 = num1.size();
	auto numSize2 = num2.size();
	int totolNum = numSize1 + numSize2;
	vector<int> numVec(totolNum, 0);
	
	//�Ӻ���ǰ��
	//123 * 234 = 3 * 234 + 2 * 234 + 1 * 234
	int i = 0;
	for (i = numSize1 - 1; i >= 0; i-- )
	{
		//�õ����λ�õ���ʵ����ֵ
		int n1 = num1[i] - '0';
		int nSurplus = 0;//��¼��һ����˵õ��Ľ�λ�� �� �� 3 * 4 = 12��λ��
 		for (int j = numSize2 - 1; j >= 0; j--)
		{
			int n2 = num2[j] - '0';
			//����ط���1����Ϊ����123 *234 ʱ�����λ��Ӧ������5��λ�ã��������Ǵ�����±꿪ʼ
			nSurplus = n1 * n2 + nSurplus + numVec[i + j + 1];
			numVec[i + j + 1] = nSurplus % 10;
			nSurplus = nSurplus / 10;

		}
		numVec[i] = nSurplus;

	}
	
	return vec_tostring(numVec);
}

//�ӷ�
string addstring(string num1, string num2)
{
	int nLen1 = num1.length();
	int nLen2 = num2.length();
	int nMaxLen = ( nLen1 > nLen2 ? nLen1 : nLen2) + 1;
	
	string minStr = num1;
	string maxStr = num2;
	if (nLen1 > nLen2)
	{
		minStr = num2;
		maxStr = num1;
	}

	vector<int> numVec(nMaxLen, 0);
	int i = 0;
	int nTemp = 0;
	int j = minStr.size() -1;
	for ( i = maxStr.size() - 1; i >= 0 ; i--)
	{
		int n1 = maxStr[i] - '0';
		int n2 = j >= 0 ? minStr[j] - '0' : 0 ;
		nTemp = n1 + n2 + nTemp + numVec[i + 1];
		numVec[ i + 1] = nTemp % 10;
		nTemp /= 10;
		j--;
	}

	return vec_tostring(numVec);
}

//�����������Ǹ�����
string minusString(string num1, string num2)
{
	string minStr = num1;//12
	string maxStr = num2;//234

	//��������ȷ������λ
	bool isPositive = false;

	if ( minStr.size() > maxStr.size() )
	{
		maxStr = num1;
		minStr = num2;
		isPositive = true;
	}

	vector<int> numVec(maxStr.size(), 0);

	int i = 0;
	int j = minStr.size() -1;
	int k = 1;
	int nTemp = 0;
	for (i = maxStr.size() - 1; i >= 0;i--)
	{
		int n1 = maxStr[i] - '0';
		int n2 = j>= 0 ? minStr[j] - '0' : 0;
		if (n1 < n2)//��������Ҫ���λ��
		{
			k = 1;
			while ( i - k < maxStr.size() && maxStr[i - k] == '0' )//��Ҫ���λ��
			{
				maxStr[i - k] = '9';
				k++;
			}
			//�������Ѿ�����0�ˣ�����ֱ�Ӽ�ASC��
			maxStr[i - k] -= 1;
			n1 = 10 + n1;
		}
		numVec[i] = n1 - n2;
		j--;
	}
	
	string str = vec_tostring(numVec);
	if (!isPositive)
	{
		str = '-' + str;
	}

	return str;
}

//����
string divisionString(string num1, string num2)
{
	return "";
}

void TestReview::run()
{

	string ret = minusString("378", "8934");
	string ret2 = multiply("33555353553535353535353535353535", "465868886868686866868");
	cout << ret << endl;
	cout << ret2 << endl;
	//char szStr[] = "ababac";

	//upperCase(szStr);
	//cout << szStr << endl;
	//lowerCase(szStr);
	//cout << szStr << endl;
	//cout << szStr << endl;
	//reverseStringEx(szStr);
	//MyReserse(nullptr);
	//Strlen(nullptr);
	//char buf[200] = { 0 };
	//replace(szStr, buf, "a", "xx");
	//reverseString(szStr);
	//cout << buf << endl;

	//Dog* pDog = new Dog;
	//type(*pDog);

	//Dog dog;
	//type(dog);

	/*
	int m = 7;
	int n = 4;
	int k = 0;
	while ( (m--) > (++n))
	{
		k++;
	}
	cout << "k = " << k << endl;

	//0110
	//1010
	//1100
	//1010
	//0110 = 6
	k = 6;
	k ^= 10;
	k ^= 10;
	cout << k << endl;

	cout << func(9999) << endl;
	cout << func(8888) << endl;


	char buf1[100] = "zheng fa sheng";
	char buf2[100] = "lkjkljkljlkjlklk";
	mystrcpy(buf2, buf1);
	cout << buf2 << endl;
	*/

	/*
	int i = 1; int k = -14;
	switch (i)
	{
	case  1: k++;
	case 2:k += i; break;
	case 10:k += 3; break;
	default: k /= i;
		break;
	}

	cout << k << endl;
	*/
	/*
	int k = 0;
	while ( ++k < 4 )
	{

	}
	cout << k << endl;
	*/
	//001 
	//010 
	//011 a
	//001 b
	//010
	
	//int a = 10;
	//int b = 20;
	//MySwap(a, b);
	//cout << a << " " << b << endl;
	
}
