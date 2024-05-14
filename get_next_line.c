#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    char *str;
    int bytes;

    bytes = 1;
    if(!buffer[0])
        read(fd,buffer,BUFFER_SIZE);
    str = NULL;
    str = ft_strjoin(str,buffer);
    while (bytes > 0 && find_line(buffer) == 0)
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        str = ft_strjoin(str, buffer);
    }
    
    return str;
}

int main()
{
    int fd = open("test.txt", O_RDONLY);
    char *str = get_next_line(fd);

    printf("str: %s\n", str);
    str = get_next_line(fd);
    printf("str: %s\n", str);
}