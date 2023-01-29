#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
void create_file()
{
    char string[50] = {};
    char buff;
    buff = getchar();
    int checker = 0;
    if (buff == '"')
    {
        checker = 1;
        getchar(); // for get / before root folder
    }
    buff = getchar();
    int i = 0;
    while (buff != '\n')
    {

        *(string + i) = buff;
        buff = getchar();
        if ((checker == 0) && (buff == ' '))
        {
            i++;
            break;
        }
        if ((checker == 1) && (buff == '"'))
        {
            i++;
            break;
        }
        else
        {
            i++;
        }
    }
    *(string + i) = '\0';
    if (buff == '"')
    {
        getchar();
    }

    for (int i = 0; i < 50; i++)
    {
        if (string[i] == '/')
        {
            char directory[i + 2];
            strncpy(directory, string, i + 1);
            directory[i + 1] = '\0';
            mkdir(directory);
        }
    }
    if (access(string, F_OK) == 0)
    {
        puts("File Already Exists !!!");
        return;
    }
    else
    {
        FILE* myfile = fopen(string,"w");
        puts("File Created !!!");
        fclose(myfile);
    }
}