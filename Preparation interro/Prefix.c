#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * @pre str, prefix, res !=NULL, res pointe vers une zone mémoire
 * @ret place dans res le suffixe de str dont on a retiré le préfix prefix
 */
void removeprefix(char *str, char *prefix, char *res)
{
    int removable = 0;
    if (strlen(prefix)>strlen(str)) removable = 1;
    for (size_t i = 0; i < strlen(prefix); i++)
    {
        if(prefix[i]!=str[i]) {
            removable=1;
            break;
        }
    }
    if (removable==1) {
        strcpy(res, str);
    } else{
        //Si préfixe valide :
        if (strlen(str)==strlen(prefix))
        {
            strcpy(res, "");
        }
        for (int i = strlen(prefix); i < strlen(str); i++)
        {
            res[i-strlen(prefix)] = str[i];
        }
    }
}

int main(int argc, char const *argv[])
{
    char *res = (char *)malloc(sizeof(char *));
    char *str = "UCLouvain <3";
    char *prefix = "UCL";
    removeprefix(str, prefix, res);
    printf("%s\n", res);
    char *prefix1 = "KUL";
    removeprefix(str, prefix1, res);
    printf("%s\n", res);

    removeprefix(str, "UCLouvain <3", res);
    printf("%s\n", res);
    return 0;
}