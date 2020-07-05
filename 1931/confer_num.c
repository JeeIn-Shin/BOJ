#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct confer
{
	int start;
	int end;
} confer;

void Swap(confer *con, int a, int b)
{
	confer temp = con[a];
	con[a] = con[b];
	con[b] = temp;
}

int Partition(confer *con, int p, int r) {
	int pivot = con[p].end;
	int low = p + 1;
	int high = r;

	while (low <= high)
	{
		while (pivot >= con[low].end && low <= r)
			low++;
		while (pivot <= con[high].end && high >= (p + 1))
			high--;
		if (low <= high)
			Swap(con, low, high);
	}
	Swap(con, p, high);
	return high;
}

void QuickSort(confer *con, int p, int r) {
	if (p <= r) {
		int pivot = Partition(con, p, r);
		QuickSort(con, p, pivot - 1);
		QuickSort(con, pivot + 1, r);
	}
}

int	find_maxconfer(confer* con, int num)
{
	int result;
	int i;
	int end;

	result = 1;
	i = 0;
	end = con[0].end;
	while (++i < num)
	{
		if (end <= con[i].start)
		{
			end = con[i].end;
			result++;
		}
	}
	return (result);
}

int	main(void)
{
	int num;
	int idx;
	int result;
	confer* con;

	scanf("%d", &num);
	con = (confer *)malloc(sizeof(confer) * num);
	idx = 0 - 1;
	while (++idx < num)
		scanf("%d%d" ,&con[idx].start ,&con[idx].end);
	QuickSort(con, 0, num - 1);
	result = find_maxconfer(con, idx);
	printf("%d", result);
	free(con);
	return (0);
}