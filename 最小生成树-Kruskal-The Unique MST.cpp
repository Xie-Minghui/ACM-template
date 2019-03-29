#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#define INF  1e5
using namespace std;
const int maxn = 10000 + 10;//1e4可以过，1e3RE 
//注意，n<100,最多可能是完全图99*98条边，再考虑数组的边界 
typedef long long LL;
struct MGraph{
	//char vertex[maxn];//顶点表   
	int edges[maxn][maxn];//邻接矩阵,可看做边表 
	int n,e;//图中当前的顶点数和边数     
};
MGraph G;

struct Edge{
	int u;//边的起始顶点   
	int v; //边的终止顶点   
	int w;//边的权值   
	bool flag ;
};
bool cmp(Edge a,Edge b){
	return a.w < b.w;
}
int e_size = 0; //边的数量 
Edge E[maxn]; //存放所有的边  
int vset[maxn];//辅助数组，判定两个顶点是否连通 
void init(){
	int k = 1;//E数组的下标从1开始   
	for(int i = 1;i < G.n;++i){
		for(int j =i+1;j <= G.n;++j){
			if(G.edges[i][j] != INF){
				E[k].u = i,E[k].v = j,E[k].w = G.edges[i][j];
				E[k].flag = false;
				++k;
			}
		}
	}
	e_size = k - 1;
	//heapsort(E,k,sizeof(E[0])); 	
} 
int kruskal1(){//求最小生成树 
	int i,j,sn1,sn2,k;	
	for(i = 1;i <= G.n;++i){//初始化辅助数组   
		vset[i] = i;
	}
	k = 1,j = 1;
	int res = 0;
	
	while(k < G.n){//生成的边数，最后要刚好为总边数   
		sn1 = vset[E[j].u],sn2 = vset[E[j].v];//得到两顶点属于的集合编号   
		if(sn1 != sn2){		//不在同一集合编号内的话，把边加入最小生成树   
			res += E[j].w;
			E[j].flag = true;//标记已经用过 
			++k;
			for(int i = 1;i <= G.n;++i){
				if(vset[i] == sn2){
					vset[i] = sn1;
				}
			}	
		}
		++j;
	}
	return res;
}
int kruskal2(int not_used){
	int i,j,sn1,sn2,k;

	for(i = 1;i <= G.n;++i){//初始化辅助数组   
		vset[i] = i;
	}
	k = 1,j = 1;
	int res = 0;
	
	while(k < G.n){//生成的边数，最后要刚好为总边数   
		if(j == not_used){			//跳过不用的 
			++j;
			continue;
		}
		//vset[]组其实就是并查集中的父亲数组 
		sn1 = vset[E[j].u],sn2 = vset[E[j].v];//得到两顶点属于的集合编号   
		if(sn1 != sn2){		//不在同一集合编号内的话，把边加入最小生成树  
		//相当于并查集，查寻树的根 
			res += E[j].w;
			//E[j].flag = true;//标记已经用过 
			++k;
			for(int i = 1;i <= G.n;++i){
				if(vset[i] == sn2 ){
					vset[i] = sn1;
				}
			}	
		}
		++j;
	}
	return res;
}
bool full(){
	for(int i = 2;i <= G.n;++i){
		if(vset[i] != vset[1]){
			return false;
		}
	}
	return true;
}
int main(){
	int x = 0,y= 0,wt = 0;
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&G.n,&G.e);
		for(int i = 0;i <= G.n;++i){
			for(int j = 0;j <= G.n;++j){
				G.edges[i][j] = INF;
			}
		}
		for(int i = 1;i <= G.e;++i){
			scanf("%d %d %d",&x,&y,&wt);
			G.edges[x][y] = G.edges[y][x] = wt;
		}
		init();	
		sort(E+1,E+e_size+1,cmp);	
		LL ans1 = kruskal1();
		LL ans2 = 0,fg = 0;
		for(int i = 1;i <= e_size;++i){
			if(E[i].flag == true){
			/* 
				int temp = E[i].w;
				E[i].w = INF;
				sort(E+1,E+e_size+1,cmp);
				E[e_size].w = temp;
				sort(E+1,E+e_size+1,cmp);//最后还要排一次序，复原 (之前一直WA的原因可能就是这里）
				//换了一种标记方式就行了 
			*/
				ans2 = kruskal2(i);//寻找不用到边 i 的最小生成树
				if(ans2 == ans1 && full()){//但是我的写法，这个full判断可有可无 
		//需要考虑无法形成最小生成树(既没有将所有的点连起来)
		//但却刚好有返回值相等的情况(一部分的树的边权值和)
					fg = 1;
					printf("Not Unique!\n");
					break;
				}
			}	
		}
		if(fg == 0){
			printf("%lld\n",ans1);
		}
		
	}
		
	return 0;
}
