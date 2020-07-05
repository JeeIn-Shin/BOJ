#include <iostream>
#include <string.h>
using namespace std;

int		**make_garden(int &row, int &col)
{
	int idx;
	int** garden;
	garden = new int *[col];
	idx = 0 - 1;
	while (++idx < col)
	{
		garden[idx] = new int[row];
		memset(garden[idx], 0, sizeof(int) * row);
	}
	return (garden);
}

void	free_memory(int** garden, int &col)
{
	int idx;

	idx = 0 - 1;
	while (++idx < col)
		delete[] garden[idx];
	delete[] garden;
}

void	dfs(int x, int y, int garden_x, int garden_y, int **garden)
{
	int dx[] = { 0, 0, -1, 1 };
	int dy[] = { 1, -1, 0, 0 };
	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < garden_y && 0 <= ny && ny < garden_x)
		{
			if (garden[nx][ny] == 1)
			{
				garden[nx][ny] = 2;
				dfs(nx, ny, garden_x, garden_y, garden);
			}
		}
	}
}

int		get_cabbageworm_num(int garden_x, int garden_y, int **garden)
{
	int worm;

	worm = 0;
	for (int i = 0; i < garden_y; i++)
	{
		for (int j = 0; j < garden_x; j++)
		{
			if (garden[i][j] == 1)
			{
				worm++;
				dfs(i, j, garden_x, garden_y, garden);
			}

		}
	}
	return (worm);
}

int		main(void)
{
	int testcase;
	int garden_x;
	int garden_y;
	int cabbage_num;
	int **garden;
	int cabbage_x;
	int cabbage_y;
	int worm_num;

	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		cin >> garden_x >> garden_y >> cabbage_num;
		garden = make_garden(garden_x, garden_y);
		for (int a = 0; a < cabbage_num; a++)
		{
			cin >> cabbage_x >> cabbage_y;
			garden[cabbage_y][cabbage_x] = 1;
		}
		worm_num = get_cabbageworm_num(garden_x, garden_y, garden);
		cout << worm_num << endl;
		free_memory(garden, garden_y);
	}
	return (0);
}

/*void    dfs(int i, int j, int map[52][52])
{
	if (map[i - 1][j] == 1 && i - 1 >= 0)
	{
		map[i - 1][j] += 1;
		dfs(i - 1, j, map);
	}
	if (map[i + 1][j] == 1 && i + 1 < N)
	{
		map[i + 1][j] += 1;
		dfs(i + 1, j, map);
	}
	if (map[i][j - 1] == 1 && j - 1 >= 0)
	{
		map[i][j - 1] += 1;
		dfs(i, j - 1, map);
	}
	if (map[i][j + 1] == 1 && j + 1 < M)
	{
		map[i][j + 1] += 1;
		dfs(i, j + 1, map);
	}
} */