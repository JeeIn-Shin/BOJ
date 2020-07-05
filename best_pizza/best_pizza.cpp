#include <iostream>
#include <algorithm>
using namespace std;

int toping_num;
int dough_price;
int dough_calorie;
int toping_price;

int		get_max(int* topings_caloire)
{
	int idx;
	int max;
	int total_price;
	int total_caloire;

	total_caloire = dough_calorie;
	total_price = dough_price;
	idx = 0 - 1;
	max = total_caloire / total_price;
	while (++idx < toping_num)
	{
		if (max < topings_caloire[idx] / toping_price)
		{
			total_caloire += topings_caloire[idx];
			total_price += toping_price;
			max = total_caloire / total_price;
		}
	}
	return (max);
}

int		main(void)
{
	int* topings_caloire;
	int idx;
	int max;

	cin >> toping_num;
	cin >> dough_price >> toping_price;
	cin >> dough_calorie;

	if (toping_num == 0)
	{
		max = dough_calorie / dough_price;
		cout << max;
		return (0);
	}
	else
	{
		topings_caloire = new int[toping_num];
		idx = 0 - 1;
		while (++idx < toping_num)
			cin >> topings_caloire[idx];
		sort(topings_caloire, topings_caloire + toping_num, greater<int>());
		max = get_max(topings_caloire);
	}	
	cout << max;
	delete [] topings_caloire;
	return (0);
}