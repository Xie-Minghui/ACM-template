/*
编写程序，在数组中同时查找最大值和最小值，用递归程序实现
*/
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
void Find_max_min(int* a,int l,int r,int& ma,int& mi){//interval is [l,r) 
	if(r - l == 1){
		ma = max(ma,a[l]);
		mi = min(mi,a[l]);
		return ;
	}
	int mid = l + (r-l)/2;
	Find_max_min(a,l,mid,ma,mi);
	Find_max_min(a,mid,r,ma,mi);
}
int main(){
	int n = 0;
	while(~scanf("%d",&n)){	
		if(n == 0){//handle exception 
			puts("Please input a valid n !!!");
			continue;
		}
		int* A = new int[n+1];
		for(int i = 1;i <= n;++i){
			scanf("%d",&A[i]);
		}
		int maxv = -INF,minv = INF;
		Find_max_min(A,1,n+1,maxv,minv);
		printf("max: %d , min:%d\n",maxv,minv);
	}
	return 0;
} 
