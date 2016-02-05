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

void SudokuView::updateView()
{
    for(auto node:boardView)
        node.second->updateText();
}

void SudokuView::keyPressedEvent(QKeyEvent *event)
{

    if(event->key() < Qt::Key_A && event->key() > Qt::Key_0)
        {
             activeNode->text->setPlainText(event->text());
             activeNode->node->currentValue = event->text().toUInt();
        }
    else if (event->key() == Qt::Key_0)
         {
            activeNode->text->setPlainText("");
            activeNode->node->currentValue = event->text().toUInt();
         }

    activeNode->updateText();
    activeNode->isActive = false;

}

void SudokuView::nodeSelected()
{
    if(activeNode != nullptr)
        activeNode->isActive = false;

    for(auto node:boardView)
    {
        if(node.second->isActive){
            activeNode = node.second;
            break;
        }
    }
}
