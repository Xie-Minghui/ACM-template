#include<iostream>
#include<cstdio> 
#include<algorithm>
#include<queue>
using namespace std;//POJ 3255
const int INF = 5e8; 
const int maxn = 5000 + 100;
int n = 0,r = 0;
struct edge{
	int to;
	int cost;
};
typedef pair<int,int> P;
vector<edge> G[maxn];//�ڽӱ����ȷ���ƣ��ṹ��洢������Ϣ���洢�߶����ǵ㣨��������д�ṹ�壩 
int dist[maxn],dist2[maxn];//��̾�����ζ̾��� 
void solve(){
	fill(dist,dist + maxn,INF);
	fill(dist2,dist2 + maxn,INF);
	dist[1] = 0;
	priority_queue<P,vector<P>,greater<P> >que;
	que.push(P(1,0));
	
	while(!que.empty()){
		P p = que.top();
		que.pop();
		int v = p.first,d = p.second;//first�ǽڵ�,second�Ƕ�Ӧ����̾��� 
		if(dist2[v] < d){//�������������˵���õ��Ѿ�ȡ����̾���,d��ʾ���Ǳ�ǵľ��룬���ø����� 
			continue;
			//�ؼ�����ֹ�������������ڵĵ㣬�������ڵ��dist��dist2,������Щ����������ǰ������
			//�ĵ㲢�һὫ���������ȶ����У��ٴγ���ʱ�ͻ��жϵģ��ͻὫ���ų�
			//����Ƚ�������⣬����Լ�������� 
			//�����1->2->3->1 
			//���ǱȽ����ߵ�dist������������Ǹ����������������		
		}
		for(int i = 0;i < G[v].size();++i){//�����ýڵ���ڽӱ� 
			edge e = G[v][i];
			int d2 = e.cost + d;
			if(dist[e.to] > d2){//С����̾��� 
				swap(dist[e.to] , d2);
				que.push(P(e.to,dist[e.to]));
				dist2[e.to] = d2;
				que.push(P(e.to,dist2[e.to]));
				continue; 
			}
			if(dist2[e.to] > d2 && dist[e.to] < d2){//������̾���ʹζ̾���֮�� 
				dist2[e.to] = d2;
				que.push(P(e.to,dist2[e.to]));
				continue;
			}
		}
	}
	printf("%d\n",dist2[n]);
}
int main(){
	while(scanf("%d %d",&n,&r) != EOF){
		for(int i = 0;i < r;++i){
			int a = 0,b = 0,c = 0;
			edge e;
			scanf("%d %d %d",&a,&b,&c);
			e.cost = c;
			e.to = b;G[a].push_back(e);
			e.to = a;G[b].push_back(e);
		}
		solve();
	}
	
	
	return 0;
}
