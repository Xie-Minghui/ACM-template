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
bool is_clique(int end,int now){
	for(int i = 1;i < end;++i){
		if(mp[clique[i]][now] == 0){
			return false;
		}
	}
	return true;
}
void dfs(int depth,int now){
	if(depth + (n - now) + 1 < ans){//剪枝，已经没有成功的希望了 
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
		memset(mp,0,sizeof(mp));
		per(i,1,n){
			per(j,1,n){
				scanf("%d",&mp[i][j]);
			}
		}
		ans = 0;
		dfs(0,1);
		printf("%d\n",ans);
	}
	
	return 0;
}

