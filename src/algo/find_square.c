/*
** EPITECH PROJECT, 2022
** CPE_BSQ_2017
** File description:
** Created by Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include <stdlib.h>
#include "my.h"

static void find_biggest(int **array_nb, char **array)
{
	int max = 0;
	int columns = 0;
	int lines = 0;

	for (int i = 0; array[i] != NULL; i++)
		for (int nb = 0; array[i][nb] != '\0'; nb++)
			if (max < array_nb[i][nb]) {
				max = array_nb[i][nb];
				lines = i;
				columns = nb;
			}
	for (int i = lines; i != (lines - max); i--)
		for (int nb = columns; nb != (columns - max); nb--)
			array[i][nb] = 'x';
}

int find_square(char **array)
{
	int **array_nb = malloc_nb(array);

	if (array_nb == NULL)
		return (84);
	my_algo(array, array_nb);
	find_biggest(array_nb, array);
	for (int i = 0; array_nb[i] != NULL; i++)
		free(array_nb[i]);
	free(array_nb);
	return (0);
}