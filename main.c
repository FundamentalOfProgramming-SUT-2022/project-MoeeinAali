// Moeein Aali : FOP-Project-Phase1 : 401105561
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>
#include <windows.h>
/////////////////////////////
#define LINE_LENGH 200
#define DIR_LENGTH 200
#define FILE_LINE_LENGTH 1000
#define BIG_LENGTH 10000
#define MAX_INT_LENGTH 10
#define BUFF_ADDRESS "root/.TMP"
/////////////////////////////
void start_program(void);
void input_line(char *string);
void create_file(char *input);
int find_key_word(char *str, char *match);
void copy_from_to(char *to, char *from, int l, int r);
bool double_quotation_checker(char *filename);
bool remove_double_quotation(char *filename);
void dir_checker(char *dir);
bool create_filewithdirs(char *filename);
void make_alldirs(char *dir);
bool create(char *filename);
void insert(char *input);
bool insert_text(char *dir, char *text, int linepos, int charpos, int seekpos);
bool RandW_line(int n, FILE *myfile, FILE *sourcefile);
bool RandW_chars(int n, FILE *myfile, FILE *sourcefile);
bool RandW_seeks(int n, FILE *myfile, FILE *sourcefile);
void write_txt_into_file(char *text, FILE *myfile, FILE *sourcefile);
void RMandMVandCP(char *input, int mode);
bool remove_func1(char *dir, int linepos, int charpos, int seekpos, int size, bool ForB);
bool seek_chars(int n, bool ForB, FILE *sourcefile);
bool copy_to_clipboard(char *dir, int linepos, int charpos, int size, bool ForB);
bool seek_lines(int n, FILE *sourcefile);
bool cut_to_clipboard(char *dir, int linepos, int charpos, int size, bool ForB);
void paste_func(char *input);
bool paste_from_clipboard(char *dir, int linepos, int charpos);
void cat_func(char *input);
void print_jakhali(int n);
int chand_raghami(int n);
// void grep(char *input);
// void split(char *text, char (*paths)[DIR_LENGTH]);
// void grep_func(char (*paths)[DIR_LENGTH], char *text, bool l_checker, bool c_checker);
// bool findMatchFromIndex(const char *str, const char *match, int startingIndex, bool isForward);
// void inputLineFromFile(FILE *fp, char *str);
/////////////////////////////
/*

void main(void)
{
    start_program();
}

void start_program(void)
{
    char *input = (char *)malloc(sizeof(char) * LINE_LENGH);
    char command[20];
    while (1)
    {
        input_line(input);
        int i = 0;
        while (input[i] != ' ' && input[i] != '\n')
        {
            command[i] = input[i];
            i++;
        }
        if (strcmp(command, "quit") == 0)
        {
            break;
        }
        else if (strcmp(command, "createfile") == 0)
        {
            create_file(input);
            continue;
        }
        else if (strcmp(command, "insertstr") == 0)
        {
            insert(input);
            continue;
        }
        else if (strcmp(command, "removestr") == 0)
        {
            RMandMVandCP(input, 1);
            continue;
        }
        else if (strcmp(command, "copystr") == 0)
        {
            RMandMVandCP(input, 2);
            continue;
        }
        else if (strcmp(command, "cutstr") == 0)
        {
            RMandMVandCP(input, 3);
            continue;
        }
        else if (strcmp(command, "grep") == 0)
        {
            // grep(input);
            continue;
        }
        else if (strcmp(command, "cls") == 0)
        {
            printf("\e[1;1H\e[2J");
            continue;
        }
        else if (strcmp(command, "pastestr") == 0)
        {
            paste_func(input);
            puts("String Pasted Successfully ...");
            continue;
        }
        else if (strcmp(command, "cat") == 0)
        {
            cat_func(input);
        }
        else
        {
            puts("Command not Found !");
            continue;
        }
    }
}
void input_line(char *string)
{
    char buff = getchar();
    int cnt = 0;
    while (buff != '\n' && buff != EOF && cnt != LINE_LENGH)
    {
        string[cnt] = buff;
        buff = getchar();
        cnt++;
    }
    string[cnt] = '\0';
}
void create_file(char *input)
{
    int arg1 = 0;
    arg1 = find_key_word(input, " --file");
    if (arg1 == -1)
    {
        puts("Invalid Command !");
        puts("Correct Command: --file");
        return;
    }
    char filename[DIR_LENGTH];
    copy_from_to(filename, input, arg1 + 1, BIG_LENGTH);
    if (double_quotation_checker(filename) == -1)
    {
        puts("Invalid Directory !");
        return;
    }
    dir_checker(filename);
    create_filewithdirs(filename);
}
int find_key_word(char *string, char *key)
{
    int keyindex = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == key[keyindex])
        {
            keyindex++;
            if (key[keyindex] == '\0')
            {
                return i + 1;
            }
        }
        else
        {
            keyindex = 0;
            if (string[i] == key[keyindex])
            {
                keyindex++;
            }
        }
    }
    return -1;
}
// int find_key_word(char *str, char *match)
// {
//     int matchIndex = 0;
//     for (int i = 0; str[i] != '\0'; i++)
//     {
//         if (str[i] == match[matchIndex])
//         {
//             matchIndex++;
//             if (match[matchIndex] == '\0')
//                 return i + 1;
//         }
//         else
//         {
//             matchIndex = 0;
//             if (str[i] == match[matchIndex])
//                 matchIndex++;
//         }
//     }
//     return -1;
// }
void copy_from_to(char *to, char *from, int l, int r)
{
    if (r == -1)
    {
        r = BIG_LENGTH;
    }
    if (l >= r)
    {
        puts("Copy Range is Invalid !!!");
        return;
    }
    int flag = 0;
    for (int i = l; i < r && from[i] != '\0'; i++)
    {
        to[flag] = from[i];
        flag++;
    }
    to[flag] = '\0';
}
bool double_quotation_checker(char *filename)
{
    if (!remove_double_quotation(filename) && strchr(filename, ' ') != NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool remove_double_quotation(char *filename)
{
    if (filename[0] != '"' || filename[strlen(filename) - 1] != '"')
    {
        return false;
    }
    int i = 0;
    while (1)
    {
        filename[i] = filename[i + 1];
        if (filename[i] == '\0')
        {
            filename[i - 1] = '\0';
            break;
        }
        i++;
    }
}
void dir_checker(char *dir)
{
    if (dir[0] != '/')
    {
        return;
    }
    else
    {
        int i = 0;
        while (1)
        {
            dir[i] = dir[i + 1];
            if (dir[i] == '\0')
            {
                if (dir[i - 1] == '/')
                {
                    dir[i - 1] = '\0';
                }
                return;
            }
            i++;
        }
    }
}
bool create_filewithdirs(char *filename)
{
    make_alldirs(filename);
    if (access(filename, F_OK) == 0)
    {
        puts("File Already Exists!!!");
        return false;
    }
    return create(filename);
}
void make_alldirs(char *dir)
{
    char dir_buff[MAX_PACKAGE_NAME] = {};
    for (int i = 0; dir[i] != '\0'; i++)
    {
        if (dir[i] == '/')
        {
            dir_buff[i] = '\0';
            mkdir(dir_buff);
        }
        dir_buff[i] = dir[i];
    }
}
bool create(char *filename)
{
    FILE *fp;
    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        puts("Error!!!");
        return false;
    }
    else
    {
        puts("File Created Successfully !");
        fclose(fp);
        return true;
    }
}
void insert(char *input)
{
    char dir[DIR_LENGTH] = {};
    char text[BIG_LENGTH] = {};
    char pos[MAX_INT_LENGTH] = {};
    int linepos = 1;
    int charspos = 0;
    int arg1 = find_key_word(input, " --file");
    int arg2 = find_key_word(input, " --str");
    int arg3 = find_key_word(input, " -pos");
    if (arg1 == -1 || arg2 == -1 || arg3 == -1)
    {
        puts("Invalid Command !");
        puts("Correct Command: --file --str -pos");
        return;
    }
    copy_from_to(dir, input, arg1 + 1, arg2 - 6);
    copy_from_to(text, input, arg2 + 1, arg3 - 5);
    copy_from_to(pos, input, arg3 + 1, -1);
    if (double_quotation_checker(dir) == -1)
    {
        puts("Invalid Directory !");
        return;
    }
    if (double_quotation_checker(text) == -1)
    {
        puts("Invalid Text !");
        return;
    }
    if (sscanf(pos, "%d:%d", &linepos, &charspos) != 2)
    {
        puts("Invalid Position !");
        return;
    }
    // printf("%d %d",linepos,charspos);
    if (insert_text(dir, text, linepos, charspos, -1) == true)
    {
        puts("String Inserted Successfully ...");
    }
}
bool insert_text(char *dir, char *text, int linepos, int charpos, int seekpos)
{
    FILE *sourcefile = fopen(dir, "r");
    if (sourcefile == NULL)
    {
        puts("File Doesn't Exists !!!");
        return false;
    }
    FILE *myfile = fopen(BUFF_ADDRESS, "w");
    if (seekpos == -1)
    {
        if (RandW_line(linepos, myfile, sourcefile) == false)
        {
            puts("Wrong Line Pos ...");
            return false;
        }
        if (RandW_chars(charpos, myfile, sourcefile) == false)
        {
            puts("Wrong Chars Pos ...");
            return false;
        }
    }
    else
    {
        RandW_seeks(seekpos, myfile, sourcefile);
    }
    write_txt_into_file(text, myfile, sourcefile);
    char buff;
    while ((buff = fgetc(sourcefile)) != EOF)
    {
        fprintf(myfile, "%c", buff);
    }
    fclose(myfile);
    fclose(sourcefile);
    if (remove(dir) != 0)
    {
        puts("Can't Remove Source File !!!");
        return false;
    }
    if (rename(BUFF_ADDRESS, dir) != 0)
    {
        puts("Can't Rename TMP File !!!");
        return false;
    }
    return true;
}
bool RandW_line(int n, FILE *myfile, FILE *sourcefile)
{
    char buff;
    int line_cnt = 1;
    while (line_cnt != n)
    {
        buff = fgetc(sourcefile);
        if (buff == EOF)
        {
            return false;
        }
        if (buff == '\n')
        {
            line_cnt++;
            continue;
        }
        fprintf(myfile, "\n");
    }
    return true;
}
bool RandW_chars(int n, FILE *myfile, FILE *sourcefile)
{
    char buff;
    int char_cnt = 0;
    while (char_cnt != n)
    {
        buff = fgetc(sourcefile);
        if (buff == EOF || buff == '\n')
        {
            return false;
        }
        fprintf(myfile, "%c", buff);
        char_cnt++;
    }
    return true;
}
bool RandW_seeks(int n, FILE *myfile, FILE *sourcefile)
{
    char buff;
    int char_cnt = 0;
    while (char_cnt != n)
    {
        buff = fgetc(sourcefile);
        if (buff == EOF)
        {
            break;
        }
        fprintf(myfile, "%c", buff);
        char_cnt++;
    }
}
void write_txt_into_file(char *text, FILE *myfile, FILE *sourcefile)
{
    bool backslash_checker = false;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (backslash_checker == true)
        {
            if (text[i] == '\\')
            {
                fprintf(myfile, "\\");
            }
            else if (text[i] == 'n')
            {
                fprintf(myfile, "\n");
            }
            backslash_checker = false;
            continue;
        }
        if (text[i] == '\\')
        {
            backslash_checker = true;
            continue;
        }
        if (text[i] == '\r')
        {
            continue;
        }
        fprintf(myfile, "%c", text[i]);
    }
}

void RMandMVandCP(char *input, int mode)
{
    char dir[DIR_LENGTH] = {};
    char pos[MAX_INT_LENGTH] = {};
    char sizestr[MAX_INT_LENGTH] = {};
    int linepos = 0, charpos = 0, size = 0;
    bool ForB = true;

    int arg1 = find_key_word(input, " --file");
    int arg2 = find_key_word(input, " -pos");
    int arg3 = find_key_word(input, " -size");
    int arg4 = find_key_word(input, " -f");
    if (arg4 == -1)
    {
        ForB = false;
        arg4 = find_key_word(input, " -b");
    }
    if (arg4 == -1 || arg2 == -1 || arg3 == -1 || arg4 == -1)
    {
        puts("Invalid Command !");
        puts("Correct Command: --file -pos -size -f/-b");
        return;
    }
    copy_from_to(dir, input, arg1 + 1, arg2 - 5);
    copy_from_to(pos, input, arg2 + 1, arg3 - 5);
    copy_from_to(sizestr, input, arg3 + 1, arg4 - 3);

    if (double_quotation_checker(dir) == -1)
    {
        puts("Invalid Directory !");
        return;
    }
    dir_checker(dir);

    if (sscanf(pos, "%d:%d", &linepos, &charpos) != 2)
    {
        puts("Invalid Position !");
        return;
    }
    if (sscanf(sizestr, "%d", &size) != 1)
    {
        puts("Invalid Size !");
        return;
    }
    switch (mode)
    {
    case 1:
        if (remove_func1(dir, linepos, charpos, -1, size, ForB) == true)
        {
            puts("String Removed ...");
        }
        break;
    case 2:
        if (copy_to_clipboard(dir, linepos, charpos, size, ForB) == true)
        {
            puts("String Copied ...");
        }
        break;
    case 3:
        if (cut_to_clipboard(dir, linepos, charpos, size, ForB) == true)
        {
            puts("String Cutted ...");
        }
        break;
    }
}
bool remove_func1(char *dir, int linepos, int charpos, int seekpos, int size, bool ForB)
{
    FILE *sourcefile = fopen(dir, "r");
    if (sourcefile == NULL)
    {
        puts("File Doesn't Exists !!!");
        return false;
    }
    FILE *myfile = fopen(BUFF_ADDRESS, "w+");
    if (seekpos == -1)
    {
        if (RandW_line(linepos, myfile, sourcefile) == false)
        {
            puts("Wrong Line Pos ...");
            return false;
        }
        if (RandW_chars(charpos, myfile, sourcefile) == false)
        {
            puts("Wrong Chars Pos ...");
            return false;
        }
    }
    else
    {
        RandW_seeks(seekpos, myfile, sourcefile);
    }
    if (ForB == false)
    {
        seek_chars(size, false, myfile);
    }
    else
    {
        seek_chars(size, true, sourcefile);
    }
    char buff;
    while ((buff = fgetc(sourcefile)) != EOF)
    {
        fprintf(myfile, "%c", buff);
    }
    fclose(myfile);
    fclose(sourcefile);
    remove(dir);
    rename(BUFF_ADDRESS, dir);
    return true;
}
bool seek_chars(int n, bool ForB, FILE *sourcefile)
{
    int char_cnt = 0;
    char buff;
    while (char_cnt != n && ForB == true)
    {
        buff = fgetc(sourcefile);
        char_cnt++;
        if (buff == EOF)
        {
            return false;
        }
    }
    while (char_cnt != n && ForB == false)
    {
        if (fseek(sourcefile, -1, SEEK_CUR) != 0)
        {
            return false;
        }
        buff = fgetc(sourcefile);
        if (buff == '\n')
        {
            fseek(sourcefile, -2, SEEK_CUR);
        }
        else
        {
            fseek(sourcefile, -1, SEEK_CUR);
        }
        char_cnt++;
    }
    return true;
}
bool copy_to_clipboard(char *dir, int linepos, int charpos, int size, bool ForB)
{
    FILE *sourcefile = fopen(dir, "r");
    char str_buff[BIG_LENGTH] = {};
    if (sourcefile == NULL)
    {
        puts("File Doesn't Exists !!!");
        return false;
    }
    if (seek_lines(linepos - 1, sourcefile) == false)
    {
        puts("Wrong Line Pos ...");
        return false;
    }
    if (seek_chars(size, true, sourcefile) == false)
    {
        puts("Wrong Char Pos ...");
        return false;
    }
    if (ForB == false)
    {
        seek_chars(size, ForB, sourcefile);
    }
    char buff;
    int i = 0;
    while (i < size && (buff = fgetc(sourcefile)) != EOF)
    {
        str_buff[i] = buff;
        i++;
    }
    str_buff[i] = '\0';
    int lengh = strlen(str_buff) + 1;
    HGLOBAL x = GlobalAlloc(GMEM_MOVEABLE, lengh * sizeof(char));
    memcpy(GlobalLock(x), str_buff, lengh);
    GlobalUnlock(x);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, x);
    CloseClipboard();
    fclose(sourcefile);
    return true;
}
bool seek_lines(int n, FILE *sourcefile)
{
    char buff;
    int line_cnt = 0;
    while (line_cnt != n)
    {
        buff = fgetc(sourcefile);
        if (buff == EOF)
        {
            return false;
        }
        if (buff == '\n')
        {
            line_cnt++;
            continue;
        }
    }
    return true;
}
bool cut_to_clipboard(char *dir, int linepos, int charpos, int size, bool ForB)
{
    if (copy_to_clipboard(dir, linepos, charpos, size, ForB) == false)
    {
        return false;
    }
    if (remove_func1(dir, linepos, charpos, -1, size, ForB) == false)
    {
        return false;
    }
    return true;
}
void paste_func(char *input)
{
    char dir[DIR_LENGTH] = {};
    char pos[BIG_LENGTH] = {};
    int linepos = 0;
    int charpos = 0;
    int arg1 = find_key_word(input, " --file");
    int arg2 = find_key_word(input, " -pos");
    if (arg1 == -1 || arg2 == -1)
    {
        puts("Invalid Command !");
        puts("Correct Command: --file -pos");
        return;
    }
    copy_from_to(dir, input, arg1 + 1, arg2 - 5);
    copy_from_to(pos, input, arg2 + 1, -1);
    if (double_quotation_checker(dir) == -1)
    {
        puts("Invalid Directory !");
        return;
    }
    if (sscanf(pos, "%d:%d", &linepos, &charpos) != 2)
    {
        puts("Invalid Position !");
        return;
    }
    dir_checker(dir);
    paste_from_clipboard(dir, linepos, charpos);
}
bool paste_from_clipboard(char *dir, int linepos, int charpos)
{
    char text[BIG_LENGTH] = {};
    OpenClipboard(0);
    HANDLE clipboard = GetClipboardData(CF_TEXT);
    char *data = (char *)GlobalLock(clipboard);
    strcpy(text, data);
    GlobalUnlock(clipboard);
    CloseClipboard();
    if (insert_text(dir, text, linepos, charpos, -1) == false)
    {
        puts("Error in Pasting by Insert-Func !!!");
        return false;
    }
    return true;
}
void cat_func(char *input)
{
    int arg1 = find_key_word(input, " --file");
    if (arg1 == -1)
    {
        puts("Invalid Command !");
        puts("Correct Command: --file");
        return;
    }
    char dir[DIR_LENGTH] = {};
    copy_from_to(dir, input, arg1 + 1, -1);
    if (double_quotation_checker(dir) == -1)
    {
        puts("Invalid Directory !");
        return;
    }
    dir_checker(dir);
    if (access(dir, R_OK) == -1)
    {
        printf("File doesn't exist\n");
        return;
    }
    FILE *myfile = fopen(dir, "r");
    if (myfile == NULL)
    {
        puts("File Doesn't Exists !!!");
        return;
    }
    char buff;
    int line_cnt = 1;
    printf("%d>", line_cnt);
    print_jakhali(6 - chand_raghami(line_cnt));
    line_cnt++;
    while ((buff = fgetc(myfile)) != EOF)
    {
        if (buff == '\n')
        {
            printf("\n%d>", line_cnt);
            print_jakhali(6 - chand_raghami(line_cnt));
            line_cnt++;
            continue;
        }
        printf("%c", buff);
    }
    printf("\n");
    fclose(myfile);
    return;
}
void print_jakhali(int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf(" ");
    }
}

int chand_raghami(int n)
{
    int javab = 0;
    while (n > 0)
    {
        javab++;
        n /= 10;
    }
    return javab;
}

*/

