/*
** EPITECH PROJECT, 2022
** CPE_BSQ_2017
** File description:
** Created by Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

int get_lines(char const *str)
{
	int result = 0;
	int i = 0;

	while (str[i] != '\n') {
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i] - 48);
		i++;
	}
	if (result < 0)
		return (-1);
	return (result);
}

int get_columns(char const *str)
{
	int result = 0;
	int i = 0;

	for (i = 0; str[i] != '\n'; i++);
	i++;
	for (i = i; str[i] != '\n'; i++)
		result++;
	result++;
	return (result);
}