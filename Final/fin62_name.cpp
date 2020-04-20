#include <stdio.h>

char name[100];
int count[100];
int state = 0;
int max_state = 0;

int main()
{
    char input;

    scanf("%s\n", &name);

    while (scanf("%c", &input) && input != '\n' && input != '\0')
    {
        if (input == name[state])
        {
            count[state]++;
            state++;
            if (name[state] == '\n' || name[state] == '\0')
            {
                max_state = state;
                state = 0;
            }
        }
    }

    // for (int i = 0; i < max_state+1; i++)
    // {
    //     printf("%d: %d\n", i, count[i]);
    // }

    printf("%d", count[state % max_state]);

    return 0;
}