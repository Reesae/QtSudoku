#include "sudokuboardnode.h"

SudokuBoardNode::SudokuBoardNode(unsigned int value):currentValue(value)
{

    if(!value || value > 9)
    {
        currentValue = 0;
        for(unsigned int i = 1; i < size * size + 1; i++)
        possibleValue.push_back(i);
    }

}

