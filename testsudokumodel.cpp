#include "testsudokumodel.h"

void TestSudokuModel::returnsCorrectValuesFromRowsUsingDefaultConstructor()
{
    SudokuModel test;
    std::vector<unsigned int> testRow{0,0,0,0,0,0,0,0,0};
    QVERIFY(test.getValuesFromRow(std::string("C5")) == testRow);
}

void TestSudokuModel::returnsCorrectValuesFromColumnsUsingDefaultConstructor()
{
    SudokuModel test;
    std::vector<unsigned int> testColumn{0,0,0,0,0,0,0,0,0};
    QVERIFY(test.getValuesFromRow(std::string("D7")) == testColumn);
}

void TestSudokuModel::returnsCorrectValuesFromRowsUsingExample()
{
    SudokuModel test(example);
    std::vector<unsigned int> testRow{9,9,9,9,9,9,9,9,9};
    QVERIFY(test.getValuesFromRow(std::string("C5")) == testRow);
}

void TestSudokuModel::returnsCorrectValuesFromColumnsUsingExample()
{

    SudokuModel test(example);
    std::vector<unsigned int> testColumn{9,9,9,9,9,9,9,9,9};
    QVERIFY(test.getValuesFromColumn(std::string("D7")) == testColumn);
}
const std::vector<unsigned int> TestSudokuModel::example{6,8,4,9,5,7,9,3,1,
                                                         5,1,7,4,2,3,9,8,6,
                                                         9,9,9,9,9,9,9,9,9,
                                                         4,3,5,1,7,2,9,9,8,
                                                         1,7,8,5,6,9,9,2,3,
                                                         2,6,9,3,4,8,9,1,5,
                                                         8,4,1,2,9,5,9,6,7,
                                                         3,5,2,7,1,6,9,4,9,
                                                         7,9,6,8,3,4,9,5,2
                                                         };



const std::vector<unsigned int> TestSudokuModel::solvedPuzzle{6,8,4,9,5,7,2,3,1,
                                                              5,1,7,4,2,3,9,8,6,
                                                              9,2,3,6,8,1,5,7,4,
                                                              4,3,5,1,7,2,6,9,8,
                                                              1,7,8,5,6,9,4,2,3,
                                                              2,6,9,3,4,8,7,1,5,
                                                              8,4,1,2,9,5,3,6,7,
                                                              3,5,2,7,1,6,8,4,9,
                                                              7,9,6,8,3,4,1,5,2
                                                             };
