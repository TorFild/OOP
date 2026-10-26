
#include "CppUnitTest.h"
#include "../Lab4/lift.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab2Tests
{
	TEST_CLASS(Lab2Tests)
	{
	public:

		TEST_METHOD(TestDefaultConstructor)
		{
			Lift lift;


			Assert::AreEqual(1, lift.GetFloorNum());

			Assert::IsFalse(lift.GetDoorsState());

			Assert::AreEqual((int)STOPPED, (int)lift.GetEngineCon());

			Assert::AreEqual(0, lift.GetFloorWeight());

			Assert::AreEqual((int)IDLE, (int)lift.GetGeneralCon());

		}

		TEST_METHOD(TestUnitConstructor) {
			Lift lift(5, 100);

			Assert::AreEqual(5, lift.GetFloorNum());
			Assert::AreEqual(100, lift.GetFloorWeight());

			Assert::IsFalse(lift.GetDoorsState());
			Assert::AreEqual((int)STOPPED, (int)lift.GetEngineCon());
			Assert::AreEqual((int)IDLE, (int)lift.GetGeneralCon());


		}

		TEST_METHOD(TestCopyConstructor)
		{
			Lift originalLift(3, 150);

			Lift copiedLift(originalLift);

			Assert::AreEqual(3, copiedLift.GetFloorNum());
			Assert::AreEqual(150, copiedLift.GetFloorWeight());
			Assert::IsFalse(copiedLift.GetDoorsState());
			Assert::AreEqual((int)STOPPED, (int)copiedLift.GetEngineCon());
			Assert::AreEqual((int)IDLE, (int)copiedLift.GetGeneralCon());

		}

		TEST_METHOD(TestStartUp) {
			Lift lift;

			lift.Start(5);

			Assert::IsFalse(lift.GetDoorsState());
			Assert::AreEqual((int)UP, (int)lift.GetEngineCon());
			Assert::AreEqual((int)CALL, (int)lift.GetGeneralCon());
		}

		TEST_METHOD(TestLoadCabin) {
			Lift lift;

			lift.LoadCabin(150);

			Assert::AreEqual(150, lift.GetFloorWeight());
		}

		TEST_METHOD(TestLaunchSuccess) {
			Lift lift;


			lift.LoadCabin(110);

			lift.Launch(5);

			Assert::IsFalse(lift.GetDoorsState());

			Assert::AreEqual((int)UP, (int)lift.GetEngineCon());

			Assert::AreEqual((int)TRANSPORT, (int)lift.GetGeneralCon());

		}

		TEST_METHOD(TestLauchEmptySafety) {
			Lift lift;


			lift.Launch(5);

			Assert::AreEqual((int)STOPPED, (int)lift.GetGeneralCon());

			Assert::AreEqual((int)IDLE, (int)lift.GetGeneralCon());

		}

		TEST_METHOD(TestEnd) {
			Lift lift;

			lift.End(3);

			Assert::AreEqual(3, lift.GetFloorNum());

			Assert::AreEqual((int)STOPPED, (int)lift.GetEngineCon());

			Assert::IsTrue(lift.GetDoorsState());

			Assert::AreEqual((int)IDLE, (int)lift.GetGeneralCon());

		}


		TEST_METHOD(TestStop) {
			Lift lift;


			lift.Stop(2);

			Assert::AreEqual(2, lift.GetFloorNum());
			Assert::AreEqual((int)STOPPED, (int)lift.GetEngineCon());
			Assert::IsTrue(lift.GetDoorsState());
			Assert::AreEqual((int)IDLE, (int)lift.GetGeneralCon());

		}


		TEST_METHOD(TestOperatorPlusEqualsValid)
		{
			Lift lift(1, 0); 
			lift += 80;
			Assert::AreEqual(80, lift.GetFloorWeight());
		}

		TEST_METHOD(TestOperatorPlusEqualsOverload)
		{
			Lift lift(1, 200); 
			lift += 100;       

			Assert::AreEqual(200, lift.GetFloorWeight());
		}

		TEST_METHOD(TestOperatorPrefixIncrement)
		{
			Lift lift;
			++lift;

			Assert::IsFalse(lift.GetDoorsState());
		}

		TEST_METHOD(TestOperatorPrefixDecrement)
		{
			Lift lift;
			++lift; 
			--lift; 

			Assert::IsTrue(lift.GetDoorsState());
		}


	};
}
