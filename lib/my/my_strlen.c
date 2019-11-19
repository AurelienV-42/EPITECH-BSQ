/*
** EPITECH PROJECT, 2017
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
** File description:
** Library : my_strlen
*/

#include "my.h"

int my_strlen(char const *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++);
	return (i);
}