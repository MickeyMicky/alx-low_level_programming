#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <elf.h>
#include <stdio.h>


void error_exit(int exit_code, const char *error_message)
{
	fprintf(stderr, "%s", error_message);
	exit(exit_code);
}

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
	printf("OS/ABI: %s\n", header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "Other");
	printf("ABI Version: %d\n", header.e_ident[EI_ABIVERSION]);

	printf("Type: ");
	switch (header.e_type)
	{
		case ET_NONE: printf("NONE"); break;
		case ET_REL: printf("REL"); break;
		case ET_EXEC: printf("EXEC"); break;
		case ET_DYN: printf("DYN"); break;
		case ET_CORE: printf("CORE"); break;
		default: printf("UNKNOWN"); break;
	}
       	printf("\n");

	printf("Entry point address: 0x%lx\n", (unsigned long)header.e_entry);

	close(fd);
	return (0);
}
