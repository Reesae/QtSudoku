#include "testsudokusquaremodel.h"

void TestSudokuSquareModel::squaresVectorHoldsPointersToStaticConstMembers()
{
    SudokuSquareModel test;

    QVERIFY(*test.squares.at(0) == test.squareA && *test.squares.at(8) == test.squareI);
}
