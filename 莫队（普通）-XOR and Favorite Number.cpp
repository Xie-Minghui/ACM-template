#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f3f
typedef long long LL;
using namespace std;
const int maxn = 1<<20;//1e6会wa,数据是神仙数 
int n = 0,m = 0,k = 0;
int a[maxn+10];
int block = 0;
int pos[maxn+10];
LL cnt[maxn+10];
struct Query{
	int l,r,id;
	
	friend bool operator < (const Query& u,const Query& v){
		return (pos[u.l] == pos[v.l] ? u.r < v.r : pos[u.l] < pos[v.l]);
	}
	/*
	bool operator < (const Query& rhs) const {
        if(pos[l] == pos[rhs.l]) return r < rhs.r;
        else return pos[l] < pos[rhs.l];
    } 
    */
}q[maxn+10];
void add(int p,LL& ans){
	ans += (cnt[a[p]^k]);
	++cnt[a[p]];
}
void del(int p,LL& ans){
	--cnt[a[p]];
	ans -= (cnt[a[p]^k]);
}
void init(){
	memset(cnt,0,sizeof(cnt));
	per(i,1,m){
		scanf("%d %d",&q[i].l,&q[i].r);
		q[i].id = i;
	}
	cnt[0] = 1;//
	sort(q+1,q+1+m);
}
void solve(){
	LL res[maxn+10] = {0};
	LL ans = 0;
	int l = 1,r = 0;
	per(i,1,m){	
		if(r < q[i].r){
			while((++r) < q[i].r){
				add(r,ans);
			}
			add(r,ans);
		}
		if(l > q[i].l){
			while((--l) > q[i].l){
				add(l-1,ans);
			}
			add(l-1,ans);
		}
		
		if(r > q[i].r){
			while(r > q[i].r){
				del(r--,ans);
			}
		}
		if(l < q[i].l){
			while(l < q[i].l){
				del(l-1,ans);
				l++;
			}
		}
		/*
		while (l<q[i].l)
        {
            del(l-1,ans);
            l++;
        }
        while (l>q[i].l)
        {
            l--;
            add(l-1,ans);
        }
        while (r<q[i].r)
        {
            r++;
            add(r,ans);
        }
        while (r>q[i].r)
        {
            del(r,ans);
            r--;
        }
        */
		res[q[i].id] = ans;
	}
	
	per(i,1,m){
		printf("%I64d\n",res[i]);
	}
}
int main(){
	
	while(~scanf("%d %d %d",&n,&m,&k)){
		block = int(sqrt(n+0.5));
		per(i,1,n){
			scanf("%d",&a[i]);
			a[i] ^= a[i-1];
			pos[i] = (i-1) / block + 1; 
			//pos[i] = i / block;
 		}
 		init();
		solve();
	}
	return 0;
}
