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
const int maxn = 50;
int n = 0,m = 0;
int mp[maxn+10][maxn+10];
int clique[maxn+10];
int ans = 0;
int dp[maxn+10];//考虑dp来降低复杂度，我们可以从后往前枚举点，
//dp[i]表示第i个点和它之后点所能组成的最大值，那么最后一个点就是dp[n]=1
//因为只有一个点，
//然后遍历点，让改点加入后面的组合中看是否能加入和更新最大值！ 
bool is_clique(int end,int now){
	for(int i = 1;i < end;++i){
		if(mp[clique[i]][now] == 0){
			return false;
		}
	}
	return true;
}
void dfs(int depth,int now){
//	if(depth > ans){
	//	ans = depth;
	//}
	if(depth + dp[now] <= ans){//等号不能缺少，否则TLE，下面的剪枝也是一样的 
		return ;
	}
	if(depth + (n - now) + 1 <= ans){//剪枝，已经没有成功的希望了 
		return ;
	}
	for(int i = now;i <= n;++i){//按照递增的顺序剪枝 
		if(is_clique(depth+1,i)){//判断新点与原来的点是否联通 
			clique[depth+1] = i;//加入最大团集合 
			dfs(depth + 1 , i); 
		}
	}

	if(depth > ans){
		ans = depth;
	}
	
}
int main(){
	while(~scanf("%d",&n) && n){
		//memset(mp,0,sizeof(mp));//这个可以不初始化，后面的赋值会自动覆盖 
		per(i,1,n){
			per(j,1,n){
				scanf("%d",&mp[i][j]);
			}
		}
		memset(dp,0,sizeof(dp));
		ans = 1;//初始值为1 
		dp[n] = 1;
		for(int i = n-1;i >= 1;--i){
			clique[1] = i;//这种第一个答案已经确定的，可以直接写出来，优化一下 
			dfs(1,i+1);
			//dfs(0,i+1);//把前两行注释掉，用这行会WA 
			dp[i] = ans;
		}
		//dfs(0,1);
		printf("%d\n",ans);
	}
	
	return 0;
}

