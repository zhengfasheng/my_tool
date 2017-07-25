#include "DesignPatternManager.h"
#include "FactoryTest.h"
#include "AbstractFactoryTest.h"
#include "TemplateTest.h"
#include "BuilderTest.h"
#include "DelegateTest.h"
#include "PrototypeTest.h"
#include "MediatorTest.h"
#include "CommandTest.h"
#include "ResponsibilityTest.h"
#include "DecoratorTest.h"
#include "StrategyTest.h"
#include "AdapterTest.h"
#include "IteratorTest.h"
#include "CompositeTest.h"
#include "ObserverTest.h"
#include "FacadeTest.h"
#include "MementoTest.h"
#include "VisitorTest.h"
#include "StateTest.h"
#include "FlyweightTest.h"
#include "BridgeTest.h"

void DesignPatternManager::registerTest()
{
	RIGISTER_TEST(FactoryTest);
	RIGISTER_TEST(AbstractFactoryTest);
	RIGISTER_TEST(TemplateTest);
	RIGISTER_TEST(BuilderTest);
	RIGISTER_TEST(DelegateTest);
	RIGISTER_TEST(PrototypeTest);
	RIGISTER_TEST(MediatorTest);
	RIGISTER_TEST(CommandTest);
	RIGISTER_TEST(ResponsibilityTest);
	RIGISTER_TEST(DecoratorTest);
	RIGISTER_TEST(StrategyTest);
	RIGISTER_TEST(AdapterTest);
	RIGISTER_TEST(IteratorTest);
	RIGISTER_TEST(CompositeTest);
	RIGISTER_TEST(ObserverTest);
	RIGISTER_TEST(FacadeTest);
	RIGISTER_TEST(MementoTest);
	RIGISTER_TEST(VisitorTest);
	RIGISTER_TEST(StateTest);
	RIGISTER_TEST(FlyweightTest);
	RIGISTER_TEST(BridgeTest);
}
