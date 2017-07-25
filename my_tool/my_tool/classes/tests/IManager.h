/******************************************************************************
 * Copyright (c) 2017 . All rights reserved.
 *
 *
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  Author:Zheng Fasheng
 *  
 *  Email:zheng_fasheng@qq.com
 *
 *  Date:2017/7/25 21:50
 *
 *  Summary:所有测试管理器接口类
 *  
 ******************************************************************************/
#pragma once

#include "common.h"

#define IMPLEMENT_MANAGER( _TYPE_ )\
IMPLEMENT_SINGLETON(_TYPE_)\
IMPLEMENT_GET_NAME(_TYPE_)

#define RIGISTER_MANAGER( _TYPE_ )\
registerManger(_TYPE_::getInstance())

class ITest;
class IManager
{
public:
	IManager();
	virtual ~IManager();

	virtual void run();

	virtual std::string getName() = 0;

	virtual bool isUsing() { return true; }

	virtual void destory();

protected:

	virtual void registerTest(ITest* pTest) final;

	virtual void registerTest() = 0;

	virtual void excuteTest() final;

private:

	std::vector<ITest*> m_tests;
};