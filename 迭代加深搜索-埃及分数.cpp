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
const int maxn = 1e3;
LL a = 0,b = 0;
LL ans[maxn+10],v[maxn+10];//aa,bb要LL，否则枚举时会爆int 
int maxd = 0;
LL gcd(LL x,LL y){
	return y == 0 ? x : gcd(y,x%y);
} 
LL get_first(LL x,LL y){
	return ceil(y*1.0/x);
}
bool better(int d){
	for(int i = d;i >= 0;--i){
		if(v[i] != ans[i]){
			return ans[i] == -1 || v[i] < ans[i];
		}
	}
	return false;
}
bool dfs(int d,LL from,LL aa,LL bb){
	if(d == maxd){
		if(bb % aa != 0){//必须是埃及分数 

			return false;
		}
		v[d] = bb /aa;
		if(better(d)){
			memcpy(ans,v,(d+1)*sizeof(LL));
		} 
		return true;
	}
	bool ok = false;
	from = max(get_first(aa,bb),from);
	for(int i = from;;++i){
		//剪枝;如果剩下的(maxd - d + 1)个分数全是1/i,加起来仍然不超过aa/bb，则无解，且更小的i也无解，退出循环 
		//最理想化剪枝 
		if(aa * i >= bb * (maxd - d + 1)){//bb写成b去了 
			break;
		}
		v[d] = i;
		LL b2 = i * bb;
		LL a2 = aa*i - bb;
		int g = gcd(a2,b2);
		if(dfs(d+1,i+1,a2/g,b2/g)){
			ok = true;
		}
	} 
	return ok;
}
int main(){
	//std::ios::sync_with_stdio(false);
	int kase = 0;
	while(~scanf("%I64d %I64d",&a,&b)){
		bool ok = false;
		for(maxd = 1;;++maxd){
			memset(ans,-1,sizeof(ans));
			if(dfs(0,get_first(a,b),a,b)){
				ok = true;
				break;
			}
		}
		printf("Case %d: %I64d/%I64d=",++kase,a,b);
		printf("1/%I64d",ans[0]);
		for(int i = 1;i <= maxd;++i){
			printf("+1/%I64d",ans[i]);
		}
		printf("\n");
	}
	
	
	return 0;
}

