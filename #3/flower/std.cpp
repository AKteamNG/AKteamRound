#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int col[100010],Fa[100010],Next[200010],vet[200010],head[200010],num,a[100010];
const int INF=1000000010;
int read()
{
	int ans=0;
	char ch=getchar(),last='+';
	while (ch<'0'||ch>'9') last=ch,ch=getchar();
	while (ch>='0'&&ch<='9') ans=ans*10+ch-'0',ch=getchar();
	if (last=='-') return -ans;
	return ans;
}
void add(int u,int v)
{
	Next[++num]=head[u];
	head[u]=num;
	vet[num]=v;
}
struct LCT{
	multiset<int>Set[100010];
	int son[100010][2],fa[100010],a[100010],tree[100010],val[100010],Max[100010];
	int isroot(int x)
	{
		return (son[fa[x]][0]!=x&&son[fa[x]][1]!=x);
	}
	void update(int x)
	{
		tree[x]=tree[son[x][0]]+tree[son[x][1]]+val[x]+1;
		Max[x]=a[x];
		if (son[x][0]) Max[x]=max(Max[x],Max[son[x][0]]);
		if (son[x][1]) Max[x]=max(Max[x],Max[son[x][1]]);
		if (Set[x].size()) 
		{
			multiset<int>::iterator xx=Set[x].end();
			xx--;
			Max[x]=max(Max[x],*xx);
		}
	}
	void rotate(int x)
	{
		int y=fa[x],z=fa[y];
		if (!isroot(y))
			son[z][son[z][1]==y]=x;
		int l=son[y][1]==x,r=l^1;
		fa[y]=x,fa[x]=z,fa[son[x][r]]=y;
		son[y][l]=son[x][r],son[x][r]=y;
		update(y),update(x);
	}
	void splay(int x)
	{
		while (!isroot(x)) 
		{
			int y=fa[x],z=fa[y];
			if (!isroot(y)) 
			{
				if ((son[z][0]==y)^(son[y][0]==x)) rotate(x);
				else rotate(y);
			}
			rotate(x);
		}
	}
	void access(int x)
	{
		for (int t=0;x;t=x,x=fa[x])
		{
			splay(x);
			val[x]+=tree[son[x][1]];
			if (son[x][1]) Set[x].insert(Max[son[x][1]]);
			son[x][1]=t;
			if (son[x][1]) Set[x].erase(Set[x].find(Max[son[x][1]]));
			val[x]-=tree[son[x][1]];
			update(x);
		}
	}
	void link(int u) //link u and u's father
	{
		int father=Fa[u];
		update(u);
		splay(u);
		access(father);
		splay(father);
		fa[u]=father;
		val[father]+=tree[u];
		tree[father]+=tree[u];
		Set[father].insert(Max[u]);
		Max[father]=max(Max[father],Max[u]);
	}
	void cut(int u) //cut u and u's father
	{
		access(u);
		splay(u);
		fa[son[u][0]]=0,son[u][0]=0;
		update(u);
	}
	int findroot(int x)
	{
		access(x);
		splay(x);
		while (son[x][0]) x=son[x][0];
		splay(x);
		return x;
	}
	void modify(int u,int w)
	{
		access(u);	
		splay(u);
		a[u]=w;
		update(u);
	}
}lct[2];
struct SegmentTree{
	int lson[6400010],rson[6400010],tree[6400010],root[200010],cnt;
	int find(int t,int l,int r,int k)
	{
		if (l==r) return l;
		int mid=(l+r)>>1;
		if (tree[rson[t]]>=k) return find(rson[t],mid+1,r,k);
		return find(lson[t],l,mid,k-tree[rson[t]]);
	}
	void insert(int &t,int l,int r,int pos,int key)
	{
		if (!t) t=++cnt;
		if (l==r)
		{
			tree[t]+=key;
			return;
		}
		int mid=(l+r)>>1;
		if (pos<=mid) insert(lson[t],l,mid,pos,key);
		else insert(rson[t],mid+1,r,pos,key);
		tree[t]=tree[lson[t]]+tree[rson[t]];
	}
}st[2];
void dfs(int u,int father)
{
	Fa[u]=father;
	lct[col[u]].link(u);
	for (int i=head[u];i;i=Next[i])
	{
		int v=vet[i];
		if (v!=father) dfs(v,u);
	}
}
int main()
{
	int n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	for (int i=1;i<=n;i++) col[i]=read();
	lct[0].modify(n+1,-INF),lct[1].modify(n+1,-INF);
	dfs(1,n+1);
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		lct[0].modify(i,a[i]);
		lct[1].modify(i,a[i]);	
	}
	for (int i=1;i<=n;i++)
		st[col[i]].insert(st[col[i]].root[Fa[i]],0,INF,a[i],1);
	int m=read();
	while (m--)
	{
		int ty=read(),u=read();
		if (ty==1)
		{
			int rt=lct[col[u]].findroot(u);
			printf("%d\n",lct[col[u]].tree[lct[col[u]].son[rt][1]]);
		}
		if (ty==2)
		{
			int rt=lct[col[u]].findroot(u);
			printf("%d\n",lct[col[u]].Max[lct[col[u]].son[rt][1]]);
		}
		if (ty==3)
		{
			int k=read();
			st[col[u]].insert(st[col[u]].root[u],0,INF,a[u],1);
			if (col[Fa[u]]==col[u]) st[col[u]].insert(st[col[u]].root[u],0,INF,a[Fa[u]],1);
			printf("%d\n",st[col[u]].find(st[col[u]].root[u],0,INF,k));
			st[col[u]].insert(st[col[u]].root[u],0,INF,a[u],-1);
			if (col[Fa[u]]==col[u]) st[col[u]].insert(st[col[u]].root[u],0,INF,a[Fa[u]],-1);
		}
		if (ty==4) 
		{
			lct[col[u]].cut(u);
			st[col[u]].insert(st[col[u]].root[Fa[u]],0,INF,a[u],-1);
			col[u]^=1;
			lct[col[u]].link(u);
			st[col[u]].insert(st[col[u]].root[Fa[u]],0,INF,a[u],1);
		}
		if (ty==5)
		{
			st[col[u]].insert(st[col[u]].root[Fa[u]],0,INF,a[u],-1);
			int w=read();
			a[u]=w;
			lct[0].modify(u,w),lct[1].modify(u,w);
			st[col[u]].insert(st[col[u]].root[Fa[u]],0,INF,a[u],1);
		}
	}
	return 0;
}
