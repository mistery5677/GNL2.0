#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i;
    i = 0;

    while(str[i])
        i++;
    return i;
}

char *ft_strjoin(char *s1, char *s2)
{
    char *str;
    int i = 0;
    int j = 0;

    i = 0;
    str = malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
    if(!str)
        return NULL;
    while(s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    j = 0;
    while(s2[j])
    {
        if (s2[j] == '\n')
        {
            str[i + j] = '\n';
            break;
        }
        str[j + i] = s2[j];
        j++;
    }
    str[j + i] = '\0';
    return str;
}

int find_line(char *str)
{   
    int i;
    i = 0;

    while(str[i])
    {
        if(str[i] == '\n')
            return 1;
        i++;
    }
    return 0;
}

/* int update_buffer(char *buffer)
{
    int i;

    i = 0;
    while(buffer[i] && buffer[i] != '\n')
        i++;
    if (buffer[i] == '\n')
        i++;
    return i;
} */