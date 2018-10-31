#include<cstdio>
#include<algorithm>
#include<cstring>
#define mo 998244353
using namespace std;
inline int mod(int x)
{
	if (x>=mo) x-=mo;
	return x;
}
int F[505][505],n,num,ans[505][505],a[1005],root,vet[1005],vel[1005],Next[1005];
int head[505];
void add(int u,int v,int w)
{
	Next[++num]=head[u];
	head[u]=num;
	vet[num]=v;
	vel[num]=w;
}
int read()
{
	int ans=0;
	char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9')
	{
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans;
}
void dfs(int u,int f[],int pre,int fa)
{
	if (a[u]>a[root])
	{
		F[u][0]=0;
		for (int i=1;i<=n;i++) F[u][i]=f[i-1];
	}
	else for (int i=0;i<=n;i++) F[u][i]=f[i];
	for (int i=head[u];i;i=Next[i])
	{
		int v=vet[i];
		if (v!=fa) dfs(v,F[u],vel[i],u);
	}
	for (int i=0;i<=n;i++) 
	{	
		if (pre==0) f[i]=mod(f[i]+F[u][i]);
		else f[i]=F[u][i];
	}
}
int main()
{
	//freopen("G7-5.in","r",stdin);
//	freopen("G7-5.out","w",stdout);
	n=read();
	int q=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,w);
	}
	for (int i=1;i<=n;i++)
	{
		root=i;
		memset(F[i],0,sizeof(F[i]));
		F[i][1]=1;
		for (int j=head[i];j;j=Next[j])
		{
			int v=vet[j];
			dfs(v,F[i],vel[j],i);
		}
		for (int j=0;j<=n;j++)
			ans[i][j]=F[i][j];
	}
	while (q--)
	{
		int d=read(),Ans=0;
		while (d--)
		{	
			int u=read(),k=read();
			Ans=mod(Ans+ans[u][k]);
		}
		printf("%d\n",Ans);
	}
	return 0;
}
