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

typedef long long int;

#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
#define mod 1000000007
const int maxn = 3e5;
int n = 0,m = 0;
int q_mul(int as,int m){
	int ans = 0;
	while(as > 0){
		if(as & 1){
			ans = (ans + m) % mod;
		}
		m = (m + m) % mod;
		as >>= 1;
	}
	return ans; 
}
int q_mod(int m,int n){
	int ans = 1;
	while(n > 0){
		if(n & 1){
			ans = q_mul(ans,m) % mod;
		}
		n >>= 1;
		m = q_mul(m,m) % mod;
	}
	return ans;
}
void solve(){
	printf("%lld\n",q_mod(m,n));// π”√%I64d£¨ª·PE 
}
int main(){
	while(~scanf("%I64d %I64d",&m,&n)){

		solve();
	}
	
	return 0;
}

