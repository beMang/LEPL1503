#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * @pre str!=NULL, chars!=NULL
 * @ret retourne un pointeur vers un chaîne contenant str dont
 *  on a supprimé en fin tous les caractères se trouvant dans chars.
 *      Supprime les espaces si chars="" ou chars=NULL
 */
char *rstrip(char *str, char *chars){
    char* to_remove = (chars==NULL || chars=="") ? " " : chars;
    if(str==NULL) return NULL;
    int len = strlen(str);

    int delete_from = len;
    for (int i = len-1; i>0; i--)
    {
        int found = 0;
        for (int j = 0; j < strlen(to_remove); j++)
        {
            if (str[i]==to_remove[j]) {
                delete_from--;
                found = 1;
                break;
            }
        }
        if (found==0) break;
    }

    char* result = malloc(sizeof(char)*(delete_from+1));
    if(result==NULL) return NULL;

    for (int i = 0; i < delete_from; i++)
    {
        result[i] = str[i];
    }
    result[delete_from] = '\0';
    return result;
}

int main(int argc, char const *argv[])
{
    char* str = "www.helloworld.com";
    char* chars = "cmoa.";
    printf("%s| \n", rstrip(str, chars));

    char* chars1 = "ldcmor.";
    printf("%s| \n", rstrip(str, chars1));

    char* str2 = "www.mozilla.org    ";
    char* chars2 = "";
    printf("%s| \n", rstrip(str2, chars2));
    char* str3 = "abccc";
    char* chars3 = "c";
    printf("%s| \n", rstrip(str3, chars3));
    return 0;
}
