/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** game
*/

#include "hangman.h"

void create_hangman(hangman_t *hangman, char *word)
{
    hangman->word = malloc(sizeof(char *)* strlen(word));
    hangman->check_letter = 0;
    hangman->lose = malloc(sizeof(char *)* 11);
    hangman->letter = 0;
}

void lost_letter(int key, hangman_t *hangman)
{
    int r = 0;

    for (int i = 0; hangman->lose[i] != '\0'; i++)
        if (key == hangman->lose[i])
            r++;
    if (r == 0) {
        hangman->check_letter++;
        hangman->lose[hangman->letter] = key;
        hangman->letter++;
    }
}

void check_letter(char *word, hangman_t *hangman, int key)
{
    int i = 0;
    int r = 0;

    for (; word[i]; i++) {
        if (key == word[i]) {
            hangman->word[i] = word[i];
            r++;
        }
    }
    if (r == 0)
        lost_letter(key, hangman);
}

void print_word(char *word, hangman_t *hangman)
{
    int r = 0;
    int j = 5;

    clear();
    for (int i = strlen(word) - 1; i >= 0; i--, r++) {
        mvaddch(LINES / 2, COLS / 2 - r, word[i]);
        r++;
        mvaddch(LINES / 2, COLS / 2 - r, ' ');
    }
    mvaddch(LINES / 2 + 1, COLS / 2, '\n');
    print_hangman(hangman);
    for (int i = 0; hangman->lose[i]; i++)
        mvaddch(LINES - 10, COLS / 2 - 5 + i, hangman->lose[i]);
    refresh();
}

int launch_game(char *word, hangman_t *hangman)
{
    create_hangman(hangman, word);
    int key = -1;

    hangman->word = strcpy(hangman->word, word);
    for (int i = 0; hangman->word[i]; i++) {
        if (hangman->word[i] != ' ')
            hangman->word[i] = '_';
    }
    while (strcmp(hangman->word, word) != 0 && hangman->check_letter < 11) {
        print_word(hangman->word, hangman);
        key = getch();
        refresh();
        check_letter(word, hangman, key);
    }
    free(hangman->word);
    return (0);
}