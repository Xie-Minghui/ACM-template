#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
const int maxn = 5e3 + 10;
int n = 0;
int a[maxn];
int color[maxn],head[maxn],cntt = 0;
int cx[maxn],cy[maxn];//cx表示左边匹配到的右边的节点
bool vis[maxn];
struct Edge{
	int to,nex;
}e[maxn*maxn];
void init(){
	cntt = 0;
	per(i,1,n){
		head[i] = -1;
		vis[i] = false;
	}
}
void add_edge(int from,int to){
	e[++cntt].to = to;
	e[cntt].nex = head[from];
	head[from] = cntt;
}
bool judge(int x){//判断两个数的异或和是否只有一个1
	int cnt = 0;
	while(x > 0){//每次都去除最右边的1，比直接位运算要快
		x = x & (x-1);
		++cnt;
	}
	return cnt == 1;
}
int path(int u){
	vis[u] = true;
	for(int i = head[u];i != -1;i = e[i].nex){
		int v = e[i].to;
		if(!color[v] && !vis[v]){
			vis[v] = true;
			if(cy[v] == -1 || path(cy[v])){
				cx[u] = v;cy[v] = u;
				return 1;
			}
		}
	}
	return 0;
}
int max_match(){
	int sum = 0;
	memset(cx,-1,sizeof(cx)); memset(cy,-1,sizeof(cy));
	per(i,1,n){
		if(color[i]&1){
			memset(vis,false,sizeof(vis));//每次寻找增广路要初始化
			sum += path(i);
		}
	}
	return sum;
}
int main(){
	while(~scanf("%d",&n)){
		init();
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		per(i,1,n){
			int tmp = a[i];
			int cnt = 0;
			while(tmp > 0){//根据该数有奇数个1还是偶数个1分成左边和右边
				cnt += (tmp&1);
				tmp >>= 1;
			}
			color[i] = cnt&1;
		}
		per(i,2,n){
			per(j,1,i-1){
				if(judge(a[i] ^ a[j])){
					if(color[i]&1){
						add_edge(i,j);
					}else{
						add_edge(j,i);
					}
				}
			}
		}
		/*
			对于连通图，最大匹配+最小边覆盖 = N（节点的数量)
			最大独立集+最小顶点覆盖=N
			对于二分图，最小顶点覆盖=最大匹配
			所以，最大独立集+最大匹配 = N；
		*/
		int ans = max_match();
		ans = n - ans;
		printf("%d\n",ans);
		memset(vis,false,sizeof(vis));
		/*
		最大独立集方案的输出，从左边的没有匹配的点出发跑增广路，最后
		左边访问的点，和右边没有被访问的点就是最大独立集的一种方案
		*/
		per(i,1,n){
			if(color[i] && cx[i] == -1){
				path(i);
			}
		}
		per(i,1,n){
			if(color[i] && vis[i]){
				printf("%d ",a[i]);
			}
			if(!color[i] && !vis[i]){
				printf("%d ",a[i]);
			}
		}
		printf("\n");
	}


	return 0;
}