#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
/**
 * read_textfile - read a text file and prints it to the POSIX stdout
 * @filename: a bf
 * @letters: of letters to read
 * Return: letters
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int f = 0, rf = 0, wf = 0, cf;
	char *bf;

	bf = malloc(sizeof(char) * letters);
	if (bf == NULL)
		return (0);
	if (filename == NULL)
		return (0);
	f = open(filename, O_RDONLY);
	if (f == -1)
		return (0);
	rf = read(f, bf, letters);
	if (rf == -1)
		return (0);
	wf = write(STDOUT_FILENO, bf, rf);
	if (wf == -1)
		return (0);
	cf = close(f);
	if (cf == -1)
		return (0);
	free(bf);
	return (rf);
}
