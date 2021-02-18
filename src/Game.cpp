#include "Game.h"
#include <iostream>
#include <time.h>
#include <ncurses.h>
Game::Game(int x, int y)
{
    _NumberOfMines = 0;
    _UndiscoveredCells = x * y;
    _NumberOfFlags = 0;
    srand(time(NULL));
    _Grid.reserve(x);
    for (size_t i = 0; i < x; i++)
        _Grid[i].reserve(y);

    for (size_t i = 0; i < x; i++)
    {
        _Grid.push_back(std::vector<Cell>());
        for (size_t j = 0; j < y; j++)
        {
            _Grid[i].push_back(Cell());
        }
    }
    _ResX = x;
    _ResY = y;
}
Game::~Game()
{

}
void Game::begin(int mines)
{
    do
    {
        for (size_t i = 0; i < _Grid.size(); i++)
        {
            for (size_t j = 0; j < _Grid[i].size(); j++)
            {
                bool mine = !(rand() % 10) ? true : false;
                if (mine)
                {
                    _Grid[i][j].addMine(mine);
                    _NumberOfMines++;
                    if (_NumberOfMines >= mines)
                        break;
                }
            }
            if (_NumberOfMines >= mines)
                break;
        }
    } 
    while (_NumberOfMines < mines);
    for (size_t i = 0; i < _Grid.size(); i++)
        for (size_t j = 0; j < _Grid[i].size(); j++)
            _Grid[i][j].getNeighbours(_Grid, i, j);
    _NumberOfFlags = _NumberOfMines;
    printGrid();
}
void Game::discover(int x, int y)
{
    int discovered = 0;
    if (x >= 0 && x < _Grid.size() && y >= 0 && y < _Grid[x].size())
    {
        _Grid[x][y].discover(_Grid, x, y);
        for (size_t i = 0; i < _Grid.size(); i++)
        {
            for (size_t j = 0; j < _Grid[x].size(); j++)
            {
                if (_Grid[i][j].isDiscovered())
                {
                    discovered++;
                    if (_Grid[i][j].isFlagged())
                    {
                        _NumberOfFlags++;
                        _Grid[i][j].flag();
                    }
                }
            }
        }
    }
}
void Game::printGrid()
{
    move(0, 0);
    for (size_t i = 0; i < _Grid.size(); i++)
    {
        printw("|");
        for (size_t j = 0; j < _Grid[i].size(); j++)
        {
            char c = '#';
            if (_Grid[i][j].isDiscovered())
            {
                c = _Grid[i][j].getNeighbours();
                c = c > 0 ? c + '0' : ' ';
            }
            else if (_Grid[i][j].isFlagged())
                c = 'F';
            else if ((_hasLost || _hasWon) && _Grid[i][j].isAMine())
                c = '*';
            printw("%c|", c);
        }
        printw("\n");
    }
//    printw("\n%d Mines\n\n", _NumberOfFlags);
    if (!_hasLost && !_hasWon)
    {
        int x, y;
        getsyx(x, y);
        move(x, y);
    }
}
int Game::getX()
{
    return 1;
}
int Game::getY()
{
    return 1;
}
bool Game::hasLost()
{
    return false;
}
bool Game::hasWon()
{
    return false;
}
void Game::addFlag(int x, int y)
{
    if (!_Grid[x][y].isDiscovered())
    {
        if (_Grid[x][y].isFlagged())
        {
            _Grid[x][y].flag();
            _NumberOfFlags++;
        }
        else if (_NumberOfFlags > 0)
        {
            _Grid[x][y].flag();
            _NumberOfFlags--;
        }
    }
}
