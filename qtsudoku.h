#ifndef QTSUDOKU_H
#define QTSUDOKU_H
#include "nodeview.h"
#include "sudokuview.h"
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
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
    Ui::QtSudoku * ui;
    QGraphicsScene * scene;
    QGraphicsView * view;
    SudokuModel * sudokuModel;
    SudokuView * sudokuView;
    NodeView * activeNode;
    static const std::vector<unsigned int> example;
signals:
    void keyPressEvent(QKeyEvent*);



};

#endif // QTSUDOKU_H
