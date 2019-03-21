#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e4;
int edge[maxn+10][maxn+10];//边的邻接矩阵 
bool vis[maxn+10];//访问数组 
int cx[maxn+10],cy[maxn+10];//记录x集合中匹配的y集合的元素 
int nx = 0,ny = 0,t = 0;//x集合中的元素 

int path(int u){
	for(int i = 1;i <= ny;++i){
		if(vis[i] == false && edge[u][i] == 1){//没有访问，并且有边相连 
			vis[i] = true;
			if(cy[i] == -1 || path(cy[i])){//如果y集合中的i没有匹配，或者i已经匹配
			//但是可以从cy[i]中可以找到一条增广路 
				cx[u] = i;cy[i] = u;//找到增广路，修改匹配 
				return 1;
			}
		}
	}
	return 0;
}
int max_match(){
	int sum = 0;
	memset(cx,-1,sizeof(cx));memset(cy,-1,sizeof(cy));//初始化-1，表示都没有匹配 
	for(int i = 1;i <= nx;++i){
		if(cx[i] == -1){//没有匹配时，执行path代码 
			memset(vis,false,sizeof(vis));//重置标记为未访问 
			sum += path(i);
		}
	}
	return sum;
}
int main(){//最大匹配 == 最小顶点覆盖数，最小路径覆盖数 = V - 最大匹配 
	while(~scanf("%d",&t) && t){
		memset(edge,0,sizeof(edge));
		scanf("%d %d",&nx,&ny);
		for(int i = 1;i <= t;++i){
			int x = 0,y = 0;
			scanf("%d %d",&x,&y);
			//edge[x][y] = 1;//有向边 
			edge[x][y] = edge[y][x] = 1;
		}
		int sum = max_match();
		printf("%d\n",sum);
	}
	
	return 0;
}
