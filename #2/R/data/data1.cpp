#include <cstdio>
#include <cstdlib>
#include <ctime>

FILE *IN, *OUT;
int T;

int main()
{
	IN = fopen("R1.in", "w");
	OUT = fopen("R1.out", "w");
	T = 0;
	fprintf(IN, "%d\n", T);
	fclose(IN);
	fclose(OUT);
	return 0;
}
