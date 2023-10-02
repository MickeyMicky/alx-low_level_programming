#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *fd);
void exit_the_file(int fd);

/**
 * main - program that Copies the contents of a file to another file.
 * @argc: number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 (success).
 *
 * Description: exit code 97 - If the argument count is incorrect.
 * exit code 98 - If file_from does not exist or cannot be read.
 * exit code 99 - If file_to cannot be created or written.
 * exit code 100 - If file_to or file_from cannot be closed.
 */
int main(int argc, char *argv[])
{
	int from, to, w, r;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buffer);
	exit_the_file(from);
	exit_the_file(to);

	return (0);
}

/**
 * create_buffer - function that allocates 1024 bytes for a buffer.
 * @fd: name of the file buffer.
 *
 * Return: pointer to the newly-allocated buffer.
 */
char *create_buffer(char *fd)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);

	if (!buf)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", fd);
		exit(99);
	}

	return (buf);
}

/**
 * exit_the_file - function that exit the file descriptors.
 * @fd: file descriptor.
 */
void exit_the_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
