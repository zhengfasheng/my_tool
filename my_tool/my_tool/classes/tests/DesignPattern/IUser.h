#pragma once
//�����Ʒ
#include <iostream>
using namespace std;
class IUser
{
public:
	IUser(){}
	virtual ~IUser(){}
	virtual void insert() = 0;
	virtual void getUser() = 0;
};

