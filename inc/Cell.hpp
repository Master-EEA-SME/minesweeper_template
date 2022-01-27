#ifndef CELL_H_
#define CELL_H_
#include <vector>

class Cell
{
public:
    
private:
    bool _mine;
    bool _discovered;
    int _neighbours;
    bool _flag;
public:
    Cell();
    ~Cell();
    void addMine(bool mine);
    int get_neighbours();
    void get_neighbours(std::vector<std::vector<Cell>> &grid, size_t x, size_t y);
    bool has_neighbours();
    bool discover(std::vector<std::vector<Cell>> &grid, size_t x, size_t y);
    bool is_discovered();
    bool is_a_mine();
    bool is_flagged();
    void flag();
    void unflag();
};


#endif // CELL_H_