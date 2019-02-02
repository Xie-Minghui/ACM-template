#include<bits/stdc++.h>
using namespace std;
const int maxn = 32768;
int dp[4][maxn + 100];//dp[i][j]表示使用前i种货币，凑出j元的方法数 
int n = 0;
void solve(){
	fill(dp[0],dp[0]+4*(maxn+100),0);
	for(int i = 0;i <= maxn;++i){
		dp[1][i] = 1;
	}
	for(int i = 1;i <= 3;++i){
		dp[i][0] = 1;
	}
	for(int i = 2;i <= 3;++i){
		for(int j = 1;j <= maxn;++j){
			dp[i][j] = dp[i-1][j] + (j >= i ? dp[i][j-i]:0);
		}
	}
}
int main(){
	solve();
	while(~scanf("%d",&n)){
		printf("%d\n",dp[3][n]);
	}
	return 0;
}
