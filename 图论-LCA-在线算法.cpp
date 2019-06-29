#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (b);i >= (b);--i)
using namespace std;
const int maxn = 2e5 + 10,maxv = 1e3 + 30;
struct node{
	int to,nex,w;
};
node e[maxn];
int head[maxn];
vector<int> g;//记录dfs序列
int first[maxn];//first[i]记录i第一次出现的数组下标
int dp[maxv][maxv];
int n = 0,cntv = 0;
int in[maxn];

void init(){
	cntv = 0;
	memset(head,-1,sizeof(head));	memset(in,0,sizeof(in)); memset(first,-1,sizeof(first)); memset(dp,0x3f,sizeof(dp));
	
}
void add_edge(int from,int to,int w){
	e[++cntv] = node{to,head[from],w};
	head[from] = cntv;
}
void dfs(int s){
	g.push_back(s);
	//first[s] = (first[s] == -1 ? g.size() : first[s]);
	if(first[s] == -1){
		first[s] = g.size();
	}
	for(int i = head[s];i != -1;i = e[i].nex){
		dfs(e[i].to);
		g.push_back(s);
	}
}
void ST(){
	int si = g.size();
	int k = 0;
	while((1 << (k+1)) < si){
		++k;
	}
	per(i,1,si){
		dp[i][0] = g[i-1];
	}
	per(j,1,k){
		for(int i = 1;i + (1<<j) <= si;++i){
			dp[i][j] = min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
		}
	}
}

int RMQ(int l,int r){
	int k = 0;
	while((1<<(k+1)) < r - l + 1){
		++k;
	}
	return min(dp[l][k],dp[r-(1<<k) + 1][k]);
}

int main(){
	while(~scanf("%d",&n)){
		init();
		per(i,1,n-1){
			int x = 0,y = 0,w = 0;
			scanf("%d %d",&x,&y);
			add_edge(x,y,w);
			++in[y];
		}
		per(i,1,n){
			if(in[i] == 0){
				dfs(i);
				break;
			}
		}

		ST();
		/*
		per(i,1,n){
			cout << first[i] << " ";
		}
		cout <<endl;
		*/
		
		int q = 0;
		scanf("%d",&q);
		per(i,1,q){
			int x = 0,y = 0;
			scanf("%d %d",&x,&y);
			int ans = RMQ(min(first[x],first[y]),max(first[x],first[y]));
			printf("%d\n",ans);
		}

	}


	return 0;
}
/*
9
1 2
1 3
2 4
2 5
5 7
5 8
7 9
3 6
4
9 8
4 6
2 7
5 3

ans:
first: 1 6 2 15 7 3 10 8 11 -1
5
1
2
1

*/