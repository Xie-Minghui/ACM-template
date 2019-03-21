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
const int maxn = 1e2;
int n = 0,k = 0;
int mp[maxn+10][maxn+10];//要输出最大独立集，要使用两个数组 
int clique[maxn+10],temp[maxn+10];//clique存储最终结果，temp存储中间结果 
int ans = 0;
int dp[maxn+10]; 
bool is_clique(int end,int now){
	for(int i = 1;i < end;++i){
		//if(clique[i] == now || mp[clique[i]][now] == 0){
		//if(temp[i] == now || mp[temp[i]][now] == 0){
		if(mp[temp[i]][now] == 0){
			return false;
		}
	}
	return true;
}
void dfs(int depth,int now){
	if(depth + dp[now] <= ans){
		return ;
	}
	if(depth + (n - now) + 1 <= ans){
		return ;
	}
	for(int i = now;i <= n;++i){
		if(is_clique(depth+1,i)){
			temp[depth+1] = i;
			dfs(depth+1,i);
		}
	}
	if(ans < depth){//将temp复制给clique 
		ans = depth;
		memcpy(clique,temp,sizeof(temp));
	}
}
int main(){

	int T = 0;
	scanf("%d",&T);
	while(T--){
		fill(mp[0],mp[0]+(maxn+10)*(maxn+10),1);
		//memset(mp,0,sizeof(mp));
		scanf("%d %d",&n,&k);
		per(i,1,n){
			mp[i][i] = 0;//求补图的时候要把本身的自环也置0 
		}
		
		per(i,1,k){
			int x = 0,y = 0;
			scanf("%d %d",&x,&y);
			mp[x][y] = mp[y][x] = 0;//补图 
		}
		//ans = 0;
		//dfs(0,1);
		dp[n] = ans = 1;
		for(int i = n-1;i >= 1;--i){
			temp[1] = i;
			dfs(1,i+1);
			dp[i] = ans;
		}
		printf("%d\n",ans);
		per(i,1,ans){
			printf("%d%c",clique[i],i == ans ? '\n' : ' ');
		}
	}
	
	return 0;
}

