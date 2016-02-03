#ifndef SUDOKUMODEL_H
#define SUDOKUMODEL_H

#include <sudokuboardnode.h>
#include "sudokusquaremodel.h"
#include <unordered_map>

class SudokuModel
{
public:
    SudokuModel();
    SudokuModel(const std::vector<unsigned int> values);

    std::vector<unsigned int> getValuesFromRow(std::string key);
    std::vector<unsigned int> getValuesFromColumn(std::string key);
    std::vector<unsigned int> getValuesFromSquare(std::string key);
private:
    std::unordered_map<std::string,SudokuBoardNode> sudokuBoard;
    SudokuSquareModel squareModel;
};


#endif // SUDOKUMODEL_H
