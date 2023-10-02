#include "main.h"

/**
 * create_file - function that creates a file.
 * @filename: A pointer to the name of the file to be create.
 * @text_content: A pointer to a string
 *
 * Return: -1 if the function fails.
 *        1 success.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, w;
	int count = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (count = 0; text_content[count];)
			count++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(fd, text_content, count);

	if (fd == -1 || w == -1)
		return (-1);

	close(fd);

	return (1);
}
