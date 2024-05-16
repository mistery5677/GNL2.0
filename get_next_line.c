#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    char *str;
 
    if (BUFFER_SIZE <= 0 || fd < 0)
        return NULL;
    if(!buffer[0])
        read(fd, buffer, BUFFER_SIZE);
    str = NULL;
    while(buffer[0])
    {
        str = ft_strjoin(str, buffer);
        if (!str)
            return NULL;
        if(clean_buffer(buffer) == 1)
            break ;
        read(fd, buffer, BUFFER_SIZE);
    }
    return str;
}

/* int main()
{
    int fd = open("test.txt", O_RDONLY);
    char *str = get_next_line(fd);

    printf("str: %s\n", str);
    free(str);
} */