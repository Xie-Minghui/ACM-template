#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

typedef long long LL;

#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
const int maxn = 100;
int n = 0,k = 0;
int ball[maxn+1][maxn+10];
vector<pii> vt[50+10];
int cx[maxn+10],cy[maxn+10];
bool vis[maxn+10];
int px[maxn+10],py[maxn+10];

int cntx = 0,cnty = 0;
int path(int u,int color){
	for(int i = 1;i <= cnty;++i){
		if(vis[cy[i]] == false && ball[u][cy[i]] == color){
			vis[cy[i]] = true;
			if(py[cy[i]] == -1 || path(py[cy[i]],color)){
				px[u] = cy[i];py[cy[i]] = u;//之前这里没写导致WA 
				return 1;
			}
		}
	}
	return 0; 
}
int max_match(int color){
	memset(px,-1,sizeof(px));memset(py,-1,sizeof(py));
	int sum = 0;
	for(int j = 1;j <= cntx;++j){
		if(px[cx[j]] == -1){
			memset(vis,false,sizeof(vis));
			sum += path(cx[j],color);
		}
	}
	return sum;
}
int main(){
	while(~scanf("%d %d",&n,&k) && n && k){
		set<int> st,sc,sx,sy;
		memset(ball,0,sizeof(ball));
		for(int i = 1;i <= 50;++i){//不要忘记初始化了 
			vt[i].clear();
		} 
		per(i,1,n){
			per(j,1,n){
				scanf("%d",&ball[i][j]);
				vt[ball[i][j]].push_back(pii(i,j));
				sc.insert(ball[i][j]);//记录有哪几种颜色 
			}
		}
		set<int>::iterator ic = sc.begin();//
		for(ic = sc.begin();ic != sc.end();++ic){//遍历每种颜色 
			int i = *ic;
			cntx = 0,cnty = 0;
			for(int j = 0;j < vt[i].size();++j){
				sx.insert(vt[i][j].first);sy.insert(vt[i][j].second);
				//记录有哪些行列，避免重复 
				//cx[++cnt] = vt[i][j].first;//这里面有重复 
				//cy[cnt] = vt[i][j].second;
			}
			set<int>::iterator it;
			for(it = sx.begin();it != sx.end();++it){
				cx[++cntx] = *it;
			}
			for(it = sy.begin();it != sy.end();++it){
				cy[++cnty] = *it;
			}
			int sum = max_match(i);
			if(sum > k){
				st.insert(i);
			}
		} 
		if(st.size() == 0){
			printf("-1\n");
		}else{
			set<int>::iterator it = st.begin();
			printf("%d",*it);
			it++;
			for(it = it;it != st.end();++it){
				printf(" %d",*it);
			}
			printf("\n");
		}
	}
	
	return 0;
}

