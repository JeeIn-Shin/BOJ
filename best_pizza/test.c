#pragma warning(disable: 4996)
#include <stdio.h>

int main()
{
    int N, A, B, C, Di, SUM, PRICE;

    scanf("%d", &N);
    scanf("%d %d", &A, &B);
    scanf("%d", &C);
    SUM = C;
    PRICE = A;

    while (N > 0)
    {
        scanf("%d", &Di);
        if (Di / B > SUM / PRICE)
        {
            SUM += Di;
            PRICE += B;
        }
        N--;
    }
    printf("%d", SUM / PRICE);
    return 0;
}