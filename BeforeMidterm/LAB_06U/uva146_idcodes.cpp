#include <stdio.h>
#include <stdlib.h>

char code[51];

char getNextCharOfFirst(char *code, int start, int end){
    char next = 'z'+1;
    for(int i = start; i<end; i++){
        if(code[i] > code[start] && next > code[i])
            next = code[i];
    }
    return next;
}

int compare(const void *a, const void *b)
{
    return (*((char *)a) - *((char *)b));
}

bool ismax(char *code, int start, int end)
{
    if (end - start <= 1)
        return true;
    for (int i = start + 1; i < end; i++)
    {
        if (code[i - 1] < code[i])
            return false;
    }
    return true;
}

int main()
{
    int i;
    int N;
    char c;
    while (1)
    {
        for (i = 0; i == 0 || code[i - 1] != '\0'; i++)
        {
            scanf("%c", &code[i]);
            if (code[i] == '\n')
            {
                code[i] = '\0';
                N = i;
            }
            else if (code[i] == '#')
                return 0;
        }
        if (ismax(code, 0, N))
            printf("No Successor");
        else
        {
            for (i = N - 2; i >= 0; i--)
            {
                if (!ismax(code, i, N))
                    break;
            }
            c = code[i];
            code[i] = getNextCharOfFirst(code, i, N);
            // printf("%c: ", code[i]);
            for(int j = i+1; j < N; j++){
                if(code[j] == code[i]){
                    code[j] = c;
                    break;
                }
            }
            // printf("%s\t", code);
            qsort(&code[i+1], N-i-1, sizeof(char), compare);
            printf("%s", code);
        }
        printf("\n");
    }
    return 0;
}
