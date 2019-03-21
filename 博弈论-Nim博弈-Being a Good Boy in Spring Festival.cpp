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
const int maxn = 1e2;
int n = 0,m = 0;
int a[maxn+10];

int main(){
	while(~scanf("%d",&n) && (n != 0)){
		int sum = 0,cnt = 0;
		for(int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
			sum ^= a[i];
		}
		for(int i = 1;i <= n;++i){
			if((sum ^ a[i]) < a[i]){
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	
	return 0;
}

