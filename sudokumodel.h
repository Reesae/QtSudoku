#ifndef SUDOKUMODEL_H
#define SUDOKUMODEL_H

#include <sudokuboardnode.h>
#include "sudokusquaremodel.h"
#include <unordered_map>
#include <QObject>
class SudokuModel:public QObject
{
    Q_OBJECT
public:
    SudokuModel();
    SudokuModel(const std::vector<unsigned int> values);

    std::vector<unsigned int> getValuesFromRow(std::string key);
    std::vector<unsigned int> getValuesFromColumn(std::string key);
    std::vector<unsigned int> getValuesFromSquare(std::string key);
    void getUnsolvedNodes();
    void sortUnsolvedNodes();
    bool solveNode(std::string key);
    void solvePuzzle();
    void check();

    std::unordered_map<std::string,SudokuBoardNode*> sudokuBoard;
private:
    std::vector<std::string> unsolvedNodes;
    SudokuSquareModel* squareModel;

    void checkRows();
    void checkColumns();
    void checkSquares();

    static const std::vector<std::string> rowCheckValues;
    static const std::vector<std::string> columnCheckValues;
    static const std::vector<std::string> squareCheckValues;
    static const std::vector<unsigned int> correctValues;
};


#endif // SUDOKUMODEL_H
