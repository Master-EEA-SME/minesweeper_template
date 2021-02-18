#include "Cell.h"
#include <iostream>

Cell::Cell()
{
    _Mine = false;
    _Discovered = false;
    _Neighbours = 0;
}
Cell::~Cell()
{

}
void Cell::addMine(bool mine)
{

}
int Cell::getNeighbours()
{
    return 0;
}
void Cell::getNeighbours(std::vector<std::vector<Cell>> &grid, int x, int y)
{
    _Neighbours = 0;
    if (_Mine)
        return;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (x + i >= 0 && y + j >= 0 && x + i < grid.size() && y + j < grid[x + i].size())
            {
                if (grid[x + i][y + j].isAMine())
                    _Neighbours++;
            }
        }
    }
}
bool Cell::isDiscovered()
{
    return false;
}
bool Cell::isAMine()
{
    return true;
}
bool Cell::discover(std::vector<std::vector<Cell>> &grid, int x, int y)
{
    if (isAMine())
        return true;
    _Discovered = true;
    if (hasNeighbours())
        return false;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if ((x + i >= 0) && (y + j >= 0) && (x + i < grid.size()) && (y + j < grid[x + i].size()))
            {
                if (!grid[x + i][y + j].isAMine() && !grid[x + i][y + j].isDiscovered())
                    grid[x + i][y + j].discover(grid, x + i, y + j);
            }
        }
    }
    return false;
}
bool Cell::hasNeighbours()
{
    return false;
}
bool Cell::isFlagged()
{
    return false;
}
void Cell::flag()
{

}