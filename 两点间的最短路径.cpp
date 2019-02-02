#include<iostream> 
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<cstring> 
using namespace std;

vector<int> ve;
const int maxn = 102;
const int INF = 1000000;
int start = 0,ed = 0;
int n = 0;
int adj[maxn][maxn],p[maxn],d[maxn];
int color[maxn];
void init(){
	memset(color,0,sizeof(color));
	memset(adj,0,sizeof(adj));
	memset(d,INF,sizeof(d));
	memset(p,-1,sizeof(p));
}
void bfs(){
	queue<int> q;
	q.push(start);
	color[start] = 1;
	p[start] = -1;//
	d[start] = 0;
	
	while(!q.empty()){
		int u = q.front();q.pop();
		if(u == ed){
			break;
		}
		for(int v = 1;v <= n;++v){
			if(adj[u][v] > 0 && color[v] == 0){
				p[v] = u;
				q.push(v);
				color[v] = 1;
			}
		}
	}	
	
}
int main(){
	
	init();
	scanf("%d %d",&start,&ed);
	getchar();
	scanf("%d",&n);
	getchar();
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= n;++j){
			scanf("%d",&adj[i][j]);
		}
		getchar();
	}
	bfs();
	if(p[ed] == -1){
		printf("NO\n");
	}else{
		stack<int> st;
		int v = ed;
		while(p[v] != -1){//打印路径 
			st.push(v);
			v = p[v];
		}
		st.push(v);
		while(!st.empty()){//反向打印路径 
			printf("%d\n",st.top());
			st.pop();
		}
	}
	
	return 0;
}
