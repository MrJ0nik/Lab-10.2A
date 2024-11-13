#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab-10.2A/Lab-10.2A.cpp"  

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestSortStudents)
        {
            Student students[3] = {
                {"Ivanenko", 2, COMPUTER_SCIENCE, 4, 5, 3},
                {"Petrenko", 3, MATHEMATICS, 3, 4, 5},
                {"Shevchenko", 1, PHYSICS, 5, 3, 5}
            };

            SortStudents(students, 3);

          
            Assert::AreEqual(string("Petrenko"), students[0].surname);
            Assert::AreEqual(3u, students[0].course);  
            Assert::AreEqual(5, students[0].informatics);

            Assert::AreEqual(string("Shevchenko"), students[1].surname);
            Assert::AreEqual(1u, students[1].course);  
            Assert::AreEqual(5, students[1].informatics);

            Assert::AreEqual(string("Ivanenko"), students[2].surname);
            Assert::AreEqual(2u, students[2].course);  
            Assert::AreEqual(3, students[2].informatics);
        }

        TEST_METHOD(TestIndexSortStudents)
        {
            Student students[3] = {
                {"Ivanenko", 2, COMPUTER_SCIENCE, 4, 5, 3},
                {"Petrenko", 3, MATHEMATICS, 3, 4, 5},
                {"Shevchenko", 1, PHYSICS, 5, 3, 5}
            };

            int indexArray[3];
            IndexSortStudents(students, 3, indexArray);

            
            Assert::AreEqual(1, indexArray[0]); 
            Assert::AreEqual(2, indexArray[1]); 
            Assert::AreEqual(0, indexArray[2]); 
        }

        TEST_METHOD(TestBinarySearch)
        {
            Student students[3] = {
                {"Ivanenko", 2, COMPUTER_SCIENCE, 4, 5, 3},
                {"Petrenko", 3, MATHEMATICS, 3, 4, 5},
                {"Shevchenko", 1, PHYSICS, 5, 3, 5}
            };

            int indexArray[3];
            IndexSortStudents(students, 3, indexArray);

            
            int foundIndex = BinarySearch(students, indexArray, 3, "Petrenko", 3, 5);
            Assert::AreEqual(1, foundIndex);


            int notFoundIndex = BinarySearch(students, indexArray, 3, "Kovalenko", 2, 4);
            Assert::AreEqual(-1, notFoundIndex);
        }
    };
}
