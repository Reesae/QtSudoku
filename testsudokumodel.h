#include <QtTest/QTest>
#include "sudokumodel.h"

class TestSudokuModel : public QObject
{
    Q_OBJECT
public:
    static const std::vector<unsigned int> solvedPuzzle;
    static const std::vector<unsigned int> notsolvedPuzzle;
    static const std::vector<unsigned int> notsolvedPuzzle2;
    static const std::vector<unsigned int> example;
private slots:
  void returnsCorrectValuesFromRowsUsingDefaultConstructor();
  void returnsCorrectValuesFromColumnsUsingDefaultConstructor();
  void returnsCorrectValuesFromRowsUsingExample();
  void returnsCorrectValuesFromColumnsUsingExample();
  void findsCorrectValuesOfNode();
  void findsCorrectValuesOfPuzzle();
};



