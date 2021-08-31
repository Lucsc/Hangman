/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** pendu
*/

#ifndef HANGMAN_H_
#define HANGMAN_H_

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ncurses.h>
#include <signal.h>
#include <string.h>

typedef struct hangman_s {
    char *word;
    int check_letter;
    char *lose;
    int letter;
} hangman_t;

void print_hangman(hangman_t *hangman);
int launch_game(char *word, hangman_t *hangman);

#endif /* !HANGMAN_H_ */