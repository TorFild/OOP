#include "CppUnitTest.h"
#include "../Lab3/polygon.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab7Tests
{
    TEST_CLASS(Lab7Tests)
    {
    public:
        TEST_METHOD(TestPolygon_Int_ArrayAndArea)
        {
            int coords[] = { 0, 0, 4, 0, 4, 3, 0, 3 };
            Polygon<int> rect(4, coords);

            Assert::AreEqual(4, rect.GetVertexCount());
            Assert::AreEqual(4, rect.GetVertexX(1));
            Assert::AreEqual(3, rect.GetVertexY(2));
            Assert::AreEqual(12.0, rect.GetArea(), 0.001);
        }

        TEST_METHOD(TestPolygon_Int_SetVertex)
        {
            Polygon<int> tri(3);
            bool ok = tri.SetVertex(0, 0, 0) && tri.SetVertex(1, 6, 0) && tri.SetVertex(2, 0, 4);
            bool outOfBounds = tri.SetVertex(5, 10, 10); 

            Assert::IsTrue(ok);
            Assert::IsFalse(outOfBounds);
            Assert::AreEqual(6, tri.GetVertexX(1));
            Assert::AreEqual(4, tri.GetVertexY(2));
            Assert::AreEqual(12.0, tri.GetArea(), 0.001);
        }

        TEST_METHOD(TestPolygon_Double_RegularRadius)
        {
            Polygon<double> square(4, 5.0);

            Assert::AreEqual(4, square.GetVertexCount());
            Assert::AreEqual(5.0, square.GetVertexX(0), 0.001);
            Assert::AreEqual(0.0, square.GetVertexY(0), 0.001);
            Assert::AreEqual(50.0, square.GetArea(), 0.001);
        }

        TEST_METHOD(TestPolygon_Float_CopyConstructor)
        {
            Polygon<float> original(3);
            original.SetVertex(0, 0.0f, 0.0f);
            original.SetVertex(1, 3.5f, 0.0f);
            original.SetVertex(2, 0.0f, 2.0f);

            Polygon<float> copy(original);

            original.SetVertex(1, 10.0f, 0.0f);

            Assert::AreEqual(3.5f, copy.GetVertexX(1), 0.001f);
            Assert::AreEqual(2.0f, copy.GetVertexY(2), 0.001f);
            Assert::AreEqual(3.5, copy.GetArea(), 0.001);
        }

        TEST_METHOD(TestPolygon_DefaultConstructor)
        {
            Polygon<double> emptyPoly;

            Assert::AreEqual(0, emptyPoly.GetVertexCount());
            Assert::AreEqual(0.0, emptyPoly.GetArea(), 0.001);
            Assert::AreEqual(0.0, emptyPoly.GetVertexX(0), 0.001);
        }
    };
}
