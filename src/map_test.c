/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"

int map_test(char *buffer)
{
	int i;

	if (buffer == NULL || buffer[0] == '\0' || buffer[0] == '\n')
		return (84);
	for (i = 0; buffer[i] != '\n'; i++);
	for (; buffer[i] != '\0'; i++)
		if (buffer[i] != '.' && buffer[i] != 'o' && buffer[i] != '\n')
			return (84);
	return (0);
}
