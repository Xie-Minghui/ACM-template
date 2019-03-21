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
int x = 0,k = 0;
int a[maxn+10];
void solve(){
	bool win[maxn+10];
	win[0] = false;
	per(j,1,x){
		win[j] = false;
		per(i,1,k){
			win[j] |= ( (a[i] <= j) && (!win[j-a[k]]) );
		}
	}
	if(win[x]){
		puts("Alice");
	}else{
		puts("Bob");
	}
}
int main(){
	while(~scanf("%d %d",&x,&k)){
		per(i,1,k){
			scanf("%d",&a[i]);
		}
		solve();
	}
	
	return 0;
}

