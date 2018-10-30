#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
bool sum[10010][10010],h[10010],l[10010];
char ch[10010];
int ans,n,m,a,b,Mod;
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d%d%d%d%d",&n,&m,&a,&b,&Mod);
	long long num=a;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			num=(num*b%Mod+a)%Mod;
			if (num&1)
			{
				sum[i][j]^=1;
				h[i]^=1;l[j]^=1;
			}
		}
	}
	//return 0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			ans+=(sum[i][j]^h[i]^l[j]);
	printf("FKC AK IOI 2019!\n");
	printf("%d\n",ans);
	return 0;
}
