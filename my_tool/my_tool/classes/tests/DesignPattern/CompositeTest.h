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
		return "组合模式";
	}

	virtual void run() override
	{
		using namespace Composite;

		/*auto pMenu = Menu::create("标题1");
		auto pMenu1_1 = Menu::create("标题1-1");
		auto pMenu1_2 = Menu::create("标题1-2");
		auto pMenu1_3 = Menu::create("标题1-3");
		pMenu->addChild(pMenu1_1);
		pMenu->addChild(pMenu1_2);
		pMenu->addChild(pMenu1_3);

		auto pMenu1_1_1 = Menu::create("标题1-1-1");
		auto pMenu1_1_2 = MenuItem::create("标题1-1-2");
		pMenu1_1->addChild(pMenu1_1_1);
		pMenu1_1->addChild(pMenu1_1_2);

		auto pMenu1_1_1_1 = MenuItem::create("标题1-1-1-1");
		pMenu1_1_1->addChild(pMenu1_1_1_1);

		pMenu->display();*/
		
		auto pMenu = Menu::create("国内新闻");
		auto pSubMenu = Menu::create("时事新闻");

		pSubMenu->addChild(MenuItem::create("时事政治"));
		pSubMenu->addChild(MenuItem::create("时事要闻"));

		pMenu->addChild(pSubMenu);
		pMenu->addChild(MenuItem::create("社会新闻"));

		pMenu->display();

		pMenu = Menu::create("国际新闻");
		pMenu->addChild(MenuItem::create("国际要闻"));
		pMenu->addChild(MenuItem::create("环球视野"));
		pMenu->display();
		

		Pool::getInstance()->tick();

		
	}
};