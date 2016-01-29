#include "qtsudoku.h"
#include "ui_qtsudoku.h"

QtSudoku::QtSudoku(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QtSudoku)
{
    ui->setupUi(this);
}

QtSudoku::~QtSudoku()
{
    delete ui;
}
