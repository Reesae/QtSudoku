#include "qtsudoku.h"
#include <QApplication>
#include "testsudokuboardnode.h"
#include "sudokumodel.h"
#include "testsudokumodel.h"
#include "testsudokusquaremodel.h"



int main(int argc, char *argv[])
{
    TestSudokuBoardNode test1;
    QTest::qExec(&test1, argc, argv);
    TestSudokuModel test2;
    QTest::qExec(&test2, argc, argv);
    TestSudokuSquareModel test3;
    QTest::qExec(&test3, argc, argv);


    QApplication a(argc, argv);
    QtSudoku w;
    w.show();


    return a.exec();
}
