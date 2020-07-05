#pragma warning(disable: 4996)
#include <stdio.h>

char arr[3072][6144];

void    make_triangle(int star_num, int x, int y)
{
    if (star_num == 3)
    {
        //첫줄
        arr[y][x] = '*';
        //두번째줄
        arr[y + 1][x - 1] = '*';
        arr[y + 1][x + 1] = '*';
        //세번째줄
        arr[y + 2][x - 2] = '*';
        arr[y + 2][x - 1] = '*';
        arr[y + 2][x] = '*';
        arr[y + 2][x + 1] = '*';
        arr[y + 2][x + 2] = '*';
    }
    else
    {
        //젤 위에 삼각형
        make_triangle(star_num / 2, x, y);
        //왼쪽 아래 삼각형
        make_triangle(star_num / 2, x - (star_num / 2), y + (star_num / 2));
        //오른쪽 아래 삼각형
        make_triangle(star_num / 2, x + (star_num / 2), y + (star_num / 2));
    }
}

int main()
{
    int star_num;
    scanf("%d", &star_num);

    for (int i = 0; i < star_num; i++)
    {
        for (int j = 0; j < 2 * star_num - 1; j++)
        {
            arr[i][j] = ' ';
        }
    }
    make_triangle(star_num, star_num - 1, 0);
    for (int i = 0; i < star_num; i++)
    {
        for (int j = 0; j < 2 * star_num - 1; j++)
            printf("%c", arr[i][j]);
        printf("\n");
    }
    return (0);
}