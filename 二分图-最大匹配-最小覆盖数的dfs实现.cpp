#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e4;
int edge[maxn+10][maxn+10];//�ߵ��ڽӾ��� 
bool vis[maxn+10];//�������� 
int cx[maxn+10],cy[maxn+10];//��¼x������ƥ���y���ϵ�Ԫ�� 
int nx = 0,ny = 0,t = 0;//x�����е�Ԫ�� 

int path(int u){
	for(int i = 1;i <= ny;++i){
		if(vis[i] == false && edge[u][i] == 1){//û�з��ʣ������б����� 
			vis[i] = true;
			if(cy[i] == -1 || path(cy[i])){//���y�����е�iû��ƥ�䣬����i�Ѿ�ƥ��
			//���ǿ��Դ�cy[i]�п����ҵ�һ������· 
				cx[u] = i;cy[i] = u;//�ҵ�����·���޸�ƥ�� 
				return 1;
			}
		}
	}
	return 0;
}
int max_match(){
	int sum = 0;
	memset(cx,-1,sizeof(cx));memset(cy,-1,sizeof(cy));//��ʼ��-1����ʾ��û��ƥ�� 
	for(int i = 1;i <= nx;++i){
		if(cx[i] == -1){//û��ƥ��ʱ��ִ��path���� 
			memset(vis,false,sizeof(vis));//���ñ��Ϊδ���� 
			sum += path(i);
		}
	}
	return sum;
}
int main(){//���ƥ�� == ��С���㸲��������С·�������� = V - ���ƥ�� 
	while(~scanf("%d",&t) && t){
		memset(edge,0,sizeof(edge));
		scanf("%d %d",&nx,&ny);
		for(int i = 1;i <= t;++i){
			int x = 0,y = 0;
			scanf("%d %d",&x,&y);
			//edge[x][y] = 1;//����� 
			edge[x][y] = edge[y][x] = 1;
		}
		int sum = max_match();
		printf("%d\n",sum);
	}
	
	return 0;
}
