#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "createfile.c"
void error()
{
    printf("Invalid Command !!!");
}
void command_input()
{
    char command[50] = {};
    scanf("%s",&command);
    if(strcmp(command,"createfile")==0) //createfile
    {
        char check1[10] ={};
        scanf("%s",&check1);
        if(strcmp(check1,"--file")==0)
        {
            getchar() ;
            create_file();



        }
        else
        {
            error();
            return ;
        }




    }
}

int main()
{
    command_input();
}