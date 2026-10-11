
#include "CppUnitTest.h"
#include "..\Lab2\lift.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab2Tests
{
	TEST_CLASS(Lab2Tests)
	{
	public:
		
		TEST_METHOD(TestReset)
		{
			Lift lift;
			lift.Reset();

			Assert::AreEqual(1, lift.GetFloorNum());

			Assert::IsFalse(lift.GetDoorsState());

			Assert::AreEqual((int)STOPPED, (int)lift.GetEngineCon());
		}

		TEST_METHOD(TestStartUp)  {
			Lift lift;
			lift.Reset(); 
			lift.Start(5);

			Assert::IsFalse(lift.GetDoorsState());
			Assert::AreEqual((int)UP, (int)lift.GetEngineCon()); 
			Assert::AreEqual((int)CALL, (int)lift.GetGeneralCon());
		}

		TEST_METHOD(TestLoadCabin) {
			Lift lift;
			lift.Reset();
			lift.LoadCabin(150);

			Assert::AreEqual(150, lift.GetFloorWeight());
		}

		TEST_METHOD(TestLaunchSuccess) {
			Lift lift;
			lift.Reset();
		
			lift.LoadCabin(110);

			lift.Launch(5);

			Assert::IsFalse(lift.GetDoorsState());

			Assert::AreEqual((int)UP, (int)lift.GetEngineCon());

			Assert::AreEqual((int)TRANSPORT, (int)lift.GetGeneralCon());

		}

		TEST_METHOD(TestLauchEmptySafety) {
			Lift lift;
			lift.Reset();

			lift.Launch(5);

			Assert::AreEqual((int)STOPPED, (int)lift.GetGeneralCon());

			Assert::AreEqual((int)IDLE, (int)lift.GetGeneralCon());

		}

		TEST_METHOD(TestEnd) {
			Lift lift;
			lift.Reset();

			lift.End(3);

			Assert::AreEqual(3, lift.GetFloorNum());

			Assert::AreEqual((int)STOPPED, (int)lift.GetEngineCon());

			Assert::IsTrue(lift.GetDoorsState());

			Assert::AreEqual((int)IDLE, (int)lift.GetGeneralCon());

		}


		TEST_METHOD(TestStop) {
			Lift lift;
			lift.Reset();


			lift.Stop(2);

			Assert::AreEqual(2, lift.GetFloorNum());
			Assert::AreEqual((int)STOPPED, (int)lift.GetEngineCon());
			Assert::IsTrue(lift.GetDoorsState());
			Assert::AreEqual((int)IDLE, (int)lift.GetGeneralCon());

		}

	};
}
