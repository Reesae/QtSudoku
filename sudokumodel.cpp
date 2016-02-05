#include "sudokumodel.h"
#include <typeinfo>
#include <QDebug>
SudokuModel::SudokuModel():squareModel()
{
    unsigned int s = SudokuBoardNode::size;
    std::string key = "A0";

    for(unsigned int i = 0; i < s*s*s*s;i++)
    {
        if(key[1] != '9' )
        {
            key[1]+=1;
        }
        else
        {
            key[0]+=1;
            key[1] = '1';
        }
        sudokuBoard.emplace(key,new SudokuBoardNode(0));
    }

}

SudokuModel::SudokuModel(std::vector<unsigned int> values)
{
    unsigned int s = SudokuBoardNode::size;
    std::string key = "A0";

    for(unsigned int i = 0; i < s*s*s*s;i++)
    {
        if(key[1] != '9' )
        {
            key[1]+=1;
        }
        else
        {
            key[0]+=1;
            key[1] = '1';
        }
        sudokuBoard.emplace(key,new SudokuBoardNode(values[i]));
    }
}

std::vector<unsigned int> SudokuModel::getValuesFromRow(std::string key)
{
    char row = key[0];
    std::vector<unsigned int> values;

    for_each(sudokuBoard.cbegin(),sudokuBoard.cend(),[row,&values](const std::pair<std::string, SudokuBoardNode*>& p){

        if(p.first[0] == row)
            values.push_back(p.second->currentValue);}
    );
    return values;

}

std::vector<unsigned int> SudokuModel::getValuesFromColumn(std::string key)
{
    char row = key[1];
    std::vector<unsigned int> values;

    for_each(sudokuBoard.cbegin(),sudokuBoard.cend(),[row,&values](const std::pair<std::string, SudokuBoardNode*>& p){

        if(p.first[1] == row)
            values.push_back(p.second->currentValue);}
    );
    return values;

}

std::vector<unsigned int> SudokuModel::getValuesFromSquare(std::string key)
{
    std::vector<unsigned int> values;

    for(auto vec: squareModel.squares)
    {
        auto itr = find(vec->cbegin(),vec->cend(),key);
        if(itr != vec->cend())
        {
            for(auto x: *vec)
            {
               auto itr = sudokuBoard.find(x);
               if(itr != sudokuBoard.cend())
                  values.push_back((*itr).second->currentValue);
            }

        }
    }
    return values;

}

void SudokuModel::getUnsolvedNode()
{

    for(auto it: sudokuBoard)
    {
        if(it.second->currentValue == 0)
            unsolvedNodes.push_back(it.first);
    }
}

bool SudokuModel::solveNode(std::string key)
{

    std::vector<unsigned int> usedValues;
    std::vector<unsigned int> rowValues = getValuesFromRow(key);
    std::vector<unsigned int> columnValues = getValuesFromColumn(key);
    std::vector<unsigned int> squareValues = getValuesFromSquare(key);

    usedValues.insert(usedValues.end(),rowValues.begin(),rowValues.end());
    usedValues.insert(usedValues.end(),columnValues.begin(),columnValues.end());
    usedValues.insert(usedValues.end(),squareValues.begin(),squareValues.end());

    std::sort(usedValues.begin(), usedValues.end());
    auto last = std::unique(usedValues.begin(), usedValues.end());
    usedValues.erase(last, usedValues.end());

    auto node = sudokuBoard.at(key);
    for(auto itr = usedValues.begin();itr != usedValues.end();itr++)
    {
        auto it = find(node->possibleValue.begin(),node->possibleValue.end(),*itr);
        if(it != node->possibleValue.end())
            node->possibleValue.erase(it);


    }

    if(node->possibleValue.size() == 1)
    {
        sudokuBoard[key]->currentValue = node->possibleValue[0];
        emit sudokuBoard[key]->valueChanged();
        return true;
    }

    return false;
}

void SudokuModel::solvePuzzle()
{
    getUnsolvedNode();
    while(unsolvedNodes.size())
    {
        for(auto it = unsolvedNodes.begin(); it != unsolvedNodes.end();)
        {
            if(solveNode(*it))
                unsolvedNodes.erase(it);
        }

    }

}

void SudokuModel::check()
{
    try{
    checkRows();
    checkColumns();
    checkSquares();
    }catch(std::string s)
    {
        qDebug()<<QString(s.c_str());
    }
}

void SudokuModel::checkRows()
{
    for_each(rowCheckValues.begin(),rowCheckValues.end(),[this](std::string key){

        std::vector<unsigned int> values = getValuesFromRow(key);

        std::sort(values.begin(),values.end());
        auto last = std::unique(values.begin(), values.end());
        values.erase(last, values.end());

        for(size_t i = 0; i < values.size();i++)
        {
            if(values[i] != correctValues[i])
                throw key;
        }

    });

}

void SudokuModel::checkColumns()
{
    for_each(rowCheckValues.begin(),rowCheckValues.end(),[this](std::string key){

        std::vector<unsigned int> values = getValuesFromColumn(key);

        std::sort(values.begin(),values.end());
        auto last = std::unique(values.begin(), values.end());
        values.erase(last, values.end());

        for(size_t i = 0;i < values.size();i++)
        {
            if(values[i] != correctValues[i])
                throw key;
        }

    });
}

void SudokuModel::checkSquares()
{
    for_each(squareCheckValues.begin(),squareCheckValues.end(),[this](std::string key){

        std::vector<unsigned int> values = getValuesFromSquare(key);

        std::sort(values.begin(),values.end());
        auto last = std::unique(values.begin(), values.end());
        values.erase(last, values.end());

        for(size_t i = 0;i < values.size();i++)
        {
            if(values[i] != correctValues[i])
                throw key;
        }

    });
}

const std::vector<std::string> SudokuModel::rowCheckValues{"A1","B1","C1","D1","E1","F1","G1","H1","I1"};
const std::vector<std::string> SudokuModel::columnCheckValues{"A1","A1","A3","A4","A5","A6","A7","A8","A9"};
const std::vector<std::string> SudokuModel::squareCheckValues{"B2","B5","B7","E2","E5","E7","H2","H5","H7"};
const std::vector<unsigned int> SudokuModel::correctValues{1,2,3,4,5,6,7,8,9};




