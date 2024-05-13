#include "get_next_line.h"

int main()
{
    int fd = open("test.txt", O_RDONLY);
    char *str = get_next_line(fd);
    while(str)
    {
        printf("str %s", str);
        free(str);
        str = get_next_line(fd);
    }
}