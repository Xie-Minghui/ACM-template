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
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define PER(i,x) for(auto i=x.begin();i!=x.end();i++)
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
typedef long long LL;
const double eps=1.0e-5;
const int maxn=15000000 + 5;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
//int cnt1=0,cnt2=0,cnt3=0,tmp = 0,a[maxn],b[maxn],c[maxn],ma=-inf,flag;

int n = 0; 
int prime[maxn];
int a[maxn];
int u[maxn],s[maxn];
int gcd(int x,int y){
	return y == 0 ? x : gcd(y,x%y);
}
void ouler(){
	fill(u,u+maxn,0);
	fill(prime,prime+maxn,0);
	int cnt = 0;
	per(i,2,maxn-1){
		if(u[i] == 0){
			u[i] = prime[cnt++] = i;
		} 
		for(int j = 0;j < cnt && i * prime[j] < maxn;++j){
			u[i * prime[j]] = prime[j];
			if(i % prime[j] == 0){
				break;
			}
		}
	}
}
int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	ouler();
	while(~scanf("%d",&n)){
		fill(s,s+maxn,0);
		int g = 0,x = 0;
		per(i,1,n){
			scanf("%d",&a[i]);
			g = gcd(max(g,a[i]),min(g,a[i]));//求所有数的最大公因数 
		}
		
		per(i,1,n){
			for(int j = a[i]/g;j > 1;){//先除以最大公约数 
				s[x = u[j]]++;	//除以相应的素数，+1，同一个数对于同一个素数只加一次 
				while(u[j] == x){//将这个素数除尽 
					j /= u[j];
				}
			}
		}
		
		/*
		per(i,1,n){
			for(int j = a[i]/g;j > 1;){//先除以最大公约数 
	//除以相应的素数，+1，同一个数对于同一个素数只加一次 
	//将这个素数除尽 
				for(++s[x = u[j]];u[j] == x;){
					j /= u[j];
				}		
			
			}
		}
		*/
		int ans = 0;
		per(i,1,maxn){
			ans = max(ans,s[i]);//取一个素数能整除最多的数的数 
		}
		printf("%d\n",ans == 0 ? -1 : n - ans);
	}
	
	return 0; 
}
