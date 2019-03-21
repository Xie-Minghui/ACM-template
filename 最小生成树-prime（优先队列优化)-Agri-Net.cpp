#include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<fstream>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define PER(i,x) for(auto i=x.begin();i!=x.end();i++)
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
typedef long long LL;
typedef pair<int,int> pii;
const double eps=1.0e-5;
const int maxn=100 + 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n = 0; 
bool vis[maxn];
int adj[maxn][maxn];
int d[maxn];
struct cmp{
	bool operator()(const pii a,const pii b){
		return a.second > b.second;
	}
}; 
void prime(int s){
	fill(vis,vis+maxn,false);
	fill(d,d+maxn,INF);
	priority_queue<pii,vector<pii>,cmp> que;
	que.push(pii(s,0));
	int res = 0;
	while(!que.empty()){
		pii p = que.top();
		que.pop();
		int u = p.first,v = p.second;
		if(vis[u] == true || d[u] < v){//����һ��������Ϊ��ȥ��������֪��Сֵ�ĵ� 
			continue;//��Ϊ���Ѿ����ʹ��ĵ����ڵĵ㶼���������ȶ��У���������ֻ���� 
		}//�����о�����֪��������Ǹ������������Ŀ����ǲ��е� 
		res += v;
		vis[u] = true;
		for(int i = 1;i <= n;++i){//��������ıȽϺ͸��£�������DJ�㷨��д����һ���� 
			if(d[i] > adj[i][u] && vis[i] == false){
				d[i] = adj[i][u];//�˴���DJ�㷨������DJ��ѡȡ����ԭ������ĵ�
				//��prime�㷨ѡȡ���Ǿ����ѷ��ʽڵ㵽δ���ʽڵ������̵Ľڵ� 
				que.push(pii(i,d[i]));
			}
		}
	}
	printf("%d\n",res);
}
int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	while(~scanf("%d",&n)){
		fill(adj[0],adj[0] + maxn*maxn,INF);
		per(i,1,n){
			per(j,1,n){
				scanf("%d",&adj[i][j]);
			}
		} 
		prime(1); 
	}
	
	return 0; 
}
