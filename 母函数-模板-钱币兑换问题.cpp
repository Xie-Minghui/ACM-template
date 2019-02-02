#include<bits/stdc++.h>
using namespace std;
const int maxn = 32768;
typedef long long LL;
int sup[maxn+10],temp[maxn+10];
int n = 0;
void solve(){
	fill(sup,sup+maxn,1);
	fill(temp,temp+maxn,0);
	//int last = 0;
	//sup[0] = sup[1] = sup[2] = sup[3] = 1;
	for(int i = 2;i <= 3;++i){
	//	int last2 = min(last+)
		for(int j = 0;j <= maxn;++j){
			for(int k = 0;k + j <= maxn;k += i){
				temp[j+k] += sup[j]; 
			}
		}
		for(int j = 0;j <= maxn;++j){
			sup[j] = temp[j];
			temp[j] = 0;
		}
	}
	//printf("%d\n",sup[n]);
}
int main(){
	solve();//先一次性全部处理，这道题的评测方式特别不是一个一个样例即使的，是一起叠加的 
	while(~scanf("%d",&n)){
		printf("%d\n",sup[n]);
	}
	
	return 0; 
} 
