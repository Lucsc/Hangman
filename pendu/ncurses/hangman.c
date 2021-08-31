/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** hangman
*/

#include "hangman.h"

void print_hangman_bis(hangman_t *hangman)
{
    if (hangman->check_letter >= 6)
        mvaddch(LINES - 9, COLS / 2 - 5 - 4, '-');
    if (hangman->check_letter >= 7)
        mvaddch(LINES - 8, COLS / 2 - 5 - 5, '|');
    if (hangman->check_letter >= 8)
        mvaddch(LINES - 7, COLS / 2 - 5 - 5, 'o');
    if (hangman->check_letter >= 9) {
        mvaddch(LINES - 6, COLS / 2 - 5 - 6, '/');
        mvaddch(LINES - 6, COLS / 2 - 5 - 5, '|');
        mvaddch(LINES - 6, COLS / 2 - 5 - 4, '\\');
    }
    if (hangman->check_letter >= 10) {
        mvaddch(LINES - 5, COLS / 2 - 5 - 6, '/');
        mvaddch(LINES - 5, COLS / 2 - 5 - 4, '\\');
    }
}

void print_hangman(hangman_t *hangman)
{
    if (hangman->check_letter >= 1)
        mvaddch(LINES - 5, COLS / 2 - 5, '|');
    if (hangman->check_letter >= 2)
        mvaddch(LINES - 6, COLS / 2 - 5, '|');
    if (hangman->check_letter >= 3)
        mvaddch(LINES - 7, COLS / 2 - 5, '|');
    if (hangman->check_letter >= 4)
        mvaddch(LINES - 8, COLS / 2 - 5, '|');
    if (hangman->check_letter >= 5)
        mvaddch(LINES - 9, COLS / 2 - 5 - 2, '-');
    print_hangman_bis(hangman);
}