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
private:
    SudokuModel * model;
public slots:
    void keyPressedEvent(QKeyEvent *);
};

#endif // SUDOKUVIEW_H
