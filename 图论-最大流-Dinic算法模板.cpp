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
int iter[maxn+10],level[maxn+10];
bool vis[maxn+10];
void add_edge(int from,int to,int cap){
	g[from].push_back(edge{to,cap,g[to].size()});
	g[to].push_back(edge{from,0,g[from].size()-1});
}

void bfs(int s){
	memset(level,-1,sizeof(level));	memset(vis,false,sizeof(vis));

	queue<int> que;
	que.push(s);
	vis[s] = true;	level[s] = 0;
	while(!que.empty()){
		int u = que.front();
		que.pop();
		int size = g[u].size();
		per(i,0,size-1){
			edge& e = g[u][i];
			if(!vis[e.to] && e.cap > 0){
				que.push(e.to);
				level[e.to] = level[u] + 1;
				vis[e.to] = true;
			}
		}
	}
}

int dfs(int s,int t,int f){
	if(s == t){
		return f;
	}
	vis[s] = true;
	int size = g[s].size();
	for(int& i = iter[s];i < size;++i){
		edge& e = g[s][i];
		if(level[e.to] == (level[s] + 1) && e.cap > 0){
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
		int f = 0;
		bfs(s);//构建层次网络
		memset(vis,false,sizeof(vis));
		if(level[t] < 0){
			return flow;
		}
		memset(iter,0,sizeof(iter));
		while((f = dfs(s,t,INF)) > 0){
			flow += f;
		}
	}

	return 0;
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