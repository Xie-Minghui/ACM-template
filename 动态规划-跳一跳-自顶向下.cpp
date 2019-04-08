#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b); ++i)
using namespace std;
const int maxn=1e3;
int n = 0,m = 0,h = 0;
int r[maxn+10][maxn+10];
int dp[100][100][100];
int vis[maxn+10][maxn+10];
int dfs(int x,int y,int hn,bool sta){//����x,y,��������hn�Σ�sta�Ƿ��ǵ�һ�ε������ 
	if(x == m && hn == h){//�ݹ���ֹ���� 
		return (vis[x][y] == 0) ? r[x][y] : 0;
	}
	if(sta &&dp[x][y][hn] != 0){//sta��ʾ��һ�ε�����һ�У���ô���Է���ԭ������Ľ�������е�������λDP 
		return dp[x][y][hn];
	}
	int bonus = (vis[x][y] == 0 ) ? r[x][y] : 0;//ֻ�е�һ�����������н�������vis��һ���������飬bool���鲻���� 
	++vis[x][y];
	int res = 0;
	if(hn + 1 <= h){
		if(y-1 >= 1){
			res = dfs(x,y-1,hn+1,false);	
		}
		if(y+1 <= n){
			res = max(res,dfs(x,y+1,hn+1,false));	
		}
	}
	if(x != m){
		if(y - 1 >= 1){
			res = max(res,dfs(x+1,y-1,hn,true));	
		}
		res = max(res,dfs(x+1,y,hn,true));
		if(y+1 <= n){
			res = max(res,dfs(x+1,y+1,hn,true));
		}
	}
	if(sta){//��������λDP������ǵ�һ�ε�����е�ֵ����ô�ͼ�¼�����������Ļ��г�ͻ 
		dp[x][y][hn] = max(res + bonus,dp[x][y][hn]);
	}
	--vis[x][y];
	return res + bonus;
}
int main(){
	//std::ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	while(~scanf("%d %d %d",&m,&n,&h)){
		per(i,1,m){
			per(j,1,n){
				scanf("%d",&r[i][j]); 
			}
		}
		memset(dp,0,sizeof(dp)); memset(vis,0,sizeof(vis));
		int maxv = -1,loc = 0;
		per(i,1,n){
			int ans = dfs(1,i,0,true);
			if(ans > maxv){
				loc = i;
				maxv = ans;
			}
		}
		printf("The starting position is %d, The maximum bonus you can get is %d\n",loc,maxv);
	}
	return 0;
}
