#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - function that read text file and prints it to POSIX STDOUT.
 * @filename: text file
 * @letters: number of letters
 * Return: actual number of letters it could read and print
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t file;
	ssize_t w;
	ssize_t r;

	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	r = read(file, buffer, letters);
	w = write(STDOUT_FILENO, buffer, r);

	free(buffer);
	close(file);
	return (w);
}
