/*
** EPITECH PROJECT, 2017
** BSQ
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "library.h"

static char **malloc_array(int n_lines, int n_columns)
{
	char **result = malloc(sizeof(char *) * (n_lines + 1));

	if (result == NULL || n_lines > 100000)
		return (NULL);
	for (int i = 0; i < n_lines; i++) {
		result[i] = malloc(sizeof(char) * (n_columns + 1));
		if (result[i] == NULL)
			return (NULL);
		result[i][n_columns] = '\0';

	}
	result[n_lines] = NULL;
	return (result);
}

static void fill_buffer_xy(char *buffer, char **buffer_xy, int n_lines)
{
	int i = 0;
	int nb = 0;

	for (i = 0; buffer && buffer[i] != '\0' && buffer[i] != '\n'; i++);
	i++;
	for (int n = 0; n < n_lines; n++) {
		for (; buffer && buffer[i] != '\0' && buffer[i] != '\n'; i++) {
			buffer_xy[n][nb] = buffer[i];
			nb++;
		}
		buffer_xy[n][nb] = buffer[i];
		i++;
		nb = 0;
	}
}

static int buffer_xy(char *buffer)
{
	int n_lines = get_lines(buffer);
	int n_columns = get_columns(buffer);
	char **buffer_xy = malloc_array(n_lines, n_columns);

	if (buffer_xy == NULL)
		return (84);
	fill_buffer_xy(buffer, buffer_xy, n_lines);
	if (find_square(buffer_xy) == 84)
		return (84);
	for (int i = 0; buffer_xy[i] != NULL; i++)
		my_putstr(buffer_xy[i]);
	my_free_array(buffer_xy);
	return (0);
}

int bsq(char const *filepath)
{
	struct stat stru;
	int fd = 0;
	int size = 0;
	char *buffer = NULL;

	if ((fd = open(filepath, O_RDONLY)) == -1)
		return (84);
	stat(filepath, &stru);
	buffer = malloc(sizeof(char) * stru.st_size + 1);
	size = stru.st_size;
	read(fd, buffer, size);
	buffer[size] = '\0';
	if (map_test(buffer) == 84 || buffer_xy(buffer) == 84) {
		close(fd);
		free(buffer);
		return (84);
	}
	close(fd);
	free(buffer);
	return (0);
}
