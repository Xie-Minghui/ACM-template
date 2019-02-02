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
const int maxn = 1e6;
int n = 0,m = 0;
int dp[maxn + 10];
const LL mod = 1e9;//取后面的9位数是mod1e9而不是1e10，这里我WA了一上午 
void solve(){//完全背包 
	fill(dp,dp+maxn+10,0);
	dp[0] = 1;
	int tmp = 1; 
	per(i,1,21){
		if(n < tmp){
			break;
		}
		per(j,tmp,n){	
			dp[j] = (dp[j] + dp[j-tmp]) % mod; 
		}
		tmp <<= 1;
	}
	printf("%d\n",dp[n]);
}
int main(){
	while(~scanf("%d",&n)){
		solve();
	}
	
	
	return 0;
}

