#include "CppUnitTest.h"
#include "../Lab5/space_objects.hpp"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab5Tests
{
	TEST_CLASS(Lab5Tests)
	{
	public:
		
		TEST_METHOD(TestPolymorphism_Parallelepiped)
		{
			SpaceObject* objPtr = new Parallelepiped(0.0, 0.0, 0.0, 2.0, 3.0, 4.0);

			objPtr->ScaleToVolume(1000.0);

			Assert::AreEqual(1000.0, objPtr->GetVolume(), 0.001);

			delete objPtr;
		}

		TEST_METHOD(TestPolymorphism_Sphere)
		{
			SpaceObject* objPtr = new Sphere(0.0, 0.0, 0.0, 3.0);

			objPtr->ScaleToVolume(500.0);

			Assert::AreEqual(500.0, objPtr->GetVolume(), 0.001);

			delete objPtr;
		}

		TEST_METHOD(TestParallelepiped_InitialVolume)
		{
			Parallelepiped p(0.0, 0.0, 0.0, 2.0, 3.0, 4.0); 
			Assert::AreEqual(24.0, p.GetVolume(), 0.001, L"Помилка розрахунку початкового об'єму паралелепіпеда");
		}

		TEST_METHOD(TestParallelepiped_ChangeSize)
		{
			Parallelepiped p(0.0, 0.0, 0.0, 2.0, 3.0, 4.0);
			p.ChangeSize(5.0, 5.0, 5.0);
			Assert::AreEqual(125.0, p.GetVolume(), 0.001, L"Помилка розрахунку об'єму після ChangeSize");
		}

		TEST_METHOD(TestSpaceObject_MovePolymorphic)
		{
			SpaceObject* objPtr = new Sphere(1.0, 2.0, 3.0, 5.0);
			objPtr->Move(2.0, -1.0, 5.0);

			Assert::AreEqual(3.0, objPtr->GetX(), 0.001);
			Assert::AreEqual(1.0, objPtr->GetY(), 0.001);
			Assert::AreEqual(8.0, objPtr->GetZ(), 0.001);

			delete objPtr;
		}

		
		TEST_METHOD(TestSphere_InitialVolume)
		{
			Sphere s(0.0, 0.0, 0.0, 3.0); 
			double expected_volume = (4.0 / 3.0) * acos(-1.0) * pow(3.0, 3);
			Assert::AreEqual(expected_volume, s.GetVolume(), 0.001, L"Помилка розрахунку початкового об'єму сфери");
		}

		TEST_METHOD(TestSphere_ChangeRadius)
		{
			Sphere s(0.0, 0.0, 0.0, 3.0);
			s.ChangeRadius(5.0);
			double expected_volume = (4.0 / 3.0) * acos(-1.0) * pow(5.0, 3);
			Assert::AreEqual(expected_volume, s.GetVolume(), 0.001, L"Помилка об'єму після ChangeRadius");
		}

		TEST_METHOD(TestSphere_ScaleToVolume)
		{
			Sphere s(0.0, 0.0, 0.0, 3.0);
			s.ScaleToVolume(500.0);
			Assert::AreEqual(500.0, s.GetVolume(), 0.001, L"Помилка при зворотньому розрахунку радіусу (ScaleToVolume)");
		}




	};


}
