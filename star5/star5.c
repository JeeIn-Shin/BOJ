#include <stdio.h>

int main(void)
{
    int star_num;
    int row;
    int col;

    scanf("%d", &star_num);
    row = 2 * star_num - 1;
    col = star_num;

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < col - i - 1; j++)
            printf(" ");
        for (int j = 0; j < 2 * i + 1; j++)
            printf("*");
        if (i < col - 1)
            printf("\n");
    }
    return (0);
}