#pragma warning(disable: 4996)
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10000

typedef struct	stack
{
	int		data[MAX_SIZE];
	int		top;
}				stack;

void	push(int *top, int idx, int x, stack *s)
{
	s->data[idx] = x;
	top++;
}

void	pop(int *top, stack *s)
{
	int temp;
	
	temp = top;
	if (top == 0)
		printf("-1\n");
	else
	{
		printf("%d\n", s->data[temp - 1]);
		top--;
	}
}

void	size(int top)
{
	printf("%d\n", top);
}

int empty(int top)
{
	if (top == 0)
		printf("1\n");
	else
		printf("0\n");
}

int top(int top, stack *s)
{
	if(empty()) 
		printf("%d\n", -1);
	else
		printf("%d\n", s->data[top - 1]);
}

int	main(void)
{
	stack s;
	int idx;
	int num;
	int data;
	int peek;
	char *order;

	idx = 0 - 1;
	scanf("%d", &num);
	while (++idx < num)
	{
		scanf("%s", &order);
		if (strcmp(order, "push") == 0)
		{
			scanf("%d", &data);
			push(&peek, idx, data, &s);
		}
		if (strcmp(order, "pop") == 0)
			pop(&peek, &s);
		if (strcmp(order, "size") == 0)
			size(peek);
		if (strcmp(order, "empty") == 0)
			empty(peek);
		if (strcmp(order, "top") ==0)
			top(peek, &s);
	}
	return (0);
}