#pragma warning(disable: 4996)

#include <iostream>
#include <stdio.h>
using namespace std;

char arr[3072][6000];
char tri[3][6] = { "  *  ",
                   " * * ",
                   "*****" };
void print(int x, int y)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[y + i][x + j] = tri[i][j];
        }
    }
}
void printtri(int N, int x, int y)
{
    if (N == 3)
    {
        print(x, y);
    }
    else
    {
        printtri(N / 2, x + (N / 2), y); // 위쪽
        printtri(N / 2, x, y + (N / 2)); // 왼쪽 아래
        printtri(N / 2, x + N, y + (N / 2)); // 오른쪽아래
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2 * N - 1; j++)
        {
            arr[i][j] = ' ';
        }
    }
    printtri(N, 0, 0);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2 * N - 1; j++)
        {
            printf("%c", arr[i][j]);
        }
        if (i != N - 1)
            printf("\n");
    }
    return 0;
}