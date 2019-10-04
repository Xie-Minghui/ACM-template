#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
// const int maxn = 3e5 + 10;
int n = 0,k = 0,m = 0,q = 0;
const int maxn = 5e3 + 10;
const int maxk = 2e3 + 10;
LL dp[maxk][maxn];
LL pre_w[maxn];
LL sum = 0;
int Q[maxn],head = 0,tail = 0;
struct node{
	LL h,w;
};
node a[maxn];
bool cmp(node no1,node no2){ //高度从大到小排序
	return no1.h > no2.h; //这里不能有等号，否则会WA
}
long double slope(int k1,int k2,int i){
	return (long double)(dp[i-1][k1] - dp[i-1][k2]) * 1.0 / (pre_w[k1] - pre_w[k2]);
}
void solve(){
	
}
void init(){
	memset(dp,0,sizeof(dp));
	memset(pre_w,0,sizeof(pre_w));
	sum = 0;
}
int main(){
	// std::ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	while(~scanf("%d %d",&n,&k)){
		init();
		per(i,1,n){
			scanf("%lld %lld",&a[i].w,&a[i].h);
			sum += (a[i].w * a[i].h);
		}
		sort(a+1,a+1+n,cmp);
		per(i,1,n){
			pre_w[i] = pre_w[i-1] + a[i].w;
		}
		per(i,1,k){
			head = tail = 0;
			per(j,1,n){
				while(head < tail && slope(Q[head],Q[head+1],i) > a[j].h){
					++head;
				}
				dp[i][j] = dp[i-1][Q[head]] + a[j].h * (pre_w[j] - pre_w[Q[head]]);
				while(head < tail && slope(Q[tail],Q[tail-1],i) < slope(Q[tail],j,i)){
					--tail;
				}
				Q[++tail] = j;
			}
		}
		printf("%lld\n",sum - dp[k][n]);
		// solve();
	}

	return 0;
}
