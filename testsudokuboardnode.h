#include <QtTest/QTest>
#include "sudokuboardnode.h"

class TestSudokuBoardNode : public QObject
{
    Q_OBJECT

private slots:
    void createsWithAssaignedValue();
    void vectorOfPossibleValuesIsEmptyOnValueAssaigned();
    void setsCurrentValueToZeroOnInvalidNumberPassed();
    void vectorsOfPossibleValuesSizeIsProportionalToSizeOfGrid();
};





