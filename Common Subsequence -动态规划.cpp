#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string> 
#include<cstring>
#include<set>
#define INF 0x7fffffff
using namespace std;
const int maxn = 1000 + 10;

string str1,str2;
int dp[maxn][maxn]; 
void solve(){
	int len1 = str1.size(),len2 = str2.size();
	
	for(int i = 0;i < len1;++i){
		for(int j = 0;j < len2;++j){	//注意边界问题 
			if(str1[i] == str2[j]){
				dp[i+1][j+1] = dp[i][j] + 1;
			}else{
				dp[i+1][j+1] = max( dp[i+1][j], dp[i][j+1]);
			}
		}
	}
	printf("%d\n",dp[len1][len2]);//注意是dp[len1][len2]，因为是dp[i+1][j+1] 
	
}
int main(){
	
	while(cin >> str1 >> str2){
		memset(dp,0,sizeof(dp));
		solve();	
	}

	return 0;
}
