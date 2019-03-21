#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

typedef long long LL;

//#define INF 0x3f3f3f3f	//对long long来说太小了 
#define INF LONG_LONG_MAX		//这才是正确的姿势 
#define PI acos(-1.0)
#define pii pair<int,LL>		//pair也要改成long long,这里不改成LL,会WA53 
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
const int maxn = 3e5;
int n = 0,m = 0,k = 0;
struct edge{
	int id,to,w;
	edge(int x,int y,int w1){
		id = x;to = y;w = w1;
	}
};
vector<edge> G[maxn+10];
bool vis[maxn+10];
LL d[maxn+10];
int father[maxn+10],faedge[maxn+10];
struct cmp{
	bool operator () (const pii a,const pii b){
		return a.second > b.second;
	}
};
/*
5 5 4
1 2 999999999
2 3 999999999
3 4 999999999
1 5 999999999
5 4 999999999
4
1 4 2 5
2 
1 4
WA 43
*/
void dijikstra(int s){
	fill(d,d+maxn+10,INF);
	fill(vis,vis+maxn+10,false);
	priority_queue<pii,vector<pii>,cmp> pq;
	d[s] = 0;
	father[s] = 1;
	pq.push(pii(s,0)); 
	while(!pq.empty()){
		pii p = pq.top();
		pq.pop();//别忘记删除节点 
		int u = p.first;
		if(vis[u] == true || d[u] < p.second){
			continue;
		}
		vis[u] = true;
		//per(i,0,G[u].size()-1){//这里面有宏定义错误，per(1,a,b)a <= b
		//而这里a > b ，就会导致程序崩掉 
		for(int i = 0;i < G[u].size();++i){
			edge v = G[u][i];
		
			if(d[v.to] > d[u] + v.w && vis[v.to] == false){
				d[v.to] = d[u] + v.w;
				
				father[v.to] = u;//记录父亲节点 
				faedge[v.to] = v.id;//记录父亲边 
				pq.push(pii(v.to,d[v.to]));
			}
		}
	}
}
vector<int> son[maxn+10];
vector<int> ans;
void bfs(int s){
	queue<int> que;
	int cnt = 0;
	que.push(s);
	while(!que.empty() && cnt <= k){
		int u = que.front();
		que.pop();
		//per(i,0,son[u].size()-1){
		for(int i = 0;i < son[u].size();++i){
			if(cnt >= k){
				break;
			}
			int v = son[u][i];
			ans.push_back(faedge[v]);
			que.push(v);
			cnt++;
		}
	}
}
int main(){
	while(~scanf("%d %d %d",&n,&m,&k)){
		//ans.clear();
		int x,y,w;
		per(i,1,m){
			scanf("%d %d %d",&x,&y,&w);
			G[x].push_back(edge(i,y,w));
			G[y].push_back(edge(i,x,w));
		} 
		dijikstra(1);

		per(i,2,n){//将最短路径树的父亲关系转化为儿子关系 
			son[father[i]].push_back(i);
		}
		
		bfs(1);
		printf("%d\n",ans.size());
		//per(i,0,ans.size()-1){//这里面有宏定义错误，per(1,a,b)a <= b
		//而这里a > b ，就会导致程序崩掉 
		for(int i = 0;i < ans.size();++i){
			printf("%d%c",ans[i],i == (ans.size()-1) ? '\n' : ' ');
		}
	}
	return 0;
}

