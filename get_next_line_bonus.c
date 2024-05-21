#include "get_next_line_bonus.h"

char *get_next_line(int fd)
{
    static char buffer[FOPEN_MAX][BUFFER_SIZE + 1];
    char *str;
 
    if (BUFFER_SIZE <= 0 || fd < 0 || fd > FOPEN_MAX)
        return NULL;
    if(!buffer[fd][0])
        read(fd, buffer[fd], BUFFER_SIZE);
    str = NULL;
    while(buffer[fd][0])
    {
        str = ft_strjoin(str, buffer[fd]);
        if (!str)
            return NULL;
        if(clean_buffer(buffer[fd]) == 1)
            break ;
        read(fd, buffer[fd], BUFFER_SIZE);
    }
    return str;
}
