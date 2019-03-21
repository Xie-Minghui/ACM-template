#include<iostream>
#include<cstdio>
#include<algorithm>	
#include<string>
#include<cstring>
#include<set>
using namespace std;
const int maxn = 1e5 + 10;
struct Node{
	int x,y;
	int id;
};
Node a[maxn];
int tree[maxn],level[maxn];
int n = 0;
bool cmp(Node a,Node b){
	if(a.y != b.y){
		return a.y > b.y;
	}else{
		return a.x < b.x;
	}
}
int lowbit(int x){
	return x & (-x);
}

void add(int loc,int val){
	for(int i = loc;i <= maxn;i += lowbit(i)){
		tree[i] += val;
	}
	/*
	int  i = loc;
	while(i <= loc){
		tree[i] += val;
		i += lowbit(i);
	}
	*/
}

int getsum(int loc){
	int ans = 0;
	for(int i = loc;i > 0;i -= lowbit(i)){
		ans += tree[i]; 
	}
	/*
	int  i = loc;
	while(i > 0){
		ans += tree[i];
		i -= lowbit(i);
	}
	*/
	return ans;
}
int main(){
	
	
	while(scanf("%d",&n) != EOF && n){
		memset(tree,0,sizeof(tree));
		memset(level,0,sizeof(level));
		for(int i = 0;i < n;++i){//因为y是递增的，所以可以不用考虑y
			scanf("%d %d",&a[i].x,&a[i].y);
			++a[i].x,++a[i].y;			//避免0的出现 
			a[i].id = i;				//当前从区间1-x的和（闭区间），即是水平数
						//但是，因为是递增的，所以 只能看当前1-x区间的总和
								//然后再单点更新（不包括本身） 
		}
		sort(a,a + n,cmp);//
		level[a[0].id] = getsum(a[0].x);
		add(a[0].x,1);
		for(int i = 1;i < n;++i){
			if(a[i].x == a[i-1].x && a[i].y == a[i-1].y){
				level[a[i].id] = level[a[i-1].id];
			}else{
				level[a[i].id] = getsum(a[i].x);		
			}
			add(a[i].x,1);
		}
		printf("%d",level[0]);
		for(int i = 1;i < n;++i){
			//if(i > 0){
		//		printf(" ");
		//	}
			printf(" %d",level[i]);
		}
		printf("\n");
	}
	
	
	
	return 0;
} 
