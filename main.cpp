#include "qtsudoku.h"
#include <QApplication>
#include "testsudokuboardnode.h"


int main(int argc, char *argv[])
{
    TestSudokuBoardNode test1;
    QTest::qExec(&test1, argc, argv);

    QApplication a(argc, argv);
    QtSudoku w;
    w.show();

    return a.exec();
}
