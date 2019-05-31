#include<bits/stdc++.h>
#include<vector>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 1e5;
int n = 0,m = 0;
int s = 0,t = 0;
int dist[maxn+10];
bool vis[maxn+10];
int path[maxn+10];
struct edge{
	int to,w;
};
vector<edge> g[maxn+10];
void spfa(int s){
	memset(vis,false,sizeof(vis)); memset(dist,INF,sizeof(dist));
	memset(path,-1,sizeof(path));
	queue<int> que;
	dist[s] = 0;
	que.push(s);
	vis[s] = true;
	while(!que.empty()){
		int u = que.front(); que.pop();
		vis[u] = false;//出队，就false
		int size = g[u].size();
		per(i,0,size-1){
			edge& v = g[u][i];
			if(v.w > 0 && dist[v.to] > dist[u] + v.w){
				dist[v.to] = dist[u] + v.w;
				path[v.to] = u;
				if(!vis[v.to]){
					que.push(v.to);
					vis[v.to] = true;//入队就true
				}
			}
		}
	}
}
/*
//判断负环的条件：重新经过某个当前搜索栈中的结点
void spfa(int s){//spfa的dfs优化
	int size = g[s].size;
	per(i,0,size-1){
		edge& v = g[s][i];
		if(dist[v.to] > dist[s] + v.w){
			dist[v.to] = dist[s] + v.w;
			spfa(v.to);
		}
	}
}
*/
int main(){
	while(~scanf("%d %d",&n,&m)){
		per(i,1,m){
			int x = 0,y = 0,w = 0;
			scanf("%d %d %d",&x,&y,&w);
			g[x].push_back(edge{y,w}); g[y].push_back(edge{x,w});
		}
		spfa(s);
	}
	return 0;
}