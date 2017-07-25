#pragma once
#include "Itest.h"
class TestReview : public ITest
{
public:
	IMPLEMENT_GET_NAME(TestReview);
	TestReview();
	~TestReview();
	virtual void run() override;
};

