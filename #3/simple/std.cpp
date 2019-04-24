#include<cstdio>
#include<algorithm>
using namespace std;
int addnum,vel[6100000],ne[6100000],head[6100000];
int dfn[6100000],dep[3100000],nfd[3100000];
int w[3100000];
int q[1100000],b[310000];
int l[310000],r[310000],d[310000];
int f[310000][21],tot;
int n,m;
const int MOD=1e9+7;
void add(int u,int v)
{
	addnum++,vel[addnum]=v,ne[addnum]=head[u],head[u]=addnum;
}
void dfs(int u,int fa)
{		
	dfn[++tot]=dep[u]; nfd[u]=tot;
	for (int e=head[u];e;e=ne[e])
	{
		int v=vel[e];
		if (v==fa) continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
		dfn[++tot]=dep[u];
	}
}
int read()
{
	int ans=0;
	char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') ans=(ans<<1)+(ans<<3)+ch-'0',ch=getchar();
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	int x,c;
	scanf("%d%d",&x,&c);
	for (int i=2;i<=n;i++)
	{
		int y=(1ll*x*x+c)%(i-1)+1;
		add(i,y),add(y,i);
	}
	dfs(1,-1);
	w[0]=-1;
	for (int i=1;i<=tot;i++) w[i]=w[i/2]+1; 
	int t=20;
	//printf("1\n");
	for (int i=0;i<(1<<t);i++)
	{
		for (int j=t-1;j>=0;j--)
		if (i&(1<<j))
		{
			int ds=0,num=0;
			for (int dw=j-1;dw>=0;dw--)
				if (i&(1<<dw)) num++;
				else num--,ds=min(ds,num);
			q[i]=ds;
			break;
		}
	}
	for (int i=1;i<=tot;i++) b[i]=(i-1)/t+1;
	for (int i=1;i<=tot;i++) l[b[i]]=!l[b[i]]?i:l[b[i]],r[b[i]]=i;
//	printf("1\n");
	for (int i=1;i<=b[tot];i++)
	{
		d[i]=1;
		for (int j=l[i]+1;j<=r[i];j++)
			d[i]=(d[i]<<1)+(dfn[j]>dfn[j-1]?1:0);
	//	printf("%d\n",d[i]);
		f[i][0]=dfn[l[i]]+q[d[i]]; 
	}
	for (int i=1;i<=20;i++)
		for (int j=1;j<=b[tot]-(1<<i)+1;j++)
			f[j][i]=min(f[j][i-1],f[j+(1<<(i-1))][i-1]);	
	//printf("1\n");
	int lastans=0;
	while (m--)
	{
		int k;
		x=read(),c=read(),k=read();
		x=x^lastans,c=c^lastans;
		int minn=1e9,maxx=0;
		long long sum=0;
		for (int i=1;i<=k;i++)
			x=(1ll*x*x+c)%(n-2)+2,sum=sum+dfn[nfd[x]],minn=min(minn,nfd[x]),maxx=max(maxx,nfd[x]);
		int mins=1e9;
		//printf("%d %d\n",b[minn],b[maxx]);
		if (b[minn]==b[maxx])
		{
		
			int dt=d[b[minn]];
			dt=dt>>(r[b[minn]]-maxx);
			dt=dt&((1<<(maxx-minn))-1);
			dt=dt|(1<<(maxx-minn));
			//printf("num=%d\n",dt);
			mins=min(mins,dfn[minn]+q[dt]);
		} else
		{
			int dx=b[minn]+1,dy=b[maxx]-1;
			int dt=w[dy-dx+1];
			if (dx<=dy)mins=min(f[dx][dt],f[dy-(1<<dt)+1][dt]);
			dt=d[b[minn]];
			dt=dt&((1<<(r[b[minn]]-minn))-1);
			dt=dt|(1<<(r[b[minn]]-minn));
			mins=min(mins,dfn[minn]+q[dt]);
			dt=d[b[maxx]];
			dt=dt>>(r[b[maxx]]-maxx);
			//printf("num=%d\n",dt);
			mins=min(mins,dfn[l[b[maxx]]]+q[dt]);
		} 
	//	printf("%d\n",mins);
		lastans=(sum-1ll*mins*k)%MOD;
	}
	printf("%d\n",lastans);
}
