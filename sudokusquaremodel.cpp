#include "sudokusquaremodel.h"

SudokuSquareModel::SudokuSquareModel()
{
    squares.push_back(&squareA);
    squares.push_back(&squareB);
    squares.push_back(&squareC);
    squares.push_back(&squareD);
    squares.push_back(&squareE);
    squares.push_back(&squareF);
    squares.push_back(&squareG);
    squares.push_back(&squareH);
    squares.push_back(&squareI);

}

const std::vector<std::string> SudokuSquareModel::squareA{"A1","A2","A3","B1","B2","B3","C1","C2","C3"};
const std::vector<std::string> SudokuSquareModel::squareB{"A4","A5","A6","B4","B5","B6","C4","C5","C6"};
const std::vector<std::string> SudokuSquareModel::squareC{"A7","A8","A9","B7","B8","B9","C7","C8","C9"};
const std::vector<std::string> SudokuSquareModel::squareD{"D1","D2","D3","E1","E2","E3","F1","F2","F3"};
const std::vector<std::string> SudokuSquareModel::squareE{"D4","D5","D6","E4","E5","E6","F4","F5","F6"};
const std::vector<std::string> SudokuSquareModel::squareF{"D7","D8","D9","E7","E8","E9","F7","F8","F9"};
const std::vector<std::string> SudokuSquareModel::squareG{"G1","G2","G3","H1","H2","H3","I1","I2","I3"};
const std::vector<std::string> SudokuSquareModel::squareH{"G4","G5","G6","H4","H5","H6","I4","I5","I6"};
const std::vector<std::string> SudokuSquareModel::squareI{"G7","G8","G9","H7","H8","H9","I7","I8","I9"};