// void grep(char *input)
// {
//     int arg1 = find_key_word(input, " --str");
//     int arg2 = find_key_word(input, " --files");
//     if (arg1 == -1 || arg2 == -1)
//     {
//         puts("Required: --str, --files");
//         return;
//     }
//     char text[BIG_LENGTH] = {};
//     char dirs[LINE_LENGH] = {};
//     char(*paths)[DIR_LENGTH] = (char(*)[DIR_LENGTH])calloc(MAX_GREP_FILECOUNT, sizeof(char[DIR_LENGTH]));
//     bool l_checker = false, c_checker = false;
//     if (find_key_word(input, "-c") != -1)
//     {
//         c_checker = true;
//     }
//     else if (find_key_word(input, "-l") != -1)
//     {
//         l_checker = true;
//     }
//     copy_from_to(text, input, arg1 + 1, arg2 - 8);
//     copy_from_to(text, input, arg2 + 1, -1);
//     if (double_quotation_checker(text) == -1)
//     {
//         puts("Invalid Text !");
//         return;
//     }
//     split(text, paths);
//     grep_func(paths, text, l_checker, c_checker);
//     free(paths);
// }
// void split(char *text, char (*paths)[DIR_LENGTH])
// {
//     int pathStartIndex = 0, pathEndIndex, pathsIndex = 0;
//     char buff;
//     while (1)
//     {
//         if (text[pathStartIndex] == '"')
//         {
//             pathStartIndex++;
//             for (pathEndIndex = pathStartIndex; text[pathEndIndex] != '"'; pathEndIndex++)
//             {
//                 if (text[pathEndIndex] == '\0')
//                 {
//                     return;
//                 }
//             }
//             copy_from_to(paths[pathsIndex], text, pathStartIndex, pathEndIndex);
//             dir_checker(paths[pathsIndex]);
//             pathStartIndex = pathEndIndex + 2;
//         }
//         else
//         {
//             for (pathEndIndex = pathStartIndex; text[pathEndIndex] != ' '; pathEndIndex++)
//             {
//                 if (text[pathEndIndex] == '\0')
//                 {
//                     break;
//                 }
//             }
//             copy_from_to(paths[pathsIndex], text, pathStartIndex, pathEndIndex);
//             dir_checker(paths[pathsIndex]);
//             pathStartIndex = pathEndIndex + 1;
//         }
//         if (text[pathStartIndex - 1] == '\0')
//         {
//             break;
//         }
//         pathsIndex++;
//     }
// }
// void grep_func(char (*paths)[DIR_LENGTH], char *text, bool l_checker, bool c_checker)
// {
//     if (c_checker && l_checker == true)
//     {
//         puts("We Can't Use l and c together ...");
//         return;
//     }
//     int cnt = 0;
//     for (int fileIndex = 0; paths[fileIndex][0] != '\0'; fileIndex++)
//     {
//         bool foundAMatch = false;
//         FILE *fp;
//         fp = fopen(paths[fileIndex], "r");
//         if (fp == NULL)
//         {
//             printf("File %s doesn't exist\n", paths[fileIndex]);
//             return;
//         }
//         while (!feof(fp))
//         {
//             char currentLine[FILE_LINE_LENGTH];
//             inputLineFromFile(fp, currentLine);
//             for (int i = 0; currentLine[i] != '\0'; i++)
//             {
//                 if (!findMatchFromIndex(currentLine, text, i, 1))
//                     continue;
//                 if (l_checker)
//                     foundAMatch = true;
//                 else if (c_checker == false)
//                     printf("%d- %s: %s\n", cnt + 1, paths[fileIndex], currentLine);
//                 cnt++;
//                 break;
//             }
//             if (l_checker && foundAMatch)
//                 break;
//         }
//         if (l_checker && foundAMatch)
//             printf("%s\n", paths[fileIndex]);
//     }
//     if (c_checker)
//         printf("%d\n", cnt);
// }
// bool findMatchFromIndex(const char *str, const char *match, int startingIndex, bool isForward)
// {
//     int matchIndex, iterator = 1;
//     int matchLen = strlen(match);
//     if (isForward)
//         matchIndex = 0;
//     else
//     {
//         iterator = -1;
//         matchIndex = matchLen - 1;
//     }
//     for (int i = startingIndex; matchLen != 0; matchLen--)
//     {
//         if (i == -1 || matchIndex == -1 || match[matchIndex] == '\0' || str[i] == '\0')
//             return false;
//         if (str[i] != match[matchIndex])
//             return false;
//         i += iterator;
//         matchIndex += iterator;
//     }
//     return true;
// }

// void inputLineFromFile(FILE *fp, char *str)
// {
//     char c;
//     int inputIndex = 0;
//     c = fgetc(fp);
//     while (c != '\n' && c != EOF && inputIndex != FILE_LINE_LENGTH - 1)
//     {
//         str[inputIndex++] = c;
//         c = fgetc(fp);
//     }
//     str[inputIndex] = '\0';
// }