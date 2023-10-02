#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <elf.h>
#include <stdio.h>

/**
 * error_exit - Function to print an error message to STDERR
 * and exit with the given exit code
 * @code: the exit code to be given
 * @exit_msg: exit message
 * Description: If the file is not an ELF File or
 * the function fails - exit code 98.
 */
void error_exit(int code, const char *exit_msg)
{
	fprintf(stderr, "%s", exit_msg);
	exit(code);
}

/**
 * main - program that displays the information contained in
 * the ELF header at the start of an ELF file
 * @argc: number of arguments
 * @argv: an array of pointers
 *
 * Return: 0 (success)
 * Description: If the file is not an ELF File or
 * the function fails - exit code 98.
 */
int main(int argc, char *argv[])
{
	int fd, i;
	const char *elf_filename = argv[1];
	ssize_t r;
	Elf64_Ehdr header;

	if (argc != 2)
	error_exit(98, "Usage: elf_header elf_filename\n");

	fd = open(elf_filename, O_RDONLY);

	if (fd == -1)
	error_exit(98, "Error: Unable to open the ELF file.\n");

	r = read(fd, &header, sizeof(header));

	if (r != sizeof(header) || memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
		error_exit(98, "Error: Not an ELF file.\n");

	printf("Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", header.e_ident[i]);
		if (i < EI_NIDENT - 1)
			printf(" ");
	}
	printf("\n");

	printf("Class: %s\n", header.e_ident[EI_CLASS] ==
			ELFCLASS64 ? "ELF64" : "ELF32");
	printf("Data: %s\n", header.e_ident[EI_DATA] == ELFDATA2LSB ?
			"2's complement, little endian" : "2's complement, big endian");
	printf("Version: %d\n", header.e_ident[EI_VERSION]);
	printf("OS/ABI: %s\n", header.e_ident[EI_OSABI] == ELFOSABI_SYSV ?
			"UNIX - System V" : "Other");
	printf("ABI Version: %d\n", header.e_ident[EI_ABIVERSION]);

	close(fd);
	return (0);
}
