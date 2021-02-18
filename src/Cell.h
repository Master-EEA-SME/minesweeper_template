#ifndef CELL_H_
#define CELL_H_
#include <vector>

class Cell
{
public:
    
private:
    bool _Mine;
    bool _Discovered;
    int _Neighbours;
    bool _Flag;
public:
    Cell();
    ~Cell();
    void addMine(bool mine);
    int getNeighbours();
    void getNeighbours(std::vector<std::vector<Cell>> &grid, int x, int y);
    bool hasNeighbours();
    bool discover(std::vector<std::vector<Cell>> &grid, int x, int y);
    bool isDiscovered();
    bool isAMine();
    bool isFlagged();
    void flag();
};


#endif // CELL_H_