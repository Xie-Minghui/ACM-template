#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string> 
#include<cstring>
#include<set>
#define INF 0x7fffffff
using namespace std;
const int maxn = 400000 + 10;//开1e5小了，线段树一般开原来的4倍 

struct SegTree{
	int l,r;
	int sum;
	int add_mark;
};
SegTree seg_tree[maxn];
int arr[maxn]; 
int n = 0;
void build(int root,int is,int ie){
	seg_tree[root].add_mark = 0;
	seg_tree[root].l = is;
	seg_tree[root].r = ie;
	
	if(is == ie){
		seg_tree[root].sum = arr[is];
		return ;
	}else{
		int mid = (ie - is)/2 + is;
		build(root*2,is,mid);
		build(root*2+1,mid+1,ie);
		seg_tree[root].sum = seg_tree[root*2].sum + seg_tree[root*2+1].sum;
	}
	
}

void push_down(int root){
	if(seg_tree[root].add_mark != 0){
		seg_tree[root*2].add_mark += seg_tree[root].add_mark;
		seg_tree[root*2+1].add_mark += seg_tree[root].add_mark;
		
		seg_tree[root*2].sum += seg_tree[root].add_mark;
		seg_tree[root*2+1].sum += seg_tree[root].add_mark;
		
		seg_tree[root].add_mark = 0;
	}
}

//void update(int root,int is,int ie,int us,int ue,int add_val){
void update(int root,int us,int ue,int add_val){
	
	int is = seg_tree[root].l,ie = seg_tree[root].r ;
	
	if(is > ue || ie < us){
		return ;
	}else if(is >= us && ie <= ue){
		seg_tree[root].add_mark += add_val;
		seg_tree[root].sum += add_val;
		return ;
	}else{
		push_down(root);
		//int mid = (ie - is)/2 + is;
		//update(root*2,is,mid,us,ue,add_val);
		//update(root*2+1,mid+1,ie,us,ue,add_val);
		update(root*2,us,ue,add_val);
		update(root*2+1,us,ue,add_val);
		seg_tree[root].sum = seg_tree[root*2].sum + seg_tree[root*2+1].sum;
	}
}

int query(int root,int us,int ue){
	
	int is = seg_tree[root].l,ie = seg_tree[root].r;
	
	if(is > ue || ie < us){
		return 0;
	}else if(is >= us && ie <= ue){
		return seg_tree[root].sum;
	}else{
		push_down(root);
		//int mid = (ie - is)/2 + is;
		
		//return query(root*2,is,mid) + query(root*2+1,mid+1,ie);
		return query(root*2,us,ue) + query(root*2+1,us,ue);
	}
	
	
}
int main(){
	int a = 0,b = 0;
	while(scanf("%d",&n) != EOF && n){
		memset(arr,0,sizeof(arr));
		memset(seg_tree,0,sizeof(seg_tree));
		build(1,1,n);
	
		for(int i = 0;i < n;++i){
			scanf("%d %d",&a,&b);
			update(1,a,b,1);
		}
		
		for(int i = 1;i <= n;++i){
			if(i > 1){
				printf(" ");
			}
			printf("%d",query(1,i,i));
		}
		printf("\n");
	}
	
	
	
	
	return 0;
}
