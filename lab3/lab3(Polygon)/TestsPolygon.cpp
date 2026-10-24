#include "CppUnitTest.h"
#include "../Lab3/polygon.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsPolygon
{
	TEST_CLASS(TestsPolygon)
	{
	public:
		
		TEST_METHOD(TestDefaultConstructor)
		{
			Polygon p;
			Assert::AreEqual(0, p.GetVertexCount());
			Assert::AreEqual(0.0, p.GetArea());
			Assert::AreEqual(0.0, p.GetVertexX(0));
		}


		TEST_METHOD(TestInitEmptyConstructor)
		{
			Polygon p(3);
			Assert::AreEqual(3, p.GetVertexCount());
			Assert::AreEqual(0.0, p.GetVertexX(1));
			Assert::AreEqual(0.0, p.GetArea());
		}


		TEST_METHOD(TestArrayConstructorAndArea)
		{
			double coords[] = { 0, 0, 4, 0, 4, 3, 0, 3 };
			Polygon p(4, coords);

			Assert::AreEqual(4, p.GetVertexCount());
			Assert::AreEqual(4.0, p.GetVertexX(1)); 
			Assert::AreEqual(0.0, p.GetVertexY(1)); 
			Assert::AreEqual(12.0, p.GetArea());    
		}


		TEST_METHOD(TestCopyConstructor)
		{
			double coords[] = { 0, 0, 4, 0, 4, 3, 0, 3 };
			Polygon original(4, coords);
			Polygon copy(original);

			original.SetVertex(0, 99.0, 99.0);

			Assert::AreEqual(4, copy.GetVertexCount());
			Assert::AreEqual(12.0, copy.GetArea());
			Assert::AreEqual(0.0, copy.GetVertexX(0)); 
		}

		TEST_METHOD(TestRadiusConstructor)
		{
			Polygon p(4, 5.0);

			Assert::AreEqual(4, p.GetVertexCount());

			Assert::AreEqual(5.0, p.GetVertexX(0));

			Assert::AreEqual(50.0, p.GetArea());
		}

	};
}
