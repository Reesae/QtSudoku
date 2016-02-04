#include "sudokuview.h"
#include <QDebug>
SudokuView::SudokuView(SudokuModel *model):model(model)
{
    std::string key = "A0";

    for(unsigned int i = 0; i < model->sudokuBoard.size();i++)
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
        boardView.emplace(key,new NodeView(model->sudokuBoard.at(key)));
        boardView.at(key)->setPosition(key);
    }


}


void SudokuView::keyPressedEvent(QKeyEvent *event)
{
    for(auto node:boardView){
    if(node.second->isActive)
    {
        if(event->key() < Qt::Key_A && event->key() > Qt::Key_0)
        {
             node.second->text->setPlainText(event->text());
        }
        else if (event->key() == Qt::Key_0)
             node.second->text->setPlainText("");

        node.second->isActive = false;
    }
    }
}
