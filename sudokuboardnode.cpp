#include "sudokuboardnode.h"

SudokuBoardNode::SudokuBoardNode(unsigned int value):currentValue(value)
{
    if(!value || value > size * size)
    {
        currentValue = 0;
        for(unsigned int i = 1; i < size * size + 1; i++)
            possibleValues.push_back(i);
    }
}

