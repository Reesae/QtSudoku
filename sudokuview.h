#ifndef SUDOKUVIEW_H
#define SUDOKUVIEW_H
#include "sudokumodel.h"
#include "nodeview.h"

class SudokuView: public QObject
{
   Q_OBJECT

public:
    SudokuView(SudokuModel * model);
    std::unordered_map<std::string,NodeView*> boardView;
    void updateView();
private:
    SudokuModel * model;
    NodeView * activeNode;

public slots:
    void keyPressedEvent(QKeyEvent *);
    void nodeSelected();
};

#endif // SUDOKUVIEW_H
