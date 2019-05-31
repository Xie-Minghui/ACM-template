#include<bits/stdc++.h>
#include<vector>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 1e5;
int n = 0,m = 0;
int s = 0,t = 0,f = 0;
struct edge{
	int to,cap,cost,rev;
};
vector<edge> g[maxn+10];
int prevv[maxn+10],preve[maxn+10],dist[maxn+10];
int h[maxn+10];//势
typedef pair<int,int> pii;
//向图中添加一条从from到to容量为cap费用为cost的边
void add_edge(int from,int to,int cap,int cost){
	g[from].push_back((edge){to,cap,cost,g[to].size()});
	g[to].push_back((edge){from,0,-cost,g[from].size()-1});
}
//求解从s到t流量为f的最小费用流
//如果不能再增广，则返回-1
int min_cost(int s,int t,int f){
	int res = 0;
	memset(h,0,sizeof(h));//初始化h
	while(f > 0){
		memset(dist,INF,sizeof(dist)); 
		dist[s] = 0;
		priority_queue<pii,vector<pii>,greater<pii> > pq;
		dist[s] = 0;
		pq.push(pii(0,s));
		while(!pq.empty()){
			pii u = pq.top(); pq.pop();
			int v = u.second;
			if(u.first > dist[v]){
				continue;
			}
			int size = g[v].size();
			per(i,0,size-1){
				edge& e = g[v][i];
				if(e.cap > 0 && dist[v] + e.cost + h[v] - h[e.to] < dist[e.to]){
					dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];//化负边为正边
					pq.push(pii(dist[e.to],e.to));
					prevv[e.to] = v; preve[e.to] = i;
				}
			}
		}

		if(dist[t] == INF){
			return -1;
		}
		per(i,1,n){
			h[i] += dist[i];//h(i+1)是f(i+1)的残存网络s到(i+1)的最短路
			//这个式子是对的，通过对dist[i]的不断迭代，得到，h[i] = s->i的费用总和
		}
		//沿s到t的最短路尽量增广
		int d = f;
		for(int v = t;v != s;v = prevv[v]){//沿着最短路找流
			d = min(d,g[prevv[v]][preve[v]].cap);
		}
		f -= d;
		res += (d * h[t]);//流*费用
		for(int v = t;v != s;v = prevv[v]){
			edge& e = g[prevv[v]][preve[v]];
			e.cap -= d;
			g[v][e.rev].cap += d;
		}
 	}
	return res;
}

int main(){
	while(~scanf("%d %d",&n,&m)){
		per(i,1,m){
			int x = 0,y = 0,z = 0,c = 0;
			scanf("%d %d %d %d",&x,&y,&z,&c);
			add_edge(x,y,z,c);
		}
		scanf("%d %d %d",&s,&t,&f);
		int ans = min_cost(s,t,f);
	}

	return 0;
}