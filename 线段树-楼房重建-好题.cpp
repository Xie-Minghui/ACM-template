#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string> 
#include<cstring>
#include<set>
#define INF 0x7fffffff
using namespace std;
const int maxn = 1e5 + 10;
int n = 0,m = 0;
struct node{
	int l,r;
	double kk;//存储区间斜率的最大值 
	int num;//存储可以被看到的房子数 
}tree[maxn * 4];
void build(int root,int l,int r){
	tree[root].l = l;tree[root].r = r;
	tree[root].kk = tree[root].num = 0;
	if(l == r){
		return ;
	}
	int mid = (l + r) >> 1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
}
int query(int root,double k2){
	int l = tree[root].l,r = tree[root].r;
	if(l == r){
		if(tree[root].kk > k2){
			return 1;
		}else{
			return 0;
		}
	}
	if(tree[root<<1].kk <= k2){
		return query(root<<1|1,k2);
	}else{
		return query(root<<1,k2) + tree[root].num - tree[root<<1].num;
	}
}
void update(int root,int x,double k2){
	int l = tree[root].l,r = tree[root].r;
	int mid = (l + r) >> 1;
	if(l == r && l == x){
		tree[root].num = 1;
		tree[root].kk = k2;
		return ;
	}
	if(x <= mid){
		update(root<<1,x,k2);
	}else{
		update(root<<1|1,x,k2);
	}
	tree[root].kk = max(tree[root<<1].kk,tree[root<<1|1].kk);
	if(tree[root<<1|1].kk <= tree[root<<1].kk){
		tree[root].num = tree[root<<1].num;
	}else{
		tree[root].num = tree[root<<1].num + query(root<<1|1,tree[root<<1].kk);
	}
}
int main(){
	//具体解释看下面这个网址 
	//https://blog.csdn.net/nhl19961226/article/details/77126920
	//思路详解：https://blog.csdn.net/FromATP/article/details/53195831 
	scanf("%d %d",&n,&m);
	build(1,1,n);
	for(int i = 1;i <= m;++i){
		int x = 0,y = 0;
		scanf("%d %d",&x,&y);
		update(1,x,y*1.0/x);
		printf("%d\n",tree[1].num);
	}
	
	return 0;	
} 
