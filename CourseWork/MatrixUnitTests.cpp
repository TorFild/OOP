#include "CppUnitTest.h"
#include "../CourseWork/operation.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MatrixUnitTests
{
    TEST_CLASS(MatrixOperationsTest)
    {
        double** createTestMatrix() {
            double vals[3][3] = {
                { 10.0, -5.5,  8.0 },
                {  4.0,  0.0,  2.5 },
                { -9.0, 14.2, -1.0 }
            };
            double** mat = new double* [3];
            for (int i = 0; i < 3; ++i) {
                mat[i] = new double[3];
                for (int j = 0; j < 3; ++j) mat[i][j] = vals[i][j];
            }
            return mat;
        }

        template <typename T>
        void freeTestMatrix(T** mat, int n) {
            for (int i = 0; i < n; ++i) delete[] mat[i];
            delete[] mat;
        }

    public:
        
        TEST_METHOD(Test_MinAboveMain)
        {
            double** mat = createTestMatrix();
            operation<double>* ptr = createOperation<double>("MinAboveMain", mat, 3);
            Assert::IsNotNull(ptr);
            ptr->execute();

            Assert::AreEqual(-5.5, ptr->getResValue(), 0.001);
            Assert::AreEqual(0, ptr->getResRow());
            Assert::AreEqual(1, ptr->getResCol());

            delete ptr;
            freeTestMatrix(mat, 3);
        }

        TEST_METHOD(Test_MaxAboveMain)
        {
            double** mat = createTestMatrix();
            operation<double>* ptr = createOperation<double>("MaxAboveMain", mat, 3);
            Assert::IsNotNull(ptr);
            ptr->execute();

            Assert::AreEqual(8.0, ptr->getResValue(), 0.001);
            Assert::AreEqual(0, ptr->getResRow());
            Assert::AreEqual(2, ptr->getResCol());

            delete ptr;
            freeTestMatrix(mat, 3);
        }

        TEST_METHOD(Test_MinBelowMain)
        {
            double** mat = createTestMatrix();
            operation<double>* ptr = createOperation<double>("MinBelowMain", mat, 3);
            Assert::IsNotNull(ptr);
            ptr->execute();

            Assert::AreEqual(-9.0, ptr->getResValue(), 0.001);
            Assert::AreEqual(2, ptr->getResRow());
            Assert::AreEqual(0, ptr->getResCol());

            delete ptr;
            freeTestMatrix(mat, 3);
        }

        TEST_METHOD(Test_MaxBelowMain)
        {
            double** mat = createTestMatrix();
            operation<double>* ptr = createOperation<double>("MaxBelowMain", mat, 3);
            Assert::IsNotNull(ptr);
            ptr->execute();

            Assert::AreEqual(14.2, ptr->getResValue(), 0.001);
            Assert::AreEqual(2, ptr->getResRow());
            Assert::AreEqual(1, ptr->getResCol());

            delete ptr;
            freeTestMatrix(mat, 3);
        }

        TEST_METHOD(Test_MinAboveSec)
        {
            double** mat = createTestMatrix();
            operation<double>* ptr = createOperation<double>("MinAboveSec", mat, 3);
            Assert::IsNotNull(ptr);
            ptr->execute();

            Assert::AreEqual(-5.5, ptr->getResValue(), 0.001);
            Assert::AreEqual(0, ptr->getResRow());
            Assert::AreEqual(1, ptr->getResCol());

            delete ptr;
            freeTestMatrix(mat, 3);
        }

        TEST_METHOD(Test_MaxAboveSec)
        {
            double** mat = createTestMatrix();
            operation<double>* ptr = createOperation<double>("MaxAboveSec", mat, 3);
            Assert::IsNotNull(ptr);
            ptr->execute();

            Assert::AreEqual(10.0, ptr->getResValue(), 0.001);
            Assert::AreEqual(0, ptr->getResRow());
            Assert::AreEqual(0, ptr->getResCol());

            delete ptr;
            freeTestMatrix(mat, 3);
        }

        TEST_METHOD(Test_MinBelowSec)
        {
            double** mat = createTestMatrix();
            operation<double>* ptr = createOperation<double>("MinBelowSec", mat, 3);
            Assert::IsNotNull(ptr);
            ptr->execute();

            Assert::AreEqual(-1.0, ptr->getResValue(), 0.001);
            Assert::AreEqual(2, ptr->getResRow());
            Assert::AreEqual(2, ptr->getResCol());

            delete ptr;
            freeTestMatrix(mat, 3);
        }

        TEST_METHOD(Test_MaxBelowSec)
        {
            double** mat = createTestMatrix();
            operation<double>* ptr = createOperation<double>("MaxBelowSec", mat, 3);
            Assert::IsNotNull(ptr);
            ptr->execute();

            Assert::AreEqual(14.2, ptr->getResValue(), 0.001);
            Assert::AreEqual(2, ptr->getResRow());
            Assert::AreEqual(1, ptr->getResCol());

            delete ptr;
            freeTestMatrix(mat, 3);
        }

        TEST_METHOD(Test_InvalidCommandReturnsNullptr)
        {
            double** mat = createTestMatrix();
            operation<double>* ptr = createOperation<double>("UnknownCmd", mat, 3);
            Assert::IsNull(ptr);
            freeTestMatrix(mat, 3);
        }

        TEST_METHOD(Test_TemplateWithIntType)
        {
            int vals[3][3] = {
                { 1, 25,  7 },
                { 4,  5, 19 },
                { 9,  2,  3 }
            };
            int** intMat = new int* [3];
            for (int i = 0; i < 3; ++i) {
                intMat[i] = new int[3];
                for (int j = 0; j < 3; ++j) intMat[i][j] = vals[i][j];
            }

            operation<int>* ptr = createOperation<int>("MaxAboveMain", intMat, 3);
            Assert::IsNotNull(ptr);
            ptr->execute();

            Assert::AreEqual(25, ptr->getResValue());
            Assert::AreEqual(0, ptr->getResRow());
            Assert::AreEqual(1, ptr->getResCol());

            delete ptr;
            freeTestMatrix(intMat, 3);
        }
    };
}
