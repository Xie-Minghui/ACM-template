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
const int ma = 2e5;
const int mod = 1e8 + 7;
int n = 0,m = 0;
LL a[300+10];
LL dp[2][2*ma+1000];
/*
dp[i][j]，前面的i只有0,1两种取值，使用了滚动数组，保存了当前状态，和上一层状态
j表示当前的分数。
这里要处负数的情况，将原来的区间[-ma,ma]变成[0,2*ma],其中如果把正数映射到[0,ma]那么j-a[i]，
可能会出现负数，所以把原来的正数映射到[ma,2*ma],这样就处理了负数的情况 
*/
int main(){
	while(~scanf("%d",&n)){
		per(i,1,n){
			scanf("%lld",&a[i]);
		}
		memset(dp,0,sizeof(dp));
		dp[0][ma] = 1;
		per(i,1,n){
			int num = i&1;
			memset(dp[num],0,sizeof(dp[num]));
			per(j,2000,2*ma){
				if(j ==  ma + 666){
					dp[num][j] = 0;
				}else{
					dp[num][j] = (dp[num^1][2*ma-j] +dp[num^1][j-a[i]]) % mod;	
				}
			}
			
		}
		printf("%lld\n",dp[n&1][ma-666]);
	}
	return 0;
}

