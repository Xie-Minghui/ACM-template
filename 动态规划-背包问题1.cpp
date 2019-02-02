#include <iostream>
#include <cstring>
#define MAXN 1000
using namespace std;

int dp[MAXN][MAXN];
int w[MAXN] = {0, 2, 1, 3, 2};
int v[MAXN] = {0, 3, 2, 4, 2};
int W = 5, n = 4;

int solve(int n, int W) {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) { //i从1开始，因为i=0的值已经确定为0
        for (int j = 0; j <= W; j++) {
            if (j < w[i]) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            }
        }
    }
    return dp[n][W];
}

int main() {
	cout << solve(n, W) << endl;
	for(int i = 1;i <= n;++i){
		for(int j = 0;j <= W;++j){
			printf("%d%c",dp[i][j],(j == W) ? '\n':' ');
		}
	} 
  
  return 0;
}

