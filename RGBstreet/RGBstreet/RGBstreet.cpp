#include <stdio.h>

int setresult(int min)
{
	int result;

	result += min;
	return (result);
}

int **init_house(int house[][3], int house_num)
{
	int idx;

	idx = 0;
	while (idx < house_num)
	{
		scanf("%d", house[][idx]);
	}
	return (house);
}

int ft_min(int a, int b)
{
	return (a < b ? a : b);
}

int	find_min_purchase(int house[][3], int house_num)
{
	int min;
	int result;
	int idx;

	idx = 1;
	while (idx < house_num)
	{
		house[idx][0] += ft_min(house[idx - 1][1], house[idx - 1][2]);
		house[idx][1] += ft_min(house[idx - 1][0], house[idx - 1][2]);
		house[idx][2] += ft_min(house[idx - 1][0[, house[idx - 1][1]);
		idx++;
	}
	return (result);
}

int	main(void)
{
	int result;
	int house_num;
	int house[][];

	scanf("%d", house_num);
	house = make_house(house_num);
	house = init_house(house, house_num);
	find_min_purchase(house, house_num);
	return (0);
}