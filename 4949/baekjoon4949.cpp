#include <iostream>
#include <string>
#include <stack>
using namespace std;

int	main(void)
{
	stack <char> stack;
	string str;
	int idx;
	int flag;
	char temp;

	while (1)
	{
		getline(cin, str);
		if (str == ".")
			break ;
		idx = 0;
		flag = 0;
		for (; idx <= str.size(); idx++)
		{
			temp = str[idx];
			switch (temp)
			{
			case '(':
				stack.push(temp);
				break ;
			case '[':
				stack.push(temp);
				break ;
			case ')':
				if (stack.empty() || stack.top() != '(')
					flag = 1;
				else
					stack.pop();
				break ;
			case ']':
				if (stack.empty() || stack.top() != '[')
					flag = 1;
				else
					stack.pop();
				break ;
			}
		}
		//���
		if (flag || !stack.empty())
			cout << "no\n";
		else
			cout << "yes\n";
		//�ʱ�ȭ
		while (!stack.empty())
			stack.pop();
	}
	return (0);
}
