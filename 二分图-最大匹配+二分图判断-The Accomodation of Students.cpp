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
const int maxn = 2e2;
int n = 0,m = 0;
vector<int> mp[maxn+10];
bool vis[maxn+10];
int color[maxn+10];
int cntx = 0,cnty = 0;
int cx[maxn+10],cy[maxn+10];
int px[maxn+10],py[maxn+10];
bool bfs(int s){
	memset(vis,false,sizeof(vis));
	queue<int> que;
	que.push(s);
	vis[s] = true;
	color[s] = 1;
	while(!que.empty()){
		int u = que.front();que.pop();
		int size = mp[u].size();
		for(int i = 0;i < size;++i){
			if(!vis[mp[u][i]]){
				vis[mp[u][i]] = true;
				color[mp[u][i]] = !color[u];
				que.push(mp[u][i]);
			}
			if(color[mp[u][i]] == color[u]){
				return false;
			}
		}
	}
	return true;
}
int path(int u){
	int size = mp[u].size();
	for(int i = 0;i < size;++i){
		if(!vis[mp[u][i]]){
			vis[mp[u][i]] = true;
			if(py[mp[u][i]] == -1 || path(py[mp[u][i]])){
				px[u] = mp[u][i];py[mp[u][i]] = u;
				return 1;
			}
		}
	}
	return 0;
}
int max_match(){
	memset(px,-1,sizeof(px));memset(py,-1,sizeof(py));
	int sum = 0;
	for(int i = 1;i <= cntx;++i){
		if(px[cx[i]] == -1){
			memset(vis,false,sizeof(vis));
			sum += path(cx[i]);
		}
	}
	return sum;
}
int main(){
	while(~scanf("%d %d",&n,&m)){
		per(i,1,n){
			mp[i].clear();
		}
		per(i,1,m){
			int x = 0,y = 0;
			scanf("%d %d",&x,&y);
			mp[x].push_back(y);mp[y].push_back(x);
		}
		memset(color,-1,sizeof(color));//color如果只是bool类型，则无法区分未访问的
		//连通分支和颜色相反的，有3种状态：未访问，1，0 
		bool flag = true;
		per(i,1,n){
			if(color[i] == -1){
				if(bfs(i) == false){
					flag = false;
					break;
				}
			}
		}
		if(flag == false){
			printf("No\n");
			continue;
		}
		//cout << "jaja "<< endl;
		cntx = 0,cnty = 0;
		per(i,1,n){
			if(color[i] == 1){
				cx[++cntx] = i;
			}else{
				cy[++cnty] = i;
			}
		}
		int sum = max_match();
		printf("%d\n",sum);
	}
	
	return 0;
}

