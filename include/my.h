/*
** EPITECH PROJECT, 2017
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
** File description:
** Library
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#ifndef MY_H_
#define MY_H_

int bsq(char const *);
int find_square(char **);
int get_lines(char const *);
int get_columns(char const *);
void my_algo(char **, int **);
int **malloc_nb(char **);
int map_test(char *);

#endif
