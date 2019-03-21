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

#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
const int maxn = 3e5;
int n = 0,m = 0;
int ans = 0,maxid = 0;
int dis[maxn+10]; 
bool vis[maxn+10];
struct node{
	int to,val;
	node(int x,int y){
		to = x;val = y;
	} 
};
vector<node> vt[maxn+10];
/*
两次DFS，第一次找到离你选的起点（起点随意选择）最远的点（树的直径上的一点，
然后从最远的点DFS，找到最远的距离 
或者BFS都可以 
*/
void dfs(int s){
	vis[s] = true;
	int size = vt[s].size();
	for(int i = 0;i < size;++i){
		if(vis[vt[s][i].to] == false){
			dis[vt[s][i].to] = dis[s] + vt[s][i].val;
			if(dis[vt[s][i].to] > ans){
				maxid = vt[s][i].to;
				ans = dis[vt[s][i].to];
			}
			dfs(vt[s][i].to);
		}
	}
} 
void bfs(int s){
	vis[s] = true;
	queue<int> que;
	que.push(s);
	while(!que.empty()){
		int u = que.front();
		que.pop();
		int size = vt[u].size();
		for(int i = 0;i < size;++i){
			if(vis[vt[u][i].to] == false){
				dis[vt[u][i].to] = dis[u] + vt[u][i].val;
				vis[vt[u][i].to] = true;
				if(dis[vt[u][i].to] > ans){
					maxid = vt[u][i].to;
					ans = dis[vt[u][i].to];
				}
				que.push(vt[u][i].to);
			}
		}
	}
}
int main(){
	while(~scanf("%d %d",&n,&m)){
		memset(dis,0,sizeof(dis));memset(vis,false,sizeof(vis));
		per(i,1,m){
			int x = 0,y = 0,d = 0;
			char ch;
			scanf("%d %d %d %c",&x,&y,&d,&ch);
			vt[x].push_back(node(y,d));vt[y].push_back(node(x,d));
		}
		bfs(1);
		memset(dis,0,sizeof(dis));memset(vis,false,sizeof(vis));
		//cout << "nima " << maxid << endl;
		bfs(maxid);
		printf("%d\n",ans);
	}
	
	return 0;
}

