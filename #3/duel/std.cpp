#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int N=100005,INF=1073741823;
int n,m,a[N],dis[N],en,head[N],vet[N<<1],Next[N<<1],val[N<<1],fa[N][17],deep[N],rmin[N][17],f[N],g[N];
pair<int,int> h[N];
pair<int,pair<int,int> > b[N];
bool vis[N];
long long ans;
void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch<='9'&&ch>='0'){
		x=x*10+ch-'0';
		ch=getchar();
	}
}
void addedge(int u,int v,int VAL){
	Next[++en]=head[u];
	head[u]=en;
	vet[en]=v;
	val[en]=VAL;
}
void dfs(int u,int pre){
	deep[u]=deep[pre]+1;
	fa[u][0]=pre;
	for(int i=1;i<=16;i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
		rmin[u][i]=min(rmin[u][i-1],rmin[fa[u][i-1]][i-1]);
	}
	for(int i=head[u];i;i=Next[i]){
		int v=vet[i];
		if(v!=pre){
			rmin[v][0]=val[i];
			dfs(v,u);
		}
	}
}
int query(int x,int y){
	int ans=INF;
	if(deep[x]<deep[y])
		swap(x,y);
	int t=deep[x]-deep[y];
	for(int i=0;i<=16;i++)
		if(t>>i&1){
			ans=min(ans,rmin[x][i]);
			x=fa[x][i];
		}
	for(int i=16;i>=0;i--)
		if(fa[x][i]!=fa[y][i]){
			ans=min(ans,rmin[x][i]);
			ans=min(ans,rmin[y][i]);
			x=fa[x][i];
			y=fa[y][i];
		}
	return x==y?ans:min(ans,min(rmin[x][0],rmin[y][0]));
}
int getf(int x){
	if(x==f[x])
		return x;
	return f[x]=getf(f[x]);
}
struct trie{
	int cnt,son[10000005][2],rmin[10000005],rmax[10000005],root;
	void init(){
		root=cnt=1;
		rmin[1]=INF;
		rmax[1]=-INF;
		son[1][0]=0;
		son[1][1]=0;
	}
	void add(int x,int y){
		int u=root;
		rmin[u]=min(rmin[u],y);
		rmax[u]=max(rmax[u],y);
		for(int i=29;i>=0;i--)
			if(x>>i&1){
				if(!son[u][1]){
					son[u][1]=++cnt;
					son[cnt][0]=0;
					son[cnt][1]=0;
					rmin[cnt]=rmax[cnt]=y;
				}
				u=son[u][1];
				rmin[u]=min(rmin[u],y);
				rmax[u]=max(rmax[u],y);
			}
			else{
				if(!son[u][0]){
					son[u][0]=++cnt;
					son[cnt][0]=0;
					son[cnt][1]=0;
					rmin[cnt]=rmax[cnt]=y;
				}
				u=son[u][0];
				rmin[u]=min(rmin[u],y);
				rmax[u]=max(rmax[u],y);
			}
	}
	int query(int x,int y){
		int u=root,res=0;		
		for(int i=29;i>=0;i--)
			if(x>>i&1){
				if(son[u][0]&&(rmin[son[u][0]]!=y||rmax[son[u][0]]!=y))
					u=son[u][0];
				else{
					u=son[u][1];
					res|=(1<<i);
				}
			}
			else{
				if(son[u][1]&&(rmin[son[u][1]]!=y||rmax[son[u][1]]!=y)){
					u=son[u][1];
					res|=(1<<i);
				}
				else
					u=son[u][0];
			}
		return res;
	}
}tree;
void Boruvka(){
	int num=n;
	for(int i=1;i<=n;i++)
		f[i]=i;
	while(num>1){
		tree.init();
		for(int i=1;i<=n;i++){
			tree.add(a[i],getf(i));
			h[i]=make_pair(0,0);
			b[i]=make_pair(a[i],make_pair(getf(i),i));
		}
		sort(b+1,b+1+n);
		for(int i=1;i<=n;i++){
			int x=h[getf(i)].first,y=h[getf(i)].second,z=tree.query(a[i],getf(i));
			if(x==0||(a[i]^z)>=(a[x]^y))
				h[getf(i)]=make_pair(i,z);
		}
		for(int i=1;i<=n;i++)
			if(i==getf(i)){
				int x=h[i].first,z=h[i].second,y=b[lower_bound(b+1,b+1+n,make_pair(z,make_pair(0,0)))-b].second.second;
				if(getf(y)==i)
					y=b[lower_bound(b+1,b+1+n,make_pair(z+1,make_pair(0,0)))-b-1].second.second;
				if(getf(y)!=i){
					f[f[y]]=i;
					num--;
					ans+=a[x]^a[y];
					addedge(x,y,a[x]^a[y]);
					addedge(y,x,a[x]^a[y]);
				}
			}
	}
}
int main(){
	read(n);
	read(m);
	for(int i=1;i<=n;i++)
		read(a[i]);
	Boruvka();
	printf("%lld\n",ans);
	dfs(1,0);
	while(m--){
		int u,v,x;
		read(u);
		read(v);
		read(x);
		int y=min(a[u]^a[v]|x,query(u,v));
		printf("%lld\n",ans+(a[u]^a[v]|x)-y);
	}
	return 0;
}
