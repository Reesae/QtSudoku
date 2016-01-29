#ifndef SUDOKUBOARDNODE_H
#define SUDOKUBOARDNODE_H

#include <vector>

class SudokuBoardNode
{
public:
    SudokuBoardNode(unsigned int value);
    unsigned int currentValue;
    std::vector <unsigned int> possibleValue;
    static const unsigned int size = 3;
};

#endif // SUDOKUBOARDNODE_H
