#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 1e5
using namespace std;
typedef long long LL;
const int maxn = 1e4;
const int maxv = 1e3;
int V = 0,E = 0;
struct Edge{
	int u,v;
	int w;
};

Edge edge[maxn];
int dist[maxv];
//求解从顶点S出发到所有点的最短距离 
void B_F(int s){//挑战的模板 ，只能用于没有负边的图 
	for(int i = 1;i <= V;++i){
		dist[i] = INF;
	}
	dist[s] = 0;
	while(true){		//如果有负边，会陷入while死循环 
		bool update = false;
		for(int i = 1;i <= E;++i){
			Edge e = edge[i];
			if(dist[e.u] != INF && dist[e.v] > dist[e.u] + e.w){
				dist[e.v] = dist[e.u] + e.w;
				update = true;
			}
		}
		if(update == false){
			break;
		}
	}
}

							//时间复杂度:O(V*E) 
bool B_F(int s){					//Bellman_Ford算法,适用于负边的情况 
	for(int i = 1;i <= V;++i){
		dist[i] = INF;
	}
	dist[s] = 0;//起点设置为0						
	for(int i = 1;i < V;++i){
		for(int j = 1;j <= E;++j){
			int u = edge[j].u,v = edge[j].v;
			if(dist[u] != INF && dist[v] > dist[u] + edge[j].w){//relax,松弛操作 
				dist[v] = dist[u] + edge[j].w;
			}
		}
	}
	bool flag = true;
	for(int i = 0;i < E;++i){
		if(dist[edge[i].v] > dist[edge[i].u] + edge[i].w){//检查到负边 
			flag = false;
			break;
		}
	}
	return flag;
}							//改错，因为存在负圈的话，根本就不能求出最短路 
							//不好意思，这个版本不能求最短路，只能找出负圈（此时无法求解最短路） 
//bool B_F(){					//Bellman_Ford算法,适用于负边的情况 
bool find_negative_loop(){
	memset(dist,0,sizeof(dist));
	
	for(int i = 1;i <= V;++i){
		for(int j = 0;j < E;++j){
			int u = edge[j].u,v = edge[j].v;
			if(dist[v] > dist[u] + edge[j].w){//relax,松弛操作 
				dist[v] = dist[u] + edge[j].w;
				if(i == V){//如果第n次仍然更新了，则存在负边 
					return false;
				}
			}
		}
	}
	return true;
}
int main(){
	
	
	
	
	return 0;
} 
