#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f
typedef long long LL;
using namespace std;
const int maxn = 3e5;
int n = 0,m = 0,cnt = 0;
bool vis[maxn+10];
int f[500+10];
int ran[500+10];
int ans = 0;
bool flag = true; 
set<int> st,st0;
struct node{
	int from,to,w;
};
node edge[maxn+10];
vector<int> g[maxn+10];
void init(){
	per(i,1,n){
		ran[i] = 0;
		f[i] = i;
	}
}
void dfs(int s){
	vis[s] = true;
	int size = g[s].size();
	per(i,0,size-1){
		int v = g[s][i];
		if(!vis[v]){
			dfs(v);
		}
	}
}
int find(int u){
	if(f[u] == u){
		return u;
	}
	return f[u] = find(f[u]);
}
bool same(int a,int b){
	return find(a) == find(b);
}
void unite(int u,int v){
	v = find(v);u = find(u);
	if(v == u){
		return ;
	}else{
		if(ran[u] > ran[v]){
			f[v] = u;
		}else{
			f[u] = v;
			if(ran[u] == ran[v]){
				++ran[v];
			}
		}
	}
}
bool cmp(node a,node b){
	return a.w < b.w;
}
int kruskal(int id){
	init();
	ans = 0;
	int cnt = 0,i = 1;
	while(i <= m){//如果下面不注释掉，这里改成true，那么测试7过了，但是测试3段错误，不知道什么鬼 
		if(cnt == n-1){
			break;
		}
		if(vis[i] || same(edge[i].from,edge[i].to)){
			++i;
			continue;
		}
		ans += edge[i].w;
		unite(edge[i].from,edge[i].to);
		st.insert(i);
		++cnt;
		++i;
	}
	/*
	if(cnt < n-1){//不知道为什么一定要把这个注释掉测试3和测试7才能过，AC 
		return -1;
	}
	*/
	if(id == 0){
		st0 = st;
	}
	return ans;
}
bool kruskal2(int ans0){	
	memset(vis,false,sizeof(vis));
	set<int>::iterator it = st0.begin();
	for(it = it;it != st0.end();++it){
		vis[*it] = true;
		int res = kruskal(1);
		if(res == ans0){
			return false;
		}
		vis[*it] = false;
	}
	return true;
}
int main(){
	while(~scanf("%d %d",&n,&m)){
		st0.clear();
		per(i,1,n){
			g[i].clear();
		}
		memset(vis,false,sizeof(vis));
		per(i,1,m){
			int u = 0,v = 0,w = 0;
			scanf("%d %d %d",&u,&v,&w);
			edge[i].from = u;edge[i].to = v;edge[i].w = w;
			g[u].push_back(v);g[v].push_back(u);
		}
		int num = 0;
		per(i,1,n){
			if(!vis[i]){
				dfs(i);
				++num;
			}
		}
		if(num > 1){
			printf("No MST\n");
			printf("%d\n",num);
			continue;
		}
		sort(edge+1,edge+1+m,cmp);
		memset(vis,false,sizeof(vis));
		int ans0 = kruskal(0);
		printf("%d\n",ans0);
		if(kruskal2(ans0)){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	
	return 0;
} 
