#ifndef SUDOKUMODEL_H
#define SUDOKUMODEL_H

#include <sudokuboardnode.h>
#include <unordered_map>

class SudokuModel
{
public:
    SudokuModel();
    std::unordered_map<std::string,SudokuBoardNode> sudokuBoard;




};

#endif // SUDOKUMODEL_H
