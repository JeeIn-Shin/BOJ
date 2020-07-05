#pragma warning(disable: 4996)
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct confer
{
	int start;
	int end;
} confer;

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

bool cmp(const confer& a, const confer& b) {
	if (a.end == b.end) {
		return a.start < b.start;
	}
	else {
		return a.end < b.end;
	}
}

int main(void)
{
	int num;
	int idx;
	int result;
	confer* con;

	cin >> num;
	con = new confer[num];
	idx = 0 - 1;
	while (++idx < num)
		cin >> con[idx].start >> con[idx].end;
	sort(con, con + num, cmp);
	result = find_maxconfer(con, idx);
	cout << result;
	delete[] con;
	return (0);
}