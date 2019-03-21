#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int d[20];
int dp[20][2];
//pre��������ǰ��0����� ,sta����Ŀ�еĺϷ�״̬�ļ�¼ 
int dfs(int pos,int pre,int sta,bool lim){
	if(pos == 0){//ö��������λ��˵���Ϸ� 
		return 1;
	}
	if(!lim && dp[pos][sta] != -1){//���û�����ƣ�����ȫ�� 
		return dp[pos][sta];
	}
	
	int up = lim ? d[pos] : 9;//ö�ٵ����� 
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
	if(!lim){//���û�����ƣ�����ȫ�� 
		dp[pos][sta] = temp;
	}
	return temp;
}
int solve(int x){//���ֵĲ�� 
	int temp = x;
	int cnt = 0;
	while(temp > 0){
		d[++cnt] = temp % 10;
		temp /= 10;
	}
	d[cnt+1] = 0;
	return dfs(cnt,-1,0,true);//��ʼ��״̬��pos:cnt,ǰ�������-1�� 
}
void init(){
	memset(dp,-1,sizeof(dp));
}
int main(){
	int n = 0,m = 0;
	while(scanf("%d %d",&n ,&m) != EOF && (m >= n) && n){
		init();
		printf("%d\n",solve(m) - solve(n-1));//������[0,m]-[0,n-1] = [n,m] 
	}
	
	return 0;
} 
