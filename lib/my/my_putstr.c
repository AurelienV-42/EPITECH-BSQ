/*
** EPITECH PROJECT, 2017
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
** File description:
** Library : my_putstr
*/

#include <unistd.h>
#include "library.h"

void my_putstr(char const *str)
{
	write(1, str, my_strlen(str));
}
