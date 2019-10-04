#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 5e4 + 10;
// int n = 0,m = 0,q = 0
LL c[maxn],pre_sum[maxn];
int Q[maxn],head = 0,tail = 0;
LL dp[maxn];
LL n = 0,l= 0;
inline LL a(int k){
	return pre_sum[k] + k;
}
inline LL b(int k){
	return a(k) + l + 1;
}
inline LL X(int i){
	return b(i);
}
inline LL Y(int i){
	return dp[i] + b(i) * b(i);
}
inline double slope(int i,int j){
	return (Y(i) - Y(j))*1.0 / (X(i) - X(j));
}

int main(){
	// std::ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	while(~scanf("%lld %lld",&n,&l)){
		memset(pre_sum,0,sizeof(pre_sum));
		memset(dp,0,sizeof(dp));
		per(i,1,n){
			scanf("%lld",&c[i]);
			pre_sum[i] = pre_sum[i-1] + c[i]; 
		}
		per(i,1,n){
			while(head < tail && slope(Q[head+1],Q[head]) < 2*a(i)){ 
				//找到第一个斜率大于i点直线斜率的点
				++head;
			}
			//然后从这个点的状态转移到i,即为最优值
			dp[i] = dp[Q[head]] + (a(i) - b(Q[head])) * (a(i) - b(Q[head]));
			// printf("nihao %d\n",Q[head]); //
			while(head < tail && slope(Q[tail],Q[tail-1]) > slope(i,Q[tail-1])){
				//将i对应的坐标点加入到单调队列中，凸包
				--tail;
			}
			Q[++tail] = i;
		}
		printf("%lld\n",dp[n]);
	}

	return 0;
}
