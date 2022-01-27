#include "Game.hpp"
#include <ctime>
#include <cstdlib>
#include <ncurses.h>
Game::Game(size_t width, size_t height)
{
    _number_of_mines = 0;
    _number_of_flags = 0;
    _width = width;
    _height = height;
    _Grid.reserve(_width);
    for (size_t i = 0; i < _width; i++)
    {
        _Grid[i].reserve(_height);
        _Grid.push_back(std::vector<Cell>());
        for (size_t j = 0; j < _height; j++)
        {
            _Grid[i].push_back(Cell());
        }
    }
}
Game::~Game()
{

}
void Game::begin(size_t mines)
{
    std::srand(std::time(NULL));
    do
    {
        for (size_t i = 0; i < _Grid.size(); i++)
        {
            for (size_t j = 0; j < _Grid[i].size(); j++)
            {
                bool mine = !(std::rand() % 2) ? true : false;
                if (mine)
                {
                    _Grid[i][j].addMine(mine);
                    _number_of_mines++;
                    if (_number_of_mines >= mines)
                        break;
                }
            }
            if (_number_of_mines >= mines)
                break;
        }
    } 
    while (_number_of_mines < mines);
    for (size_t i = 0; i < _Grid.size(); i++)
        for (size_t j = 0; j < _Grid[i].size(); j++)
            _Grid[i][j].get_neighbours(_Grid, i, j);
    _number_of_flags = _number_of_mines;
    draw();
}
void Game::discover(size_t x, size_t y)
{
    size_t discovered = 0;
    if (x >= 0 && x < _Grid.size() && y >= 0 && y < _Grid[x].size())
    {
        _Grid[x][y].discover(_Grid, x, y);
        for (size_t i = 0; i < _Grid.size(); i++)
        {
            for (size_t j = 0; j < _Grid[x].size(); j++)
            {
                if (_Grid[i][j].is_discovered())
                {
                    discovered++;
                    if (_Grid[i][j].is_flagged())
                    {
                        _number_of_flags++;
                        _Grid[i][j].flag();
                    }
                }
            }
        }
    }
}
void Game::draw()
{
    move(0, 0);
    for (size_t i = 0; i < _Grid.size(); i++)
    {
        printw("|");
        for (size_t j = 0; j < _Grid[i].size(); j++)
        {
            char c = '#';
            if (_Grid[i][j].is_discovered())
            {
                c = _Grid[i][j].get_neighbours();
                c = c > 0 ? c + '0' : ' ';
            }
            else if (_Grid[i][j].is_flagged())
                c = 'F';
            else if ((_has_lost || _has_won) && _Grid[i][j].is_a_mine())
                c = '*';
            printw("%c|", c);
        }
        printw("\n");
    }
    printw("\n%d Mines\n\n", _number_of_flags);
    if (!_has_lost && !_has_won)
    {
        int x, y;
        getsyx(x, y);
        move(x, y);
    }
}
int Game::get_width()
{
    return 1;
}
int Game::get_height()
{
    return 1;
}
bool Game::has_lost()
{
    return false;
}
bool Game::has_won()
{
    return false;
}
void Game::add_flag(size_t x, size_t y)
{
    if (!_Grid[x][y].is_discovered())
    {
        if (_Grid[x][y].is_flagged())
        {
            _Grid[x][y].flag();
            _number_of_flags++;
        }
        else if (_number_of_flags > 0)
        {
            _Grid[x][y].flag();
            _number_of_flags--;
        }
    }
}
