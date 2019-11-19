/*
** EPITECH PROJECT, 2022
** CPE_BSQ_2017
** File description:
** Created by Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include <stdlib.h>
#include "library.h"

int **malloc_nb(char **array)
{
	int **array_nb = NULL;
	int lines;
	int columns = my_strlen(array[0]);

	for (lines = 0; array[lines] != NULL; lines++);
	array_nb = malloc(sizeof(int *) * (lines + 1));
	if (array_nb == NULL)
		return (NULL);
	for (int i = 0; i != lines; i++) {
		array_nb[i] = malloc(sizeof(int) * (columns + 1));
		if (array_nb[i] == NULL)
			return (NULL);
		array_nb[i][columns] = '\0';
	}
	array_nb[lines] = NULL;
	return (array_nb);
}

void fill_first(char **array, int **array_nb)
{
	int fill = 0;

	for (int i = 0; array[i] != NULL; i++) {
		if (i == 0)
			for (int nb = 0; array[i][nb] != '\0'; nb++) {
				if (array[i][nb] == '.')
					fill = 1;
				if (array[i][nb] != '\n')
					array_nb[i][nb] = fill;
				fill = 0;
			}
		if (array[i][0] == '.')
			fill = 1;
		array_nb[i][0] = fill;
		fill = 0;
	}
}

static int the_less(int **array_nb, int lines, int cols)
{
	int less = 0;

	if (array_nb[lines][cols - 1] <= array_nb[lines - 1][cols])
		less = array_nb[lines][cols - 1];
	else
		less = array_nb[lines - 1][cols];
	if (array_nb[lines - 1][cols - 1] <= less)
		less = array_nb[lines - 1][cols - 1];
	return (less + 1);
}

void my_algo(char **array, int **array_nb)
{
	int fill = 0;
	int lines;

	fill_first(array, array_nb);
	for (lines = 1; array[lines] != NULL; lines++) {
		for (int cols = 1; array[lines][cols] != '\0'; cols++) {
			if (array[lines][cols] == '.')
				fill = 1;
			if (array[lines][cols] == '.' &&
				array[lines][cols - 1] == '.' &&
				array[lines - 1][cols] == '.' &&
				array[lines - 1][cols - 1] == '.')
				fill = the_less(array_nb, lines, cols);
			if (array[lines][cols] != '\n'
				|| array[lines][cols] != '\0')
				array_nb[lines][cols] = fill;
			fill = 0;
		}
	}
}
