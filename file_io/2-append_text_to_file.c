#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
/**
 * append_text_to_file - appends text
 * @filename: pointer to file
 * @text_content: text to write
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int f, wf, cf, len;

	if (filename == NULL)
		return (-1);

	f = open(filename, O_APPEND | O_WRONLY);
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

