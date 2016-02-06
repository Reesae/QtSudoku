#include "testsudokuboardnode.h"

void TestSudokuBoardNode::createsWithAssaignedValue()
{
    SudokuBoardNode test(3);
    QVERIFY(test.currentValue == 3);
}

void TestSudokuBoardNode::vectorOfpossibleValuessIsEmptyOnValueAssaigned()
{
    SudokuBoardNode test(3);
    QVERIFY(test.possibleValues.empty());
}

void TestSudokuBoardNode::setsCurrentValueToZeroOnInvalidNumberPassed()
{
    SudokuBoardNode test1(-1);
    SudokuBoardNode test2(19);
    QVERIFY(!(test1.currentValue && test2.currentValue));

}

void TestSudokuBoardNode::vectorsOfpossibleValuessSizeIsProportionalToSizeOfGrid()
{
     SudokuBoardNode test1(0);
     QVERIFY((test1.size * test1.size) == test1.possibleValues.size());
}
