#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 1e5;
int n = 0,m = 0;
int s = 0,t = 0;
struct edge{
	int to,cap,rev;
};
vector<edge> g[maxn+10];
bool vis[maxn+10];
void add_edge(int from,int to,int cap){
	g[from].push_back(edge{to,cap,g[to].size()});//记录反向边在终点的位置，也就是下面to增加一条边的位置
	g[to].push_back(edge{from,0,g[from].size()-1});//反向边，后面是from的位置
}

int dfs(int s,int t,int f){
	if(s == t){
		return f;
	}
	vis[s] = true;
	int size = g[s].size();
	per(i,0,size-1){
		edge& e = g[s][i];
		if(!vis[e.to] && e.cap > 0){
			int d = dfs(e.to,t,min(f,e.cap));
			if(d > 0){
				e.cap -= d;
				g[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}
int max_match(int s,int t){
	int flow = 0;
	while(true){
		memset(vis,false,sizeof(vis));
		int f = dfs(s,t,INF);
		if(f == 0){
			return flow;
		}
		flow += f;
	}
	return -1;
}

int main(){
	while(~scanf("%d %d",&n,&m)){
		per(i,1,m){
			int x = 0,y = 0,z = 0;
			scanf("%d %d %d",&x,&y,&z);
			add_edge(x,y,z);
		}
		scanf("%d %d",&s,&t);
		int ans = max_match(s,t);
	}

	return 0;
}