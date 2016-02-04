#include "qtsudoku.h"
#include "ui_qtsudoku.h"
#include <time.h>
#include <QDebug>

#include <QVBoxLayout>
QtSudoku::QtSudoku(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QtSudoku)
{
    ui->setupUi(this);
    QVBoxLayout *mainLayout =new QVBoxLayout;
    this->setLayout(mainLayout);
    scene = new QGraphicsScene;

    QBrush *brush = new QBrush();
    brush->setStyle(Qt::Dense1Pattern);
    brush->setColor(QColor(225,227,170));
    scene->setBackgroundBrush(*brush);

    view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(850,650);
    view->setSceneRect(0,0,850,650);
    mainLayout->addWidget(view);
    view->show();

    sudokuModel = new SudokuModel(example);
    sudokuView = new SudokuView(sudokuModel);
    for(auto node: sudokuView->boardView)
    {
        scene->addItem(node.second);
        scene->addItem(node.second->text);
    }
    connect(this,&QtSudoku::keyPressEvent,sudokuView,&SudokuView::keyPressedEvent);

    clock_t start = clock();
    sudokuModel->solvePuzzle();
    double duration = (clock()-start)/CLOCKS_PER_SEC;


    qDebug()<<duration;
}

QtSudoku::~QtSudoku()
{
    delete ui;
}


const std::vector<unsigned int> QtSudoku::example{0,8,4,0,5,0,0,3,1,
                                                  5,0,7,4,2,3,9,0,6,
                                                  9,2,0,6,0,1,5,7,4,
                                                  0,3,5,1,7,0,0,9,8,
                                                  1,0,8,0,6,9,0,2,3,
                                                  2,6,9,0,4,8,7,1,0,
                                                  8,4,1,2,9,5,0,6,7,
                                                  3,5,2,7,1,6,0,4,9,
                                                  0,0,6,8,0,4,1,5,0
                                                  };
