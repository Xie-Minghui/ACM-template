#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 10;
const LL mod = (1e9 + 7);
int a[maxn],b[maxn];
int n = 0,m = 0;
inline int read(){//快速读
    char chr=getchar();
    int f=1,ans=0;
    while(!isdigit(chr)) {if(chr=='-') f=-1;chr=getchar();}
    while(isdigit(chr))  {ans=ans*10;ans+=chr-'0';chr=getchar();}
    return ans*f;
}
inline int gi(){//这个快速读的模板比上面快，估计是没有调用某些函数
    char a=getchar();int b=0;
    while(a<'0'||a>'9')a=getchar();
    while(a>='0'&&a<='9')b=b*10+a-'0',a=getchar();
    return b;
}

struct STree{
	int l,r,num;
	LL val;
}st[maxn<<2];
void build(int rt,int l,int r){
	st[rt].l = l; st[rt].r = r;
	st[rt].num = 0;st[rt].val = 0;//初始化，刚开始什么都没有
	if(l == r){
		return ;
	}
	int mid = (l + r) >> 1;
	build((rt<<1),l,mid);
	build((rt<<1)|1,mid+1,r);
	return ;
}
int query(int rt,int sum){
	if(st[rt].val <= sum){
		return st[rt].num;
	}
	if(st[rt].l == st[rt].r){//说明只能选这个数来构成
		return min(st[rt].num,sum/b[st[rt].l]);
	}
	if(st[rt<<1].val >= sum){//去左子树去寻找
		return query(rt<<1,sum);
	}else{//全选左子树，剩下的部分去右子树找
		return st[rt<<1].num + query(rt<<1|1,sum-st[rt<<1].val);
	}
}
void push_up(int rt){//向上更新
	st[rt].val = st[rt<<1].val + st[rt<<1|1].val;
	st[rt].num = st[rt<<1].num + st[rt<<1|1].num;
}
void update(int rt,int pos){//更新节点
	if(st[rt].l == st[rt].r){
		++st[rt].num;
		st[rt].val += b[pos];
		return ;
	}

	if(pos <= st[rt<<1].r){
		update(rt<<1,pos);
	}else{
		update(rt<<1|1,pos);
	}

	push_up(rt);
	return ;
}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		// scanf("%d %d",&n,&m);
		n = gi();m = gi();
		per(i,1,n){
			// scanf("%d",&a[i]);
			a[i] = gi();
			b[i] = a[i];
		}
		sort(b+1,b+1+n);
		int len = unique(b+1,b+1+n) - (b + 1);
		build(1,1,len);
		per(i,1,n){
			if(i == 1){
				printf("0 ");
			}else{
				printf("%d ",i-1- query(1,m-a[i]));//寻找前k小的数和<=m-a[i],k最大
			}
			int pos = lower_bound(b+1,b+1+len,a[i]) - b;//离散化
			update(1,pos);//类似于前缀和，不断迭代
			//主席树是可持久化线段树，可持久化是保留了这棵树的所有版本
		}
		printf("\n");
	}


	return 0;
}
