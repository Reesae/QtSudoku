#ifndef SUDOKUBOARDNODE_H
#define SUDOKUBOARDNODE_H
#include <QObject>
#include <vector>

class SudokuBoardNode:public QObject
{
    Q_OBJECT
public:
    SudokuBoardNode(unsigned int value);
    unsigned int currentValue;
    std::vector <unsigned int> possibleValue;
    static constexpr unsigned int size = 3;
signals:
    void valueChanged();
};

#endif // SUDOKUBOARDNODE_H
