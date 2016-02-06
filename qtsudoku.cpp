#include "qtsudoku.h"
#include "ui_qtsudoku.h"
#include <time.h>
#include <QDebug>

#include <QVBoxLayout>
QtSudoku::QtSudoku(QWidget *parent) : QDialog(parent),ui(new Ui::QtSudoku)
{
    ui->setupUi(this);
    setupLayout();
    setupModelAndView();
    setupButtons();
}

QtSudoku::~QtSudoku()
{
    delete ui;
}

void QtSudoku::setupLayout()
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
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
}

void QtSudoku::setupModelAndView()
{

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
}

void QtSudoku::setupButtons()
{

    solve = new Button(this);
    check = new Button(this);

    scene->addItem(solve);
    scene->addItem(solve->text);
    scene->addItem(check);
    scene->addItem(check->text);

    solve->setPos(700,200);
    solve->text->setPlainText(QString("Solve"));
    solve->text->setPos(720,210);
    check->setPos(700,350);
    check->text->setPlainText(QString("Check"));
    check->text->setPos(720,360);

    connect(solve,&Button::clicked,sudokuModel,&SudokuModel::solvePuzzle);
    connect(check,&Button::clicked,sudokuModel,&SudokuModel::check);
}


const std::vector<unsigned int> QtSudoku::example{6,0,4,9,5,7,0,0,1,
                                                  5,0,7,4,2,3,0,8,0,
                                                  0,2,0,6,8,1,5,7,4,
                                                  4,3,5,1,7,0,6,9,8,
                                                  1,0,8,5,6,9,4,2,3,
                                                  0,6,9,0,4,8,0,1,5,
                                                  8,4,1,2,9,0,3,6,7,
                                                  3,0,2,7,1,6,0,4,9,
                                                  7,9,6,0,3,4,0,5,0
                                                  };
const std::vector<unsigned int> QtSudoku::example2{9,0,0,7,0,4,0,0,6,
                                                  0,4,0,0,2,0,0,8,0,
                                                  0,0,0,5,0,8,0,0,0,
                                                  0,2,6,0,0,0,0,3,0,
                                                  3,0,4,0,6,0,5,0,7,
                                                  0,7,0,0,0,0,0,6,0,
                                                  0,0,0,9,0,5,0,0,0,
                                                  0,1,0,0,4,0,0,7,0,
                                                  6,0,0,2,0,7,0,0,4
                                                  };
