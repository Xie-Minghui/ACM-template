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
const int maxn = 1e5;
int n = 0,m = 0;
struct node{
	int val,num;
};
node coin[maxn+10];
bool dp[maxn+10];//不能用二维数组，那样会MLE,要滚动降维
int cnt[maxn+10]; 
bool cmp(node a,node b){
	return a.val != b.val ? a.val < b.val : a.num < b.num;
}
void solve(){
	fill(dp,dp+(maxn+10),false);
	dp[0] = true;
	per(i,1,n){
		fill(cnt,cnt+maxn+10,0);
		per(j,0,m){//正序，因为是从更新后的状态退出后面的j的状态的 
			if(dp[j] == true){//不要跳过，否则cnt会+1,导致过快选择的i种卡超过数量限制 
				continue;//为了保证使用最少的第i种卡，凑出j 
			}
			if(j >= coin[i].val && dp[j-coin[i].val] && 
			cnt[j - coin[i].val] < coin[i].num){
				dp[j] = dp[j - coin[i].val];
				cnt[j] = cnt[j-coin[i].val] + 1;
			} 
		}
	}
	int ans = 0;
	per(i,1,m){
		ans += dp[i] ? 1 : 0; 
	}
	printf("%d\n",ans);
}
int main(){
	while(~scanf("%d %d",&n,&m) && ( m +n )){
		per(i,1,n){
			scanf("%d",&coin[i].val);
		}
		per(i,1,n){
			scanf("%d",&coin[i].num);
		}
		//sort(coin+1,coin+1+n,cmp);//排序是多余的 
		solve();
	}
	return 0;
}

