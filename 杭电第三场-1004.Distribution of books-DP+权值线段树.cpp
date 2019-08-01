#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e9
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 10;
const LL mod = (1e9 + 7);
int n = 0,k = 0;
LL a[maxn],pre[maxn],b[maxn];
int rk[maxn];//第i个数在线段树的位置
int num[maxn];//用于离散化，记录一个位置当前出现的次数
LL ans = INF;
struct STree{
	int l,r,f;
}st[maxn<<2];

void push_up(int rt){
	st[rt].f = max(st[rt<<1].f,st[rt<<1|1].f);
}
void build(int rt,int l,int r){
	st[rt].l = l;	st[rt].r = r;
	st[rt].f = -INF;
	if(l == r){
		// st[rt].f = -INF;
		return ;
	}
	int mid = (l + r) >> 1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	// push_up(rt);//我在上面将st[rt].f初始化了，所以这里不需要向上更新
}
int query(int rt,int l,int r){

	if(l <= st[rt].l && st[rt].r <= r){
		return st[rt].f;
	}
	int mid = (st[rt].l + st[rt].r) >> 1;
	int res = -INF;
	if(l <= mid){
		res = max(res,query(rt<<1,l,r));
	}
	if(r > mid){
		res = max(res,query(rt<<1|1,l,r));
	}
	return res;

	// if(l > st[rt<<1|1].r || r < st[rt<<1].l){//采用上面那种写法，这种写法会RE
	// 	return -INF;
	// }else if(l <= st[rt].l && st[rt].r <= r){
	// 	return st[rt].f;
	// }else 
	// if(r <= st[rt<<1].r){
	// 	return query(rt<<1,l,r);
	// }else  if(l > st[rt<<1|1].l){
	// 	return query(rt<<1|1,l,r);
	// }else{
	// 	return max(query(rt<<1,l,r),query(rt<<1|1,l,r));
	// }
}

void update(int rt,int pos,int val){
	if(st[rt].l == st[rt].r){
		st[rt].f = val;
		return ;
	}
	int mid = (st[rt].l + st[rt].r) >> 1;
	if(pos <= mid){
		update(rt<<1,pos,val);
	}else{
		update(rt<<1|1,pos,val);
	}
	push_up(rt);
}
bool check(LL mid){
	build(1,0,n);//从0开始建树，
	update(1,rk[0],0);//相当于动态规划里面的初始化,所以建树的时候要从0开始
	per(i,1,n){
		int pos = lower_bound(b,b+1+n,pre[i] - mid) - b;
		//在b数组中找满足区间和条件的位置区间，然后然后在这个区间寻找dp[i]的最大值
		//当前区间(1-i)的分快数，有些满足区间和条件的位置，可能在原来的pre数组i的后面
		//但由于它的顺序在i的后面，所以dp值为0，不对结果产生影响
		update(1,rk[i],query(1,pos,n) + 1);//动态规划，状态更新
	}
	if(query(1,0,n) >= k){//查询区间的分块数
		ans = min(ans,mid);
		return true;
	}
	return false;
}
void init(){
	ans = 1e18;
	memset(pre,0,sizeof(pre));
	memset(rk,0,sizeof(rk));
	memset(num,0,sizeof(num));
	memset(st,0,sizeof(st));
}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&k);
		init();
		per(i,1,n){
			scanf("%lld",&a[i]);
			pre[i] = pre[i-1] + a[i];
			b[i] = pre[i];
		}
		b[0] = 0;
		sort(b,b+1+n);   
		//将pre[i]离散化
		per(i,0,n){
			int pos = lower_bound(b,b+1+n,pre[i]) - b;
			rk[i] = pos + num[pos];//记录离散化之后前缀和在线段树数组中的对应位置
			++num[pos];
		}

		LL l = -1e15,r = 1e15;
		while(l <= r){//二分
			LL mid = (l + r)>>1;
			if(check(mid)){
				r = mid - 1;
			}else{
				l = mid + 1;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}