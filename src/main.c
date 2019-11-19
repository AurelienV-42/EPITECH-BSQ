/*
** EPITECH PROJECT, 2017
** BSQ main
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"

int main(int ac, char **av)
{
	if (ac != 2)
		return (84);
	return (bsq(av[1]));
}
