#include<bits/stdc++.h>
using namespace std;
const int maxn = 8e3 ;
int num[4];
int val[4] = {0,1,2,5};
bool dp[maxn+10];
void solve(){
	int ma = num[1] + 2*num[2] + 5*num[3];
	fill(dp,dp+maxn+10,false);
	dp[0] = true;
	for(int i = 1;i <= 3;++i){
		for(int k = 1;k <= num[i];++k){//kҪ��1��ʼ 
			for(int j = ma;j >= 1;--j){//�Ӵ�С�ݼ� 
				dp[j] = (dp[j] || dp[j-val[i]]);//������ߴ�֮ǰ��j-val[i]ת�ƹ��� 
			}
		}
	}
	for(int i = 1;i <= ma+1;++i){
		if(dp[i] == false){
			printf("%d\n",i);
			return ;
		}
	}
}
int main(){
	while(~scanf("%d %d %d",&num[1],&num[2],&num[3])){
		if(num[1] == 0 && num[2] == 0 && num[3] == 0){
			break;
		}
		solve();
	}
	
	
	return 0;
}
