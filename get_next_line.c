#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i;
    i = 0;

    if (str == NULL)
        return 0;
    while(str[i])
        i++;
    return i;
}

char *ft_strjoin(char *s1, char *s2)
{
    char *str;
    int i = 0;
    int j = 0;


    str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if(!str)
        return NULL;
    while(s1[i] && s1[i] != '\0')
    {
        str[i] = s1[i];
        i++;
    }
    while(s2[j] && s2[j] != '\n')
    {
        str[i + j] = s2[j];
        j++;
    }
    if (s2[j] == '\n')
        str[i + j] = '\n';
    str[i + j] = '\0';
    return str;
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    char *str;

    if(!buffer[0])
    { 
        read(fd, buffer, BUFFER_SIZE);
        
    }
    str = NULL;
    str = ft_strjoin(str, buffer);
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