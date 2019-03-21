#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstring>
#define INF  1e5
using namespace std;
const int maxn = 200 + 10;

double adj[maxn][maxn];
bool used[maxn];
int min_cost[maxn];
int n = 0;
struct _node{
	double x,y;
};
_node node[maxn];

double cal(_node a, _node b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void Floyd(){//只要求跳的最小距离，并没有要求是 全局的最短路 
	for(int k = 1;k <= n;++k){
		for(int i = 1;i <= n;++i){
			for(int j = 1;j <= n;++j){
				if(adj[i][k] < adj[i][j] && adj[k][j] < adj[i][j]){//三角形,松弛操作 
					adj[i][j] = adj[j][i] = min(adj[i][j] ,max( adj[i][k] , adj[k][j])) ;
				}
			}
		}
	}
} 

int main(){
	int kase = 0;
	while(scanf("%d",&n) != EOF && n){
		fill(adj[0],adj[0]+maxn*maxn,INF);

		for(int i = 1;i <= n;++i ){
			scanf("%lf %lf",&node[i].x,&node[i].y);
		}
		 for(int i = 1; i < n; i++){
		 	for(int j = i + 1; j <= n; j++){//从i+1开始，减少重复计算 
		 		//下面这种会有精度差5.000，变成4.232，应该是pow()函数的问题 
		 		//adj[i][j] = adj[j][i] = sqrt(( pow(node[i].x - node[j].x,2) )+ 
				//	(pow(node[i].x - node[j].x,2) )) ;
					
				//下面这种就可以 
				//adj[i][j] = adj[j][i] = sqrt( (node[i].x - node[j].x) * (node[i].x - node[j].x) 
				//+ (node[i].y - node[j].y) * (node[i].y - node[j].y));
				adj[i][j] = adj[j][i] = cal(node[i], node[j]);
			 }
                
		 }     
		Floyd();
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n", ++kase, adj[1][2]);

	}

	return 0;
}
