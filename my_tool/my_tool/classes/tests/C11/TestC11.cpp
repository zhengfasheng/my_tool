#include "TestC11.h"

void myPrint()
{}

template<class T, class... Types>
void myPrint(const T& value, Types... args)
{
	cout << value << endl;
	myPrint(args...);

}

void split(string szText, vector<string>& vec)
{
	vec.clear();
	size_t nend = 0;
	string szCut = "";
	while (szText.size() > 0 && nend < szText.size())
	{
		if (szText[nend] == '\n')
		{
			szCut = szText.substr(0, nend);
			vec.push_back(szCut);
			szText = szText.substr(nend + 1);
			nend = 0;
		}
		else if (szText[nend] == '\\' && nend + 1 < szText.size() && szText[nend + 1] == 'n')
		{
			szCut = szText.substr(0, nend);
			vec.push_back(szCut);
			szText = szText.substr(nend + 2);
			nend = 0;
		}
		else
		{
			nend++;
		}
	}
	if (szText.size() > 0)
	{
		vec.push_back(szText);
	}
}

//{
// Type + ID这是一个
// { 
// Type + IDssssss
// { 
// Type + ID测 
// }试 }的字符串}\{1000\}

struct ParseData
{
	int nIndex;
	int nType;
	int nID;
	string szContent;
};

void parseString(const string& szContent, vector<ParseData>& vec)
{
	string szText = szContent;
	auto isType = [](const string& szContent, int nStartPos, int nCount, int& nID, int& nType)->bool
	{

		if (nStartPos + nCount < szContent.size())
		{
			string szText = szContent.substr(nStartPos, nCount);
			for (int i = 0; i < szText.size(); i++)
			{
				if (!isdigit(szText[i]))
				{
					return false;
				}
			}
			szText = szContent[nStartPos];
			nType = atoi(szText.data());
			szText = szContent.substr(nStartPos + 1, nCount - 1);
			nID = atoi(szText.data());
			return true;
		}
		else
		{
			return false;
		}
	};

	int nID = 0;
	int nType = 0;
	int nIndex = 0;
	std::vector< ParseData > lableStack;

	for (size_t i = 0; i < szText.size(); i++)
	{
		if (szText[i] == '{' && isType(szText, i + 1, 4, nID, nType))
		{
			ParseData data;
			data.nID = nID;
			data.nType = nType;
			vec.push_back(data);
			lableStack.push_back(data);
			i += 4;
		}
		else if (szText[i] == '}')
		{
			if (lableStack.size() <= 0)
			{
				cout << "invaild" << endl;
				continue;
			}
			lableStack.pop_back();
			if (lableStack.size() > 0)
			{
				ParseData data = lableStack.back();
				vec.push_back(data);
			}
		}
		else
		{
			ParseData& data = vec.back();
			data.szContent += szText[i];
		}
	}
}

void TestC11::run()
{
	string str = "{1002aaaaaa{2003bbbbbbb}ccccc{3002ddddd{4002eeeeeee}ffffff }ggggg}";

	vector<ParseData> vec;
	parseString(str, vec);

	/*vector<string> vec;
	string szContent = "zjeng\nsfjljsf\nddd\\nssss\\n";
	split(szContent, vec);*/
	int i = 0;
	i++;

	/*char buf[100] = "zheng fa sheng";
	char* szOut = reverseString(buf);
	cout << szOut << endl;*/

	/*
	vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 88, 5 };

	for ( auto& x : vec )
	{
	cout << x << "\t";
	}
	cout << endl;

	std::sort(vec.begin(), vec.end(), [](int a, int b){ return a < b; });

	for (auto& x : vec)
	{
	cout << x << "\t";
	}
	cout << endl;*/
	/*
	String str;
	cout << str;

	String str1("zheng");
	cout << str1;

	char buf[20] = "hello";
	String str3(buf);
	cout << str3;

	string temp = "fasheng";

	String str4(temp);
	cout << str4;

	String str5(str4);
	cout << str5;

	println();

	String&& str6 = "zheng";

	String str7 = str6;

	cout << str6 << "/" << str7;
	str6 = "jjj";
	cout << str6 << "/" << str7;

	cout << (str1 == str3) << endl;

	String str11 = "qqq";
	String str22 = "qqq";
	cout << (str11 != str22) << endl;

	//string strstr = "zjzjjj";

	myPrint(1, 2, 3.4, "ssflkj", 33.454);
	*/
}

