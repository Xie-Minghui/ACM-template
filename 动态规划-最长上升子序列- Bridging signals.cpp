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
const int maxn = 4e4;
int n = 0;
int a[maxn+10];
int dp[maxn+10];
void solve(){
	fill(dp,dp+n+10,INF);
	per(i,1,n){
		 *lower_bound(dp,dp+n,a[i]) = a[i];//最长上升子序列的n*log(n)的写法 
	}
	printf("%d\n",lower_bound(dp,dp+n,INF) - dp);
}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		solve();
	}
	
	return 0;
}




