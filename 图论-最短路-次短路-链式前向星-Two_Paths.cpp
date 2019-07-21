#include<bits/stdc++.h>
// #include<iostream>
// #include<cstdio>
// #include<vector>
// #include<cstring>
using namespace std;
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
const int maxn = 2e5 + 10;
typedef long long LL;
#define INF 1e18
int n = 0,m = 0;
int cnt = 0,head[maxn];
LL d1[maxn],d2[maxn];
bool vis[maxn];
struct Edge{
	int to;
	LL w;
	int nex;
	bool operator < (const Edge& ed)const{
		return ed.w < this->w;//注意符号的顺序
	}
	Edge(){}
	Edge(int to1,LL w1,int nex1){
		to = to1; nex = nex1; w = w1;
	}
};
Edge e[maxn];
void init(){
	cnt = 0;
	per(i,0,n){
		head[i] = -1;
		d1[i] = d2[i] = INF;
	}
}

void add_edge(int from,int to,LL w){
	e[++cnt].to = to;
	e[cnt].w = w;
	e[cnt].nex = head[from];
	head[from]  = cnt;
}

void dijikstra(int s){
	// memset(vis,false,sizeof(vis));
	d1[s] = 0;
	priority_queue<Edge> pq;
	Edge tmp;	
	tmp.to = s; tmp.w= 0;
	pq.push(tmp);
	// Edge Next;
	while(!pq.empty()){
		Edge u = pq.top();
		pq.pop();
		if(d2[u.to] < u.w){	
			continue;
		}
		for(int i = head[u.to];i != -1;i = e[i].nex){
			Edge ed = e[i];
			LL way = u.w + ed.w;//	
			if(d1[ed.to] > way){//最短路
				swap(d1[ed.to],way);
				pq.push(Edge{ed.to,d1[ed.to],ed.nex});
			}
			if(d2[ed.to] > way && d1[ed.to] < way){//记录次短路
				d2[ed.to] = way;
				pq.push(Edge{ed.to,d2[ed.to],ed.nex});
			}
		}
	}

	printf("%lld\n",d2[n]);
}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		init();
		per(i,1,m){
			int x = 0,y = 0;
			LL w = 0;
			scanf("%d %d %lld",&x,&y,&w);
			add_edge(x,y,w); add_edge(y,x,w);
		}
		dijikstra(1);
	}

	return 0;
}