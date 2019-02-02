#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 6000 + 10;
int val[maxn];
vector<int> vt[maxn];
int dp[maxn][2];
int n = 0;
bool is_root[maxn];
void dfs(int u){
	dp[u][0] = 0;
	dp[u][1] = val[u];
	for(int i = 0;i < vt[u].size();++i){
		int v = vt[u][i];
		dfs(v);
		dp[u][1] += dp[v][0];
		dp[u][0] += max(dp[v][1],dp[v][0]);
	}
}
int main(){
	while(~scanf("%d",&n) && n){
		fill(is_root,is_root+n+1,true);
		for(int i = 1;i <= n;++i){
			scanf("%d",&val[i]);
		}
		for(int i = 1;i <= n-1;++i){
			int e = 0,s = 0;
			scanf("%d %d",&e,&s);
			vt[s].push_back(e);
			is_root[e] = false;
		}
		int root = -1;
		for(int i = 1;i <= n;++i){//根结点是唯一入度为0的节点 
			if(is_root[i]){
				root = i;
				break;
			}
		}
		dfs(root);
		printf("%d\n",max(dp[root][0],dp[root][1]));
	}
	
	
	return 0;
} 
