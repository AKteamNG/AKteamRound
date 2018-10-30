#include<cstdio>
#include<algorithm>
#define maxs(a,b) (a>b)?a:b
using namespace std;
int a[100010];
char st[5];
int main()
{
	int n,m,tmp=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	while (m--)
	{
		scanf("%s",st);
		if (st[0]=='A') 
		{
			int x;
			scanf("%d",&x);
			tmp+=x;
		}
		else
		{
			int l,r;
			long long ans=0,sum=0;
			scanf("%d %d",&l,&r);
			for (int i=l;i<=r;i++)
			{
				sum+=a[i]+tmp;
				if (sum<0) sum=0;
				ans=maxs(ans,sum);
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
