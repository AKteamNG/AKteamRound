#include <cstdio>
#include <algorithm>
#include <climits>
#include <sstream>
#include <iostream>

const int MAXN = 1000;
using namespace std;
int a1[155],b[155],a[155],sum[155],bb[155];

int main() {
	int n;
	freopen("input","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a1[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	sort(a1+1,a1+1+n);
	fclose(stdin);
	freopen("answer", "r", stdin);
	long long x;
	scanf("%lld",&x);
	for (int i=1;i<=n;i++) scanf("%d",&bb[i]);
	fclose(stdin);
	freopen("user_out", "r", stdin);
	long long val;
	scanf("%lld",&val);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	long long ans=0;
	for (int i=1;i<=n;i++) 
	{
		sum[i]=sum[i-1]+a[i];
		ans+=(long long)(b[i]-sum[i])*(b[i]-sum[i])*a[i];
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) 
		if (a[i]!=a1[i])
		{
			fprintf(stderr, "Your sequence is not a.");
			puts("0");
			return 0;
		}
	if (ans!=val)
	{
		fprintf(stderr, "Are you cheating me? Your value isn't conform to your sequence.");
		puts("0");
		return 0;
	}
	if (ans<x)
	{
		fprintf(stderr, "Your value is too small.");
		puts("0");
		return 0;
	}
	if (ans==x)
	{
		fprintf(stderr, "Good.You are correct!");
		puts("100");
		return 0;
	}
	fprintf(stderr, "Oh,your answer is lager than Standard answer!");
	puts("150");
	return 0;
//	puts("100");
}
