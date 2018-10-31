#include <cstdio>
#include <cstdlib>
#include <ctime>

const int M = 10;
FILE *IN, *OUT;
int T;

int main()
{
	srand(time(NULL));
	IN = fopen("R4.in", "w");
	OUT = fopen("R4.out", "w");
	T = 10;
	fprintf(IN, "%d\n", T);
	for (int i = 1; i <= T; i++)
	{
		int k = rand() % 3;
		if (k == 0)
		{
			fprintf(IN, "%d %d\n", 1, 1);
			fprintf(OUT, "Lucy & Bob\n");
		}
		else
		{
			fprintf(IN, "%d %d\n", rand() % M + 1, rand() % M + 1);
			fprintf(OUT, "Alice & Bob\n");
		}
	}
	fclose(IN);
	fclose(OUT);
	return 0;
}
