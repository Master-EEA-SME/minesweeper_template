#pragma once
#include <vector>
#include "Cell.hpp"

class Game
{
private:
    std::vector<std::vector<Cell>> _Grid;
    size_t _number_of_mines;
    size_t _number_of_flags;
    bool _has_lost = false;
    bool _has_won = false;
    size_t _width;
    size_t _height;
public:
    Game(size_t width, size_t height);
    ~Game();
    void begin(size_t mines);
    void discover(size_t x, size_t y);
    void draw();
    int get_width();
    int get_height();
    bool has_lost();
    bool has_won();
    void add_flag(size_t x, size_t y);
};
