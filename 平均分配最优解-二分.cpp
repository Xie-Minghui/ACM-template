#include<iostream>
#include<cstdio>
using namespace std;
typedef long long llong;
const int maxn = 100000;
int A[maxn];
int k,n;

int check(llong P)
{
	int v = 0;
	for(int i = 0;i < k;i++){
		llong sum = 0;
		while(sum + A[v] <= P){
			sum += A[v];
			v++;
			if(v == n)  return n;
		}
	}
	return v;
}

int get_ans()
{
	llong left = 0,right = 100000 * 10000;
	llong mid; 
	while(right - left > 1){
		mid = (right - left) / 2 + left;
		int v = check(mid);
		if(v < n){
			left = mid;
		}
		else{
			right = mid;
		}
	}
	return right;
}
int main()
{
	scanf("%d %d",&n,&k);
	for(int i = 0;i < n;i++){
		scanf("%d",&A[i]);
	}
	int ans = get_ans();
	printf("%d\n",ans);
}
