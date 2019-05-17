//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include <cmath>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
const int maxn = 5e4;
typedef long long LL;

int pos[maxn+10];//存储区间左端点的块的id
int cnt[maxn+10];//map存储i出现的个数
int a[maxn+10];//存储原始数据
int n = 0,m = 0,block = 0;
LL gcd(LL x,LL y){
	return (y == 0 ? x : gcd(y,x % y));
}
struct Query{
	int l,r,id;
	LL x,y;
	
	friend bool operator < (const Query &R,const Query &T){
        return pos[R.l]<pos[T.l] || (pos[R.l]==pos[T.l] && R.r<T.r);
    }
    /*
	bool operator < (const Query& rhs){//第一关键字：左端点的块id,第二关键字：右端点 
		return (pos[l] == pos[rhs.l] ? r < rhs.r : pos[l] < pos[rhs.l]);
	}
	*/
	void sim(){
		LL k = gcd(x,y);
		x /= k; y /= k;
	}
}q[maxn+10];

bool cmp_id(const Query& u,const Query& v){
	return u.id < v.id;
}
void mod(int p,LL& ans,int val){
	ans += (2*cnt[a[p]]*val + 1);
	cnt[a[p]] += val;
}
void init(){
	memset(cnt,0,sizeof(cnt));
	scanf("%d %d",&n,&m);
	per(i,1,n){
		scanf("%d",&a[i]);
	}
	block = (int)sqrt(n+0.5);
	per(i,1,n){//分块的编号 
		pos[i] = (i-1)/block + 1;
	}
	
	per(i,1,m){
		scanf("%d %d",&q[i].l,&q[i].r);
		q[i].id = i;
	}
	sort(q+1,q+1+m);
}

void solve(){
	LL ans = 0;
	int l = 1,r = 0;
	per(i,1,m){
		if(r < q[i].r){
			while((++r) < q[i].r){
				mod(r,ans,1);
			}	
			mod(r,ans,1);
		}
		if(l > q[i].l){
			while((--l) > q[i].l){
				mod(l,ans,1);
			}
			mod(l,ans,1);
		}
		if(r > q[i].r){
			while(r > q[i].r){
				mod(r--,ans,-1);
			}
			//mod(r,ans,-1);
		}
		if(l < q[i].l){
			while(l < q[i].l){
				mod(l++,ans,-1);
			}
			//mod(l,ans,-1);
		}
		if(q[i].r == q[i].l){
			q[i].x = 0; q[i].y = 1;
			continue;
		}
		q[i].x = ans - (q[i].r - q[i].l + 1);	q[i].y = 1ll*(q[i].r - q[i].l + 1) * (q[i].r - q[i].l);
		q[i].sim();
	}
	sort(q+1,q+1+m,cmp_id);
	per(i,1,m){
		printf("%lld/%lld\n",q[i].x,q[i].y);
	}
	
}

int main(){
	init();
	solve();
	
	return 0;
}
