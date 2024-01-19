#ifndef MAIN_H
#define MAIN_H

ssize_t read_textfile(const char *filename, ssize_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void args_error(void);
void f_from_error(char *file);
void f_to_error(char *file);
void c_error(int fd);

#endif
