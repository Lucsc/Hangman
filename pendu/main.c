/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** main
*/

#include "hangman.h"

void chose_game(char *ncurses, char *csfml, int chose, char *play)
{
    wattron(stdscr, COLOR_PAIR(1));
    box(stdscr, 0, 0);
    wattroff(stdscr, COLOR_PAIR(1));
    attron(A_BOLD | A_UNDERLINE);
    mvprintw(LINES / 2 - 5, COLS / 2 - 10, play);
    attroff(A_BOLD | A_UNDERLINE);
    if (chose == 0) {
        attron(A_BOLD | A_UNDERLINE);
        mvprintw(LINES / 2, COLS / 2 - 20, ncurses);
        attroff(A_BOLD | A_UNDERLINE);
        mvprintw(LINES / 2, COLS / 2 + 10, csfml);
    } else {
        mvprintw(LINES / 2, COLS / 2 - 20, ncurses);
        attron(A_BOLD | A_UNDERLINE);
        mvprintw(LINES / 2, COLS / 2 + 10, csfml);
        attroff(A_BOLD | A_UNDERLINE);
    }
}

void ask_game(char *word, hangman_t *hangman)
{
    int key = -1;
    int chose = 0;
    char *play = "Chose how to play :";

    noecho();
    keypad(stdscr, TRUE);
    init_pair(1, COLOR_WHITE, COLOR_WHITE);
    while (key != '\n') {
        chose_game("ncurses", "csfml", chose, play);
        key = getch();
        if (key == KEY_LEFT || key == KEY_RIGHT) {
            chose++;
            if (chose > 1)
                chose = 0;
        }
    }
    if (chose == 0)
        launch_game(word, hangman);
    else
        return;
}

int main(int ac, char **av)
{
    hangman_t hangman;

    if (ac != 2) {
        printf("Usage :\n./hangman 'Your word'\n");
        return 84;
    }
    initscr();
    ask_game(av[1], &hangman);
    endwin();
}