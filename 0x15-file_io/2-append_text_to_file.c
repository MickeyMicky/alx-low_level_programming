#include "main.h"

/**
 * append_text_to_file - function that appends text at the end of a file.
 * @filename: A pointer to file name
 * @text_content: string to be add.
 *
 * Return: -1 - If function fails or filename is NULL or
 *         If the file does not exist the user lacks write permissions.
 *         1 - if success.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, w, count = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (count = 0; text_content[count];)
			count++;
	}

	fd = open(filename, O_WRONLY | O_APPEND);
	w = write(fd, text_content, count);

	if (fd == -1 || w == -1)
		return (-1);

	close(fd);

	return (1);
}
