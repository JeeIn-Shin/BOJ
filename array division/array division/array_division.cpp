#include <iostream>
#include <algorithm>
using namespace std;


int	main(void)
{
	ios::sync_with_stdio(0);

	int N;
	int K;
	int store;
	int i;
	int j;
	int* arr;
	int* temp;

	cin >> N >> K;
	arr = new int[N];
	temp = new int[N - 1];
	
	i = 0 - 1;
	while (++i < N)
	{
		cin >> store;
		arr[i] = store;
	}
	sort(arr, arr + N, greater<int>());
	
	i = 0 - 1;
	while (++i < N)
		cout << arr[i];
	cout << endl;
	
	while (K--)
	{
		j = 0 - 1;
		while (++j < N - 1)
		{
			temp[j] = arr[j] - arr[j];
		}
		sort(temp, temp + N - 1, greater<int>());
	}

	delete[] arr;
	delete[] temp;
	return (0);
}