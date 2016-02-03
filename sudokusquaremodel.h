#ifndef SUDOKUSQUAREMODEL_H
#define SUDOKUSQUAREMODEL_H
#include <vector>
#include <string>


class SudokuSquareModel
{
public:
    SudokuSquareModel();

    std::vector<const std::vector<std::string>*> squares;
    static const std::vector<std::string> squareA;
    static const std::vector<std::string> squareB;
    static const std::vector<std::string> squareC;
    static const std::vector<std::string> squareD;
    static const std::vector<std::string> squareE;
    static const std::vector<std::string> squareF;
    static const std::vector<std::string> squareG;
    static const std::vector<std::string> squareH;
    static const std::vector<std::string> squareI;

};

#endif // SUDOKUSQUAREMODEL_H
