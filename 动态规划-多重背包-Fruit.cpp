#include<bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
struct node{
	int mi,ma;
};
node num[maxn];
int n = 0,m = 0;
int dp[maxn][maxn];
void solve(){
	fill(dp[0],dp[0]+maxn*maxn,0);
	/*
	for(int i = 0;i <= n;++i){
		dp[i][0] = 1;
	}
	*/
	dp[0][0] = 1;
	int min_sum = 0,max_sum = 0;
	for(int i = 1;i <= n;++i){
		for(int j = min_sum + num[i].mi;j <= m && j <= max_sum + num[i].ma;++j){//j <= max_sum + num[i].maÊÇ´íµÄ 
			for(int k = num[i].mi;k <= num[i].ma && k <= j;++k){
				dp[i][j] += dp[i-1][j-k];
			}
		}
		min_sum += num[i].mi;max_sum += num[i].ma;
	}
	printf("%d\n",dp[n][m]);
}
int main(){
	while(~scanf("%d %d",&n,&m)){
		for(int i = 1;i <= n;++i){
			scanf("%d %d",&num[i].mi,&num[i].ma);
		}
		solve();
	}
	
	return 0;
}
