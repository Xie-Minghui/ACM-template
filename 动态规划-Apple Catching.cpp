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
const int maxn = 1e3;
int t = 0,w = 0;
int a[maxn+10];
//像这种多阶段决策阶段，要用DP，否则考虑细节很复杂 
int dp[maxn+10][30+5];//dp[i][j]表示i分钟走了j次所吃到的最大的苹果的数目 
void solve(){
	fill(dp[0],dp[0]+(maxn+10)*(30+5),0);
	dp[1][0] = ((a[1] == 1) ? 1 : 0);//初始化 
	dp[1][1] = ((a[1] == 1) ? 0 : 1);
	per(i,2,t){
		per(j,0,w){
			dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]);
			if(a[i] == ((j % 2 == 0) ? 1 : 2)){//判断当前树有没有苹果 
				dp[i][j]++;
			}
		}
	}
	int maxv = 0;
	per(i,0,w){
		maxv = max(maxv , dp[t][i]);
	}
	printf("%d\n",maxv);
}
int main(){
	while(~scanf("%d %d",&t,&w)){
		per(i,1,t){
			scanf("%d",&a[i]);
		}
		solve();
	}
	
	
	return 0;
}

