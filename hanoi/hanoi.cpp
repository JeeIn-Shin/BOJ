#include <iostream>
using namespace std;

int		get_result(int hanoi_height, int &result)
{
	if (hanoi_height == 0)
		result = 0;
	else
	{
		result = 1;
		while (--hanoi_height)
			result = result * 2 + 1;
	}
	return (result);
}

void	print_process(int start, int end)
{
	printf("%d %d\n", start, end);
}

void	hanoi_process(int hanoi_height, int start, int via, int end)
{
	if (hanoi_height == 1)
		print_process(start, end);
	else
	{
		hanoi_process(hanoi_height - 1, start, end, via);
		print_process(start, end);
		hanoi_process(hanoi_height - 1, via, start, end);
	}
}

int	main(void)
{
	int result;
	int hanoi_height;

	scanf("%d", &hanoi_height);
	get_result(hanoi_height, result);
	printf("%d", result);
	hanoi_process(hanoi_height, 1, 2, 3);
	return (0);
}