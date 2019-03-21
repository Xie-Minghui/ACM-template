#include<iostream>
#include<cstdio> 
#include<algorithm>
#include<queue>
using namespace std;//POJ 3255
const int INF = 5e8; 
const int maxn = 5000 + 100;
int n = 0,r = 0;
struct edge{
	int to;
	int cost;
};
typedef pair<int,int> P;
vector<edge> G[maxn];//邻接表的正确姿势，结构体存储额外信息，存储边而不是点（这样便于写结构体） 
int dist[maxn],dist2[maxn];//最短距离与次短距离 
void solve(){
	fill(dist,dist + maxn,INF);
	fill(dist2,dist2 + maxn,INF);
	dist[1] = 0;
	priority_queue<P,vector<P>,greater<P> >que;
	que.push(P(1,0));
	
	while(!que.empty()){
		P p = que.top();
		que.pop();
		int v = p.first,d = p.second;//first是节点,second是对应的最短距离 
		if(dist2[v] < d){//如果条件成立，说明该点已经取到最短距离,d表示的是标记的距离，则不用更新了 
			continue;
			//关键的终止条件，遍历相邻的点，更新相邻点的dist和dist2,并且这些点会遍历到以前遍历过
			//的点并且会将他放入优先队列中，再次出对时就会判断的，就会将它排除
			//这里比较难以理解，最好自己举例理解 
			//比如从1->2->3->1 
			//这是比较两者的dist，就是上面的那个条件，如果成立，		
		}
		for(int i = 0;i < G[v].size();++i){//遍历该节点的邻接边 
			edge e = G[v][i];
			int d2 = e.cost + d;
			if(dist[e.to] > d2){//小于最短距离 
				swap(dist[e.to] , d2);
				que.push(P(e.to,dist[e.to]));
				dist2[e.to] = d2;
				que.push(P(e.to,dist2[e.to]));
				continue; 
			}
			if(dist2[e.to] > d2 && dist[e.to] < d2){//处于最短距离和次短距离之间 
				dist2[e.to] = d2;
				que.push(P(e.to,dist2[e.to]));
				continue;
			}
		}
	}
	printf("%d\n",dist2[n]);
}
int main(){
	while(scanf("%d %d",&n,&r) != EOF){
		for(int i = 0;i < r;++i){
			int a = 0,b = 0,c = 0;
			edge e;
			scanf("%d %d %d",&a,&b,&c);
			e.cost = c;
			e.to = b;G[a].push_back(e);
			e.to = a;G[b].push_back(e);
		}
		solve();
	}
	
	
	return 0;
}
