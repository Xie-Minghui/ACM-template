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
int max_sum(int *a,int x,int y){//�����������ұ�����[x,y)�е���������� 
	if(y - x == 1){
		return a[x];//ֻ��һ��Ԫ�أ�ֱ�ӷ��� 
	} 
	int mid = (y - x) / 2 + x;//���ε�һ�������ֳ�[x,mid),[mid,y) 
	int maxs = max(max_sum(a,x,mid),max_sum(a,mid,y));//���εڶ������ݹ���� 
	int maxv = 0;
	int l = a[mid-1];//���ܳ�ʼ��Ϊ0����Ϊ�����и���������max����� 
	rep(i,mid-1,x){//���ε��������ϲ�(1)-�ӷֽ�㿪ʼ�������������� 
		l = max(l,maxv += a[i]);
	}
	maxv = 0;
	int r =a[mid];
	per(i,mid,y-1){//���ε��������ϲ�(2)-�ӷֽ�㿪ʼ���ҵ���������� 
		r = max(r,maxv += a[i]);
	}
	return max(maxs,l+r);//��������Ľ���l+r�Ƚ� 
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

