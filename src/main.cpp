#include <iostream>
#include <ncurses.h>
#include "Game.hpp"

#define ENTER 10

void ncurses_initialiser()
{
    initscr();            /* Demarre le mode ncurses */
    cbreak();             /* Pour les saisies clavier (desac. mise en buffer) */
    noecho();             /* Desactive l'affichage des caracteres saisis */
    keypad(stdscr, TRUE); /* Active les touches specifiques */
    refresh();            /* Met a jour l'affichage */
    curs_set(TRUE);       /* Masque le curseur */
}

int main(int argc, char const *argv[])
{
    int key;
    ncurses_initialiser();
    Game game = Game(10, 10);
    game.begin(10);
    int x = 0;
    int y = 0;
    move(0, 1);
    do
    {
        key = getch();
        switch (key)
        {
        case KEY_UP:
            x -= 1;
            x = x < 0 ? 0 : x;
            break;
        case KEY_DOWN:
            x += 1;
            x = x >= game.get_width() ? game.get_width() - 1 : x;
            break;
        case KEY_LEFT:
            y -= 1;
            y = y < 0 ? 0 : y;
            break;
        case KEY_RIGHT:
            y += 1;
            y = y >= game.get_height() ? game.get_height() - 1 : y;
            break;
        case 'F':
        case 'f':
            game.add_flag(x, y);
            game.draw();
            break;
        default:
            break;
        }
        if (key == ENTER || key == KEY_ENTER)
        {
            game.discover(x, y);
            game.draw();
        }
        else
        {
            move(x, y * 2 + 1);
        }
        refresh();
    } while (!game.has_lost() && !game.has_won());
    printw("\n");
    if (game.has_lost())
        printw("Oh non!\n");
    else if (game.has_won())
        printw("Cool t'as gagné!\n");
    refresh();
    std::cin.get();
    endwin();
    return 0;
}