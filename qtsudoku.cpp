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
        connect(node.second->node,&SudokuBoardNode::valueChanged,node.second,&NodeView::onValueChanged);



    for(auto node: sudokuView->boardView)
    {
        scene->addItem(node.second);
        scene->addItem(node.second->text);
        connect(node.second,&NodeView::nodeSelect,sudokuView,&SudokuView::nodeSelected);
    }
    connect(this,&QtSudoku::keyPressEvent,sudokuView,&SudokuView::keyPressedEvent);

    solve = new Button(this);
    check = new Button(this);

    scene->addItem(solve);
    scene->addItem(check);

    solve->setPos(700,200);
    check->setPos(700,350);


    connect(solve,&Button::clicked,sudokuModel,&SudokuModel::solvePuzzle);
    connect(check,&Button::clicked,sudokuModel,&SudokuModel::check);




}

QtSudoku::~QtSudoku()
{
    delete ui;
}


const std::vector<unsigned int> QtSudoku::example{6,8,4,9,5,7,0,3,1,
                                                  5,0,7,4,2,3,0,8,6,
                                                  9,2,0,6,8,1,5,7,4,
                                                  4,3,5,1,7,0,6,9,8,
                                                  1,0,8,5,6,9,4,2,3,
                                                  2,6,9,0,4,8,0,1,5,
                                                  8,4,1,2,9,5,3,6,7,
                                                  3,0,2,7,1,6,0,4,9,
                                                  7,9,6,0,3,4,1,5,0
                                                  };
