#include<iostream>
#include<cstdio> 
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 5e4 + 10;
int n = 0,m = 0,r = 0;
struct edge{
	int u,v,d;
};
int rak[maxn],par[maxn];
edge es[maxn];
bool cmp(edge a,edge b){
	return a.d < b.d;
}
void init(int n){
	for(int i = 0;i < n;++i){
		par[i] = i;
		rak[i] = 0;
	}
}
int find(int x){
	if(par[x] == x){//ÕÒµ½¸ùÁË 
		return x;
	}else{
		return find(par[x]);
	}
}
void unite(int x,int y){
	x = find(x);y = find(y);
	if(x == y){
		return ;
	}
	if(rak[x] < rak[y]){
		par[x] = y;
	}else{
		par[y] = x;
		if(rak[x] == rak[y]){
			rak[x] += 1;
		}
	}
}
bool same(int x,int y){
	return find(x) == find(y);
}
void solve(){
	//int V = n + m;
	int E = r;
	init(n + m);
	int res = 0;
	for(int i = 0;i < E;++i){
		edge e = es[i];
		if(!same(e.u,e.v)){
			unite(e.u,e.v);
			res += e.d;
		}
	}
	int ans = 1e4 * (n + m) + res;
	printf("%d\n",ans);
}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&n,&m,&r);
		for(int i = 0;i < r;++i){
			scanf("%d %d %d",&es[i].u,&es[i].v,&es[i].d);
			es[i].d = -es[i].d;
			es[i].v += n;// 
		}
		sort(es,es + r,cmp);
		solve();
	}
	
	return 0;
} 
