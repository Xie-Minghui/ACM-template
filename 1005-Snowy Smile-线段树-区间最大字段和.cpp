#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
typedef long long LL;
const int maxn = 2e3 + 10;
int n = 0;
int nx = 0,ny = 0;
struct node{
	int x,y;
	LL w;
	bool operator < (const node& no)const{
		return this->y == no.y ? this->x < no.x : this->y < no.y;
	}
}p[maxn];
int xx[maxn],yy[maxn];
struct Tree{
	// int l,r;//这里不需要记录每个节点的l,r,因为没有建树，或者可以在clr的同时建树。但是感觉没必要，有点浪费内存
	LL sum,max_sum,max_pre,max_post;
	//分别记录 区间和,区间最大子段和,区间最大前缀和,区间最大后缀和
}tr[maxn<<2];
void clr(int rt,int l,int r){
	tr[rt].sum = tr[rt].max_sum = tr[rt].max_pre = tr[rt].max_post = 0;
	if(l == r){
		return ;
	}
	int mid = (l+r) >> 1;
	clr(rt<<1,l,mid);
	clr(rt<<1|1,mid+1,r);
}
void push_up(int rt){
	int ls = rt<<1,rs = rt<<1|1;
	tr[rt].sum = tr[ls].sum + tr[rs].sum;//将rs写成了rt
	tr[rt].max_sum = max(max(tr[ls].max_sum,tr[rs].max_sum),tr[ls].max_post + tr[rs].max_pre);
	tr[rt].max_pre = max(tr[ls].max_pre,tr[ls].sum + tr[rs].max_pre);
	tr[rt].max_post = max(tr[rs].max_post,tr[ls].max_post + tr[rs].sum);
}
void update(int rt,int l,int r,int pos,LL w){//单点更新
	if(l == r){
		tr[rt].max_sum = tr[rt].max_pre = tr[rt].max_post = (tr[rt].sum += w);
		return ;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid){
		update(rt<<1,l,mid,pos,w);
	}else{
		update(rt<<1|1,mid+1,r,pos,w);
	}
	push_up(rt);
}
void discret(){//离散化
	sort(xx+1,xx+1+n); sort(yy+1,yy+1+n);
	nx = unique(xx+1,xx+1+n) - (xx+1);
	ny = unique(yy+1,yy+1+n) - (yy+1);
	per(i,1,n){
		p[i].x = lower_bound(xx+1,xx+1+nx,p[i].x) - xx;
		p[i].y = lower_bound(yy+1,yy+1+ny,p[i].y) - yy;
	}
	sort(p+1,p+1+n);
}
void solve(){
	LL ans = 0;
	int beg = 1;
	per(i,1,ny){//枚举y，也就是枚举行，也就是下边界
		clr(1,1,nx);//重新枚举上边界时，要重新建树,nx别写成了ny了
		for(int j = i,curr = beg;j <= ny;++j){
			while(curr <= n && p[curr].y == j){
				update(1,1,nx,p[curr].x,p[curr].w);
				++curr;
			}
			if(j == i){//记录下一次枚举下边界时节点的起点
				beg = curr;
			}
			ans = max(ans,tr[1].max_sum);
		}
	}	
	printf("%lld\n",ans);
}
/*
题解链接：https://blog.csdn.net/Ratina/article/details/98845871
模板链接：https://blog.csdn.net/Ratina/article/details/98783337
*/
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		per(i,1,n){
			scanf("%d %d %lld",&p[i].x,&p[i].y,&p[i].w);
			xx[i] = p[i].x; yy[i] = p[i].y;
		}
		discret();
		solve();
	}

	return 0;
}