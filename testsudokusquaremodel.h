#include <QtTest/QTest>
#include "sudokusquaremodel.h"

class TestSudokuSquareModel : public QObject
{
    Q_OBJECT

private slots:
    void squaresVectorHoldsPointersToStaticConstMembers();
};



