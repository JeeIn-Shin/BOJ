#include <iostream>
#include <algorithm>
using namespace std;

#include <iostream>
#include <algorithm>
using namespace std;

bool    compare_begin(int* a, int* b)
{
    return a[0] < b[0];
}

bool    compare_end(int* a, int* b)
{
    return a[1] < b[1];
}

int        main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, min, count;
    cin >> N;

    int** meet;
    meet = new int* [N];
    for (int i = 0; i < N; i++)
    {
        meet[i] = new int[2];
        cin >> meet[i][0] >> meet[i][1];
    }
    sort(meet, meet + N, compare_begin);
    sort(meet, meet + N, compare_end);

    min = meet[0][1];
    count = 1;
    for (int i = 1; i < N; i++)
    {
        if (meet[i][0] >= min)
        {
            count++;
            min = meet[i][1];
        }
    }
    cout << count;
}