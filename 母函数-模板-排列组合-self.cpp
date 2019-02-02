#include<bits/stdc++.h>
using namespace std;
const int maxn = 15;
double temp[maxn],sup[maxn];
int n = 0,m = 0;
int num[maxn];
int f[maxn];
int fac(int x){
	f[0] = 1;
	for(int i = 1;i <= x;++i){
		f[i] = f[i-1]*i;
	}
	return f[x];
}
int main(){
	while(~scanf("%d %d",&n,&m)){
		fill(temp,temp+maxn,0);fill(sup,sup+maxn,0);
		for(int i = 1;i <= n;++i){
			scanf("%d",&num[i]);
		}
		for(int i = 0;i <= num[1];++i){
			sup[i] = 1.0/fac(i);
		}
		for(int i = 2;i <= n;++i){
			for(int j = 0;j <= n;++j){
				for(int k = 0;k + j <= n && k <= num[i];++k){
					temp[j+k] += sup[j]/fac(k);
				}
			}
			for(int j = 0;j <= n;++j){
				sup[j] = temp[j];
				temp[j] = 0;
			}
		}
		printf("%.llf\n",sup[m]*fac(m));
	}
	return 0;
} 
