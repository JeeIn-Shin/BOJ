#pragma warning (disable: 4996)
#include <stdio.h>

int down[500002] = { 0, };
int up[500002] = { 0, };
int cnt[500002] = { 0, };

int	main(void)
{
	int width;
	int height;
	int min;
	int temp;

	scanf("%d %d", &width, &height);

	//석순 종유석 개수 ,각 인덱스가 말하는 부분이 해당 크기의 석순 / 종유석을 의미
	for (int i = 1; i <= width / 2; i++)
	{
		int h1, h2;
		scanf("%d%d", &h1, &h2);
		down[h1]++;
		up[h2]++;
	}
	
	//석순 종유석 누적
	for (int i = height; i > 0; i--)
	{
		down[i] += down[i + 1];
		up[i] += up[i + 1];
	}

	//최솟값 찾기
	min = 2147483647;
	for (int i = 1; i <= height; i++)
	{
		cnt[i] = down[i] + up[height - i + 1];
		if (cnt[i] < min)
			min = cnt[i];
	}

	//동일한 최소값 있는지 체크
	temp = 0;
	for (int i = 1; i <= height; i++)
		if (cnt[i] == min)
			temp++;
	printf("%d %d", min, temp);
	return (0);
}