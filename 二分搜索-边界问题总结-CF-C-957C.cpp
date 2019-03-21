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
const int maxn = 1e5;
int n = 0,u = 0;
int a[maxn+10];
/*
int solve(int l,int x){
	int r = n;
	int ans = -1;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(a[mid] > x){
			r = mid - 1;
		}else{
			ans = mid;
			l = mid + 1;
		}

	}
	return ans;
}
*/
/*
int solve(int l,int x){
	int r = n+1;
	int ans = -1;
	while(l < r){
		int mid = (l + r) >> 1;
		if(a[mid] > x){
			r = mid;
		}else{
			ans = mid;
			l = mid + 1;
		}

	}
	return r-1;//���ﷵ�ص���r-1,��Ϊ��[l,r) 
}
*/
int solve(int l,int x){
	int r = n+1;
	--l;
	int ans = -1;
	while(l + 1 < r){
		int mid = (l + r) >> 1;
		if(a[mid] > x){
			r = mid;
		}else{
			l = mid;
		}
	}
	//return l;//
	return r-1; 
}
/*��������3����������Եõ����ɣ�
[l,r]����mid;	[l,r)����r-1;	(l,r)����r-1����l 
1,����Ǳ�������Ҫ����mid
2,����뿪������䣬r��ʱ������r-1;l,r����ʱ������ r-1,����l������ 
*/
int main(){
	while(~scanf("%d %d",&n,&u)){
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		double ans = 0;
		for(int i = 1;i <= n-2;++i){
			//int k = lower_bound(a+i,a+1+n,a[i]+u) - a;
			int k = solve(i,a[i]+u);
			//cout << k << endl;
			if(k <= i+1){
				continue;
			}
			//if(a[k]  != a[i] + u){//����lower_bound�󣬾Ͳ���Ҫ�ˣ���Ϊ�Լ�д�Ķ���
			//����һ����<=a[i]+u�ģ���lower_bound������>= 
			//	--k;
			//}
			ans = max(ans,(a[k] - a[i+1])*1.0 / (1.0 * (a[k] - a[i])) );
		}
		if(ans == 0){
			printf("-1\n");
		}else{
			printf("%.10lf\n",ans);
		}
	}
	return 0;
}

