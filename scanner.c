#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char path[] = "virus.txt";
    FILE *fls = fopen(path,"r");
    char buff;
    char lm[500];
    lm[lm, strlen(lm) - 1] = '\0';

    char kw[][25] = {
        "ip","isp","passwords",
        "addr","address","secret",
        "cookies","cookie","Cookies",
        "Cookie"
    };
    int kwSize = sizeof(kw) / sizeof(kw[0]);


    if (fls == NULL)
    {
        printf("FILE/DIRECTORY DOES NOT EXIST -> [%s]\n");
        return 1;
    }


    while (fgets(lm,sizeof(lm),fls))
    {
        for (int i = 0; i < kwSize; i++)
        {
            if (strstr(lm, kw[i]) != NULL)
            {
                printf("[WARNING] -> %s", lm);
                printf("[KEYWORD] -> %s\n",kw[i]);
            }

            else
            {
                continue;
            }
        }
    }

    return 0;
}