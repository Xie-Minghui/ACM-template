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
const int maxn = 3e5;
int n = 0,m = 0;
/*
如果n=m+1,因为最多取m个，所以先拿的人拿多少个，后拿的人能全拿走。
由此可以总结出 取胜秘籍： n=(m+1)*r+s ?(r为任意自然数，s为小于等于m）。
那么先取者拿走s个物品，如果后取者拿走K（≤m）个，那么先取者肯定获胜。
总之，要保持给对手留下（m+1）的倍数，就能最后获胜。
于是，这道题解法就出来了，只要判断 n%(m+1)是否等于等于0。
等于0代表，无论怎么取，最后都会剩下<=m个，因此后取者将会获胜。
*/
int main(){
	
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		if((n % (m+1)) != 0){
			printf("first\n");
		}else{
			printf("second\n");
		}
	}
	
	return 0;
}

