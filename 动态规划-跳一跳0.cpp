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
const int maxn = 30;
int n = 0,m = 0,h = 0;
int dp[maxn*2][maxn][maxn][2];
int r[maxn*2][maxn];
void max_bonus(){
	map<int,int> mp;
	mp[0] = 1; mp[1] = -1;
	per(i,1,2*m-1){
		per(k,0,h){//h循环必须放在j外面，因为由i&1==1的状态转移方程可知，
		//dp[x][y][h][0] = max(...,dp[x][y+1][h-1][0]),
		//y要调用y+1的结果，所以这个时候发现h调用的是h-1,所以h>y,h-1的时候计算出所有的y 
			per(dic,0,1){//这层循环可以放在这里，也可以放在j里面 
				per(j,1,n){
					if(i & 1){
						dp[i][j][k][dic] = max(dp[i-1][j][k][0],max(dp[i-1][j][k][1],(k > 0 ? dp[i][j+mp[dic]][k-1][dic] : 0))) + r[i][j];
						//dp[i][j][k][0] = max(dp[i-1][j][k][0],max(dp[i-1][j][k][1],(k > 0 ? dp[i][j+1][k-1][0] : 0)) + r[i][j];
						//dp[i][j][k][1] = max(dp[i-1][j][k][0],max(dp[i-1][j][k][1],(k > 0 ? dp[i][j+1][k-1][1] : 0)) + r[i][j];	
					}else{
						per(p,0,1){
							dp[i][j][k][dic] = max(dp[i][j][k][dic],max(dp[i-1][j-1][k][p],max(dp[i-1][j][k][p],dp[i-1][j+1][k][p])) + r[i][j]) ;
						}
						dp[i][j][k][dic] = max(dp[i][j][k][dic],(k > 0 ? dp[i][j+mp[dic]][k-1][dic]: 0) + r[i][j]) ;
					}
				}	
			}	
		}
	}
	per(i,1,m){
		per(j,1,n){
			int maxl = 0,maxr = 0;
			per(k,0,h){
				maxl = max(maxl,dp[i][j][k][0]);
				maxr = max(maxr,dp[i][j][k][1]);
			}
			printf("%d(%d) ",maxl,maxr);
		}
		printf("\n");
	}
	int maxv = -1,loc = 0;
	per(j,1,n){
		//per(k,0,h){//最大值一定是在k == h处取得 
			per(dic,0,1){
				if(dp[2*m-1][j][h][dic] >= maxv){
					maxv = dp[2*m-1][j][h][dic];
					loc = j;
				}
			}
		//}
	}
	printf("%d %d\n",loc,maxv);
}
int main(){
	while(~scanf("%d %d %d",&m,&n,&h)){
		memset(dp,0,sizeof(dp));  memset(r,0,sizeof(r));
		per(i,1,m){
			per(j,1,n){
				scanf("%d",&r[i*2-1][j]);
			}
		}
		max_bonus();
	}
	
	return 0;
}
/*
test:
3 3 3
1 2 3 
4 5 6
9 8 7

answer:3 38

1 3 4
1 2 3

6
*/ 

