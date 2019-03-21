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
const int maxn=1e6 + 10;

int cnt1=0,cnt2=0,cnt3=0,n = 0,tmp = 0,a[maxn],b[maxn],c[maxn],ma=-inf,flag;
struct node{
	int sum;
	int x,y;
	
};
bool cmp (const node& a,const node& b){
	return a.sum < b.sum;
}

struct cmp1{
    bool operator () (const node &a,const node &b) const {
        return a.sum < b.sum;
    }
};

void solve(){
	vector<node> nod;
	int cnt = 0;
	sort(a,a+n);
	per(i,0,n-1){
		per(j,i+1,n-1){
			node tmp;
			tmp.sum = a[i] + a[j];
			tmp.x = a[i];tmp.y = a[j];
			nod.push_back(tmp);
		}
	}

	sort(nod.begin(),nod.end(),cmp);
	
	for(int i = n-1;i >= 0;--i){
		for(int j = n-1;j >= 0;--j){//之前WA是没有考虑负数的情况，不过这个j循环改一下就行了 
			if(j == i){
				continue;
			}
			int cd = a[i] - a[j];
			node tmp;tmp.sum = cd;
			vector<node>::iterator s = upper_bound(nod.begin(),nod.end(),tmp,cmp1());
			vector<node>::iterator e = lower_bound(nod.begin(),nod.end(),tmp,cmp1());
			if(s != e){
				vector<node>::iterator k = e;
				for(k = e;k != s;k++){
					if((*k).x != a[j] && (*k).y != a[j] && (*k).x != a[i] && (*k).y != a[i]){
						printf("%d\n",a[i]);
						return ;
					}
				}
			}
		}
	}
	printf("no solution\n");
	return ;
}
int main(){
	while(~scanf("%d",&n) && n){
		per(i,0,n-1){
			scanf("%d",&a[i]);
		} 
		solve();
	}
	
	return 0; 
}
