#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b); ++i)
using namespace std;
const int maxn=1e3;
int n = 0,m = 0,h = 0;
int r[maxn+10][maxn+10];
int dp[100][100][100];
int vis[maxn+10][maxn+10];
int dfs(int x,int y,int hn,bool sta){//到达x,y,横着走了hn次，sta是否是第一次到达该行 
	if(x == m && hn == h){//递归终止条件 
		return (vis[x][y] == 0) ? r[x][y] : 0;
	}
	if(sta &&dp[x][y][hn] != 0){//sta表示第一次到达这一行，那么可以返回原来计算的结果，这有点类似数位DP 
		return dp[x][y][hn];
	}
	int bonus = (vis[x][y] == 0 ) ? r[x][y] : 0;//只有第一次碰到，才有奖金，所以vis是一个整数数组，bool数组不够用 
	++vis[x][y];
	int res = 0;
	if(hn + 1 <= h){
		if(y-1 >= 1){
			res = dfs(x,y-1,hn+1,false);	
		}
		if(y+1 <= n){
			res = max(res,dfs(x,y+1,hn+1,false));	
		}
	}
	if(x != m){
		if(y - 1 >= 1){
			res = max(res,dfs(x+1,y-1,hn,true));	
		}
		res = max(res,dfs(x+1,y,hn,true));
		if(y+1 <= n){
			res = max(res,dfs(x+1,y+1,hn,true));
		}
	}
	if(sta){//类似于数位DP，如果是第一次到达该行的值，那么就记录下来，其他的会有冲突 
		dp[x][y][hn] = max(res + bonus,dp[x][y][hn]);
	}
	--vis[x][y];
	return res + bonus;
}
int main(){
	//std::ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	while(~scanf("%d %d %d",&m,&n,&h)){
		per(i,1,m){
			per(j,1,n){
				scanf("%d",&r[i][j]); 
			}
		}
		memset(dp,0,sizeof(dp)); memset(vis,0,sizeof(vis));
		int maxv = -1,loc = 0;
		per(i,1,n){
			int ans = dfs(1,i,0,true);
			if(ans > maxv){
				loc = i;
				maxv = ans;
			}
		}
		printf("The starting position is %d, The maximum bonus you can get is %d\n",loc,maxv);
	}
	return 0;
}
