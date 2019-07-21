#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
int n = 0,m = 0;
LL d[maxn];
int head[maxn];
int cnt = 0;
bool vis[maxn];
struct node{
	int v;
	LL c;
	bool operator < (const node& x)const{
		return x.c + d[x.v] < this->c + d[this->v];
	}

};
struct Edge{
	int to,nex;
	LL w;
}e[2*maxn];//需要两倍的空间，每一次是有向边
void init(){
	cnt = 0;
	per(i,1,n){
		head[i] = -1;
		d[i] = INF;
		vis[i] = false;
	}
}
void add_edge(int from,int to,LL w){//链式前向星
	e[++cnt].to = to;
	e[cnt].w = w;
	e[cnt].nex = head[from];
	head[from] = cnt;
}

void dijikstra(int s){//求出每个点到终点的距离用于计算期望函数的大小
	//不需要记录非最短的路径长度，所以pq会根据是否访问来排序，未访问的为INF
	//且没有入栈，所以可实现优先选择最优的点
	priority_queue<node> pq;
	d[s] = 0;
	pq.push(node{s,0});
	while(!pq.empty()){
		node u = pq.top();
		pq.pop();
		if(vis[u.v]){
			continue;	
		}
		vis[u.v] = true;
		for(int i = head[u.v];i != -1;i = e[i].nex){
			Edge ed = e[i];
			if(d[ed.to] > d[u.v] + ed.w){
				d[ed.to] = d[u.v] + ed.w;
				pq.push(node{ed.to,0});
			}
		}
	}
}

LL A_start(int s,int k){
	--k;
	priority_queue<node> pq;
	pq.push(node{s,0});
	while(!pq.empty()){
		node u = pq.top();
		pq.pop();
		if(u.v == n){
			if(k > 0){
				--k;
			}else{
				return u.c;
			}
		}
		for(int i = head[u.v];i != -1;i = e[i].nex){
			Edge ed = e[i];
			pq.push(node{ed.to,ed.w + u.c});
			//记录从原点到该点的距离，比较时使用的是期望函数大小，还要+d[ed.to]
		}
	}
	return -1;
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
		dijikstra(n);
		// per(i,1,n){
		// 	printf("%lld ",d[i]);
		// }
		// puts("");
		printf("%lld\n",A_start(1,2));
	}	

	return 0;
}