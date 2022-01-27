#include "Cell.hpp"
#include <iostream>

Cell::Cell()
{
    _mine = false;
    _discovered = false;
    _neighbours = 0;
}
Cell::~Cell()
{

}
void Cell::addMine(bool mine)
{

}
int Cell::get_neighbours()
{
    return 0;
}
void Cell::get_neighbours(std::vector<std::vector<Cell>> &grid, size_t x, size_t y)
{
    _neighbours = 0;
    if (_mine)
        return;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (x + i >= 0 && y + j >= 0 && x + i < grid.size() && y + j < grid[x + i].size())
            {
                if (grid[x + i][y + j].is_a_mine())
                    _neighbours++;
            }
        }
    }
}
bool Cell::is_discovered()
{
    return false;
}
bool Cell::is_a_mine()
{
    return true;
}
bool Cell::discover(std::vector<std::vector<Cell>> &grid, size_t x, size_t y)
{
    if (is_a_mine())
        return true;
    _discovered = true;
    if (has_neighbours())
        return false;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if ((x + i >= 0) && (y + j >= 0) && (x + i < grid.size()) && (y + j < grid[x + i].size()))
            {
                if (!grid[x + i][y + j].is_a_mine() && !grid[x + i][y + j].is_discovered())
                    grid[x + i][y + j].discover(grid, x + i, y + j);
            }
        }
    }
    return false;
}
bool Cell::has_neighbours()
{
    return false;
}
bool Cell::is_flagged()
{
    return false;
}
void Cell::flag()
{

}