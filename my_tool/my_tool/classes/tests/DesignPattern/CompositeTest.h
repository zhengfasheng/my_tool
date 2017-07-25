#pragma once
#include "ITest.h"
#include "Composite.h"
#include <numeric>
#include <time.h>

class CompositeTest : public ITest
{
public:
	virtual std::string getName() override
	{
		return "���ģʽ";
	}

	virtual void run() override
	{
		using namespace Composite;

		/*auto pMenu = Menu::create("����1");
		auto pMenu1_1 = Menu::create("����1-1");
		auto pMenu1_2 = Menu::create("����1-2");
		auto pMenu1_3 = Menu::create("����1-3");
		pMenu->addChild(pMenu1_1);
		pMenu->addChild(pMenu1_2);
		pMenu->addChild(pMenu1_3);

		auto pMenu1_1_1 = Menu::create("����1-1-1");
		auto pMenu1_1_2 = MenuItem::create("����1-1-2");
		pMenu1_1->addChild(pMenu1_1_1);
		pMenu1_1->addChild(pMenu1_1_2);

		auto pMenu1_1_1_1 = MenuItem::create("����1-1-1-1");
		pMenu1_1_1->addChild(pMenu1_1_1_1);

		pMenu->display();*/
		
		auto pMenu = Menu::create("��������");
		auto pSubMenu = Menu::create("ʱ������");

		pSubMenu->addChild(MenuItem::create("ʱ������"));
		pSubMenu->addChild(MenuItem::create("ʱ��Ҫ��"));

		pMenu->addChild(pSubMenu);
		pMenu->addChild(MenuItem::create("�������"));

		pMenu->display();

		pMenu = Menu::create("��������");
		pMenu->addChild(MenuItem::create("����Ҫ��"));
		pMenu->addChild(MenuItem::create("������Ұ"));
		pMenu->display();
		

		Pool::getInstance()->tick();

		
	}
};