#include <stdio.h>

int	main(void)
{
	int star_num;

	scanf("%d", &star_num);

	for (int i = 1; i <= star_num; i++)
	{
		for (int j = 0; j < i; j++)
			printf("*");
		for (int j = i * 2; j < star_num * 2; j++)
			printf(" ");
		for (int j = 0; j < i; j++)
			printf("*");
		printf("\n");
	}
	for (int i = star_num; i > 0; i--)
	{
		for (int j = i - 1; j > 0; j--)
			printf("*");
		for (int j = 0; j < (star_num - i) * 2 + 2; j++)
			printf(" ");
		for (int j = i - 1; j > 0; j--)
			printf("*");
		printf("\n");
	}
	return (0);
}