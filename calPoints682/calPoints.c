#include <stdio.h>
int calPoints(char **ops, int opsSize)
{
    if (0 >= opsSize)
        return 0;
    int temp = **ops - '0';
    printf("%s", *ops);
    printf("  %d\n", temp);
    printf("  %c\n", ops[0][0]);
}
int main()
{
    char *ops[40] = {"500", "2", "C", "D", "+"};
    // char *pp = ops[100][1];
    // printf("%c\n",*pp);
    // char (*p1)[4] = ops[100][4];
    char **p2 = ops;

    printf("%s\n", *(p2 + 1));
    calPoints(p2, 5);

    printf("Hello\n");

    return 0;
}
