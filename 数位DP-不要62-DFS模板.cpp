#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int d[20];
int dp[20][2];
//pre适用于有前导0的情况 ,sta是题目中的合法状态的记录 
int dfs(int pos,int pre,int sta,bool lim){
	if(pos == 0){//枚举完了数位，说明合法 
		return 1;
	}
	if(!lim && dp[pos][sta] != -1){//如果没有限制，返回全部 
		return dp[pos][sta];
	}
	
	int up = lim ? d[pos] : 9;//枚举的上限 
	int temp = 0;
	for(int i = 0;i <= up;++i){
		if(pre == 6 && i == 2){
			continue;
		}
		if(i == 4){
			continue;
		}
		temp += dfs(pos-1,i,i==6,lim && i==d[pos]);
	}
	if(!lim){//如果没有限制，返回全部 
		dp[pos][sta] = temp;
	}
	return temp;
}
int solve(int x){//数字的拆分 
	int temp = x;
	int cnt = 0;
	while(temp > 0){
		d[++cnt] = temp % 10;
		temp /= 10;
	}
	d[cnt+1] = 0;
	return dfs(cnt,-1,0,true);//初始化状态：pos:cnt,前面的数字-1， 
}
void init(){
	memset(dp,-1,sizeof(dp));
}
int main(){
	int n = 0,m = 0;
	while(scanf("%d %d",&n ,&m) != EOF && (m >= n) && n){
		init();
		printf("%d\n",solve(m) - solve(n-1));//闭区间[0,m]-[0,n-1] = [n,m] 
	}
	
	return 0;
} 
