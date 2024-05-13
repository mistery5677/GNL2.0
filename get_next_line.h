#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char *get_next_line(int fd);
int find_line(char *str);
char *ft_strjoin(char *s1, char *s2);
int ft_strlen(char *str);
//char *update_buffer(char *buffer);
#endif