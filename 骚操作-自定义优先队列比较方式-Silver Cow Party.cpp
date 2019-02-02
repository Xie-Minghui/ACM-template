#include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<fstream>
#include<cstdlib>
#include<algorithm>

using namespace std;

//typedef  pair<int, int> pii;
#define pii pair<int,int>
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define PER(i,x) for(auto i=x.begin();i!=x.end();i++)
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
typedef long long LL;
const double eps=1.0e-5;
const int maxn=1e3 + 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n = 0,m = 0,x = 0; 
int adj[maxn][maxn];
int d1[maxn],d2[maxn];
bool used[maxn];
struct cmp{//cmp类型，然后重新定义比较方式 
	bool operator()(const pii a,const pii b){
		return a.second > b.second;//second小值优先 
	}
};
void dijikstra(int s,int* dist){
	fill(used,used+maxn,false);
	fill(dist,dist+maxn,INF);
	priority_queue<pii,vector<pii>,cmp > que;
	dist[s] = 0;//初始值设置 
	que.push(pii(s,0));
	while(!que.empty()){
		pii p = que.top();que.pop();//从未访问过的节点中选取距离远点最短的(更新距离的那些点） 
		int u = p.first,d = p.second;
		if(dist[u] < d || used[u] == true){//如果一直最小值比d小，或者已经访问过，就直接跳过 
			continue;
		}
		used[u] = true;
		for(int i = 1;i <= n;++i){//更新周围点的最短路径 
			if(dist[i] > dist[u] + adj[u][i] && used[i] == false){
				dist[i] = dist[u] + adj[u][i];
				que.push(pii(i,dist[i]));
			}
		}
	} 
}
int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	while(~scanf("%d %d %d",&n,&m,&x)){
		fill(adj[0],adj[0] + maxn*maxn,INF);
		
		per(i,1,m){
			int a = 0,b = 0,t = 0;
			scanf("%d %d %d",&a,&b,&t);
			adj[a][b] = t;
		}
		
		dijikstra(x,d1);
		per(i,1,n){//路径反转 
			per(j,i+1,n){//j要从i+1开始，否则反转两次，相当于没变化
				swap(adj[i][j],adj[j][i]);
			}
		}
	
		dijikstra(x,d2);
		int maxv = 0;
		per(i,1,n){
			if(d1[i] != INF && d2[i] != INF){//必须加上这个判断条件 
				maxv = max(maxv , d1[i] + d2[i]);
			}
		}
		printf("%d\n",maxv);
	}
	
	return 0; 
}
