#include <QtTest/QTest>
#include "sudokumodel.h"

class TestSudokuModel : public QObject
{
    Q_OBJECT
public:
    static const std::vector<unsigned int> solvedPuzzle;
    static const std::vector<unsigned int> example;
private slots:
  void returnsCorrectValuesFromRowsUsingDefaultConstructor();
  void returnsCorrectValuesFromColumnsUsingDefaultConstructor();
  void returnsCorrectValuesFromRowsUsingExample();
  void returnsCorrectValuesFromColumnsUsingExample();
};



