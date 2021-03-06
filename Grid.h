#ifndef GRID_H
#define GRID_H

#include <vector>
#include <iostream>

#include "Cell.h"

class Grid
{
public:
  enum CellsSetType {
    Line,
    Column,
    Block
  };

  Grid(void);
  virtual ~Grid(void);

  inline Cell* getCell(int i, int j) const { return _cells.at(i).at(j); }

  std::vector<Cell*> getLineFromCell(Cell* cell) const;
  std::vector<Cell*> getLineFromCellCoordinate(int i) const;
  std::vector<Cell*> getColumnFromCell(Cell* cell) const;
  std::vector<Cell*> getColumnFromCellCoordinate(int j) const;
  std::vector<Cell*> getCaseFromCell(Cell* cell) const;
  std::vector<Cell*> getCaseFromCellCoordinate(int i, int j) const;

  void fillCell(int i, int j, int value);
  void fillCell(Cell* cell, int value);
  bool fillCells(void);

  bool fillOnlyChoice(int i, int j, int value, CellsSetType cellsSetType);
  bool fillOnlyChoices(void);

  friend std::ostream& operator<<(std::ostream& os, const Grid& grid);

private:
  void getCellCoordinates(Cell* cell, int& i, int& j) const;

private:
  std::vector<std::vector<Cell*>> _cells;
};

#endif // GRID_H
