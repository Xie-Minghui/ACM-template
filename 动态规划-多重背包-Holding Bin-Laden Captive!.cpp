#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 ;
bool dp[maxn+100];
int vis[maxn+100];
int num[4];
int val[4] = {0,1,2,5};
void solve(){
	fill(dp,dp+maxn+100,false);fill(vis,vis+maxn+100,false);
	dp[0] = true;
//	for(int i = 1;i <= 3;++i){
//	//	dp[val[i]] = (num[i] == 0)?false:true;
	//}
	for(int i = 1;i <= 3;++i){
		//dp[val[i]] = true;
		for(int k = 0;k <= num[i]-1;++k){
			for(int j = num[1]*1+num[2]*2+num[3]*5;j >= val[i];--j){
				dp[j] = dp[j] || (dp[j-val[i]] && dp[val[i]]);//自己做出来的DP 
			}
		}
	}
	for(int i = 0;i <= num[1]*1+num[2]*2+num[3]*5+1;++i){
		if(dp[i] == false){
			printf("%d\n",i);
			return ;
		}
	}
}
int main(){
	while(~scanf("%d %d %d",&num[1],&num[2],&num[3])){
		if(num[1] == 0 && num[2] == 0 && num[3] == 0){
			break;
		}
		solve();
	}
	
	
	return 0;
}
