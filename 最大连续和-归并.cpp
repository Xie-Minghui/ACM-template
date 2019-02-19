#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

typedef long long LL;

#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
const int maxn = 3e5;
int n = 0,m = 0;
int a[maxn+10];
int max_sum(int *a,int x,int y){//返回数组左开右闭区间[x,y)中的最大连续和 
	if(y - x == 1){
		return a[x];//只有一个元素，直接返回 
	} 
	int mid = (y - x) / 2 + x;//分治第一步：划分成[x,mid),[mid,y) 
	int maxs = max(max_sum(a,x,mid),max_sum(a,mid,y));//分治第二步：递归求解 
	int maxv = 0;
	int l = a[mid-1];//不能初始化为0，因为输入有负数，下面max会出错 
	rep(i,mid-1,x){//分治第三步：合并(1)-从分界点开始往左的最大连续和 
		l = max(l,maxv += a[i]);
	}
	maxv = 0;
	int r =a[mid];
	per(i,mid,y-1){//分治第三步：合并(2)-从分界点开始往右的最大连续和 
		r = max(r,maxv += a[i]);
	}
	return max(maxs,l+r);//将子问题的解与l+r比较 
}
int main(){
	while(~scanf("%d",&n)){
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		printf("%d\n",max_sum(a,1,n+1));
	}
	
	
	return 0;
}

