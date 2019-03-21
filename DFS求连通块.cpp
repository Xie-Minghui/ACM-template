#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 100 + 5;
int mov[2][3] = { {0,1,-1} , { 0,1,-1} }; //移动数组 
char pic[maxn][maxn];
int m,n,idx[maxn][maxn];

void dfs(int r,int c,int id){
	
	if(r < 0 || r >= m || c < 0 ||c >= n)		return ; //出界的格子 
	if(pic[r][c] != 'W' || idx[r][c] > 0 )  return;//不是"@"或者已经访问过的格子 
	idx[r][c] = id;//连通分量编号 
	
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			if(i != 0 || j != 0){
				//r += mov[i][0];
				//c += mov[0][j];
				dfs(r + mov[0][i],c + mov[1][j],id); //移动方式 
			}
		}
	}
	
	/*
	for(int dr = -1;dr <= 1;dr++){
		for(int dc = -1;dc <= 1;dc++){
			if(dr != 0 || dc != 0){
				dfs(r+dr,c+dc,id);
			}
		}
	}
	*/
} 

int main(){
	
	while(scanf("%d %d",&m,&n) == 2 && m && n){
		for(int i = 0;i < m;i++){
			scanf("%s",pic[i]);
		}
		int cnt = 0;
		memset(idx,0,sizeof(idx));//初始化 
		for(int i = 0;i < m;i++){
			for(int j = 0;j < n;j++){
				if(pic[i][j] == 'W' && idx[i][j] == 0){
					++cnt;
					dfs(i,j,cnt);
				}
			}
		}
		printf("%d\n",cnt);
	}
	
	return 0;
}
