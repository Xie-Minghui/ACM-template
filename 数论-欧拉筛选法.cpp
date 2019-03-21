#include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<fstream>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define pii pair<int, int>
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
//#define fill(a,b) fill(a,a+sizeof(a),b)
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define PER(i,x) for(auto i=x.begin();i!=x.end();i++)
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
typedef long long LL;
const double eps=1.0e-5;
const int maxn=1e6 + 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int cnt1=0,cnt2=0,cnt3=0,tmp = 0,a[maxn],b[maxn],c[maxn],ma=-inf,flag;
int n = 0; 
bool is_prime[maxn];
int prime[maxn];
int ouler(){
	fill(is_prime,is_prime+n,true);
	fill(prime,prime+n,0);
	int cnt = 0;
	int m = sqrt(n+0.5);
	per(i,2,m){
		if(is_prime[i]){
			prime[cnt++] = i;
		}
		for(int j = 0;j < cnt && i * prime[j] <= n;++j){
			is_prime[i * prime[j]] = false;
			if(i % prime[j] == 0){
				break;
			}
		}
	}
	return cnt;
} 

int main(){
	while(~scanf("%d",&n)){
		int cnt = ouler();
		printf("%d\n",cnt);
		per(i,0,cnt-1){
			printf("%d%c",prime[i],(i == cnt-1)?'\n':' ');
		}
	}
	
	return 0; 
}
