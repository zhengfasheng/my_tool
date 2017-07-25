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
 *  Date:2017/7/25 21:47
 *
 *  Summary:所有测试的管理器
 *  
 ******************************************************************************/
#pragma once
#include "common.h"
class IManager;
//class TestManager : public Sigleton<TestManager>
class TestManager
{
	IMPLEMENT_SINGLETON(TestManager);
public:
	TestManager();

	virtual ~TestManager();

	virtual void run() final;

public:

	void registerManger( IManager* pManager);
	void registerManger();
	void excuteManager();

	std::vector<IManager*> m_managers;
};

//SINGLETON_INIT(TestManager);