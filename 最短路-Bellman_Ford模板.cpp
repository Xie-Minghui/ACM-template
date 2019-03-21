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
//���Ӷ���S���������е����̾��� 
void B_F(int s){//��ս��ģ�� ��ֻ������û�и��ߵ�ͼ 
	for(int i = 1;i <= V;++i){
		dist[i] = INF;
	}
	dist[s] = 0;
	while(true){		//����и��ߣ�������while��ѭ�� 
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

							//ʱ�临�Ӷ�:O(V*E) 
bool B_F(int s){					//Bellman_Ford�㷨,�����ڸ��ߵ���� 
	for(int i = 1;i <= V;++i){
		dist[i] = INF;
	}
	dist[s] = 0;//�������Ϊ0						
	for(int i = 1;i < V;++i){
		for(int j = 1;j <= E;++j){
			int u = edge[j].u,v = edge[j].v;
			if(dist[u] != INF && dist[v] > dist[u] + edge[j].w){//relax,�ɳڲ��� 
				dist[v] = dist[u] + edge[j].w;
			}
		}
	}
	bool flag = true;
	for(int i = 0;i < E;++i){
		if(dist[edge[i].v] > dist[edge[i].u] + edge[i].w){//��鵽���� 
			flag = false;
			break;
		}
	}
	return flag;
}							//�Ĵ���Ϊ���ڸ�Ȧ�Ļ��������Ͳ���������· 
							//������˼������汾���������·��ֻ���ҳ���Ȧ����ʱ�޷�������·�� 
//bool B_F(){					//Bellman_Ford�㷨,�����ڸ��ߵ���� 
bool find_negative_loop(){
	memset(dist,0,sizeof(dist));
	
	for(int i = 1;i <= V;++i){
		for(int j = 0;j < E;++j){
			int u = edge[j].u,v = edge[j].v;
			if(dist[v] > dist[u] + edge[j].w){//relax,�ɳڲ��� 
				dist[v] = dist[u] + edge[j].w;
				if(i == V){//�����n����Ȼ�����ˣ�����ڸ��� 
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
