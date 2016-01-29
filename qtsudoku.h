#ifndef QTSUDOKU_H
#define QTSUDOKU_H

#include <QDialog>

namespace Ui {
class QtSudoku;
}

class QtSudoku : public QDialog
{
    Q_OBJECT

public:
    explicit QtSudoku(QWidget *parent = 0);
    ~QtSudoku();

private:
    Ui::QtSudoku *ui;
};

#endif // QTSUDOKU_H
