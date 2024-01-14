#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
/**
 * create_file - a func that creates a file
 * @filename: the file
 * @text_content: NULL terminated to write to the file
 * Return: 1 or -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int f, wf, len, cf;
	mode_t mode = S_IRUSR | S_IWUSR;

	if (filename == NULL)
		return (-1);

	f = open(filename, O_CREAT | O_WRONLY | O_TRUNC, mode);
	if (f == -1)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len] != '\0'; len++)
			;
		wf = write(f, text_content, len);
	}
	if (wf == -1)
		return (-1);

	cf = close(f);
	if (cf == -1)
		return (-1);
	return (1);
}
