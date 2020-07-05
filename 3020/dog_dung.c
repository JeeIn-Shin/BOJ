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

	//���� ������ ���� ,�� �ε����� ���ϴ� �κ��� �ش� ũ���� ���� / �������� �ǹ�
	for (int i = 1; i <= width / 2; i++)
	{
		int h1, h2;
		scanf("%d%d", &h1, &h2);
		down[h1]++;
		up[h2]++;
	}
	
	//���� ������ ����
	for (int i = height; i > 0; i--)
	{
		down[i] += down[i + 1];
		up[i] += up[i + 1];
	}

	//�ּڰ� ã��
	min = 2147483647;
	for (int i = 1; i <= height; i++)
	{
		cnt[i] = down[i] + up[height - i + 1];
		if (cnt[i] < min)
			min = cnt[i];
	}

	//������ �ּҰ� �ִ��� üũ
	temp = 0;
	for (int i = 1; i <= height; i++)
		if (cnt[i] == min)
			temp++;
	printf("%d %d", min, temp);
	return (0);
}