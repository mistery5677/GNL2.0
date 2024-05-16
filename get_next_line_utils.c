#include "get_next_line.h"

int clean_buffer(char *buffer)
{
    int flag;
    int i;
    int j;

    j = 0;
    i = 0;
    flag = 0;
    while (buffer[i])
    {
        if(flag == 1)
        {
            buffer[j] = buffer[i];
            j++;
        }
        if (buffer[i] == '\n')
            flag = 1;
        buffer[i] = '\0';
        i++;
    }
    return flag;
}
int ft_strlen(char *str)
{
    int i;
    i = 0;

    if (str == NULL)
        return 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
    return i;
}

char *ft_strjoin(char *s1, char *s2)
{
    char *str;
    int i;
    int j;

    i = 0;
    j = 0;
    str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if(!str)
        return NULL;
    while(s1 && s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    while(s2 && s2[j] && s2[j] != '\n')
    {
        str[i + j] = s2[j];
        j++;
    }
    if (s2[j] == '\n')
    {
        str[i + j] = '\n';
        j++;
    }
    str[i + j] = '\0';
    free(s1);
    return str;
}