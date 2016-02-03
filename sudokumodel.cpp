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
        sudokuBoard.emplace(key,0);
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
        sudokuBoard.emplace(key,SudokuBoardNode(values[i]));
    }
}

std::vector<unsigned int> SudokuModel::getValuesFromRow(std::string key)
{
    char row = key[0];
    std::vector<unsigned int> values;

    for_each(sudokuBoard.cbegin(),sudokuBoard.cend(),[row,&values](const std::pair<std::string, SudokuBoardNode>& p){

        if(p.first[0] == row)
            values.push_back(p.second.currentValue);}
    );
    return values;

}

std::vector<unsigned int> SudokuModel::getValuesFromColumn(std::string key)
{
    char row = key[1];
    std::vector<unsigned int> values;

    for_each(sudokuBoard.cbegin(),sudokuBoard.cend(),[row,&values](const std::pair<std::string, SudokuBoardNode>& p){

        if(p.first[1] == row)
            values.push_back(p.second.currentValue);}
    );
    return values;

}

std::vector<unsigned int> SudokuModel::getValuesFromSquare(std::string key)
{
    std::vector<unsigned int> values;

    for(auto vec: squareModel.squares)
    {
        auto it = find(vec->cbegin(),vec->cend(),key);
        if(it != vec->cend())
        {
            for(auto x: *vec)
            {
               auto it = sudokuBoard.find(x);
               if(it != sudokuBoard.cend())
                  values.push_back((*it).second.currentValue);
            }

        }


    }
    return values;

}




