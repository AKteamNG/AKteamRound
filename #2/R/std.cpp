#include <cstdio>

int T;
int n, m;

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		if (n == 1 && m == 1)
		{
			puts("Lucy & Bob");
		}
		else
		{
			puts("Alice & Bob");
		}
	}
	return 0;
}
