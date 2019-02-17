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
const int maxn = 10;
int n = 0,m = 0; 
//string str;
char str[1000];
//vector<int> vt[maxn];
int s[maxn+10],sy[maxn+10];
int mp[maxn+2][maxn+2];
int ans = 20;
bool vis[maxn+10];
int id[30],back[maxn+10];//id的内存要够 
void dfs(int cur,int bw){
	if(cur == n){
		//if(bw != 0 && bw < ans){//多余的判断，能进入到这一层，一定会满足这些条件（能进行下一层地柜的条件） 
		memcpy(sy,s,sizeof(s));
		ans = bw; 
		//}
		return ;
	}
	
	for(int i = 0;i < n;++i){
		if(vis[i]){
			continue;
		}
		int tmp = bw;//bw也要在不同的选择还原 
		s[cur] = i;
		//最理想化剪枝
		 
		per(j,0,cur-1){
			if(mp[i][s[j]] == 1 || mp[s[j]][i] == 1){
				bw = max(bw,cur-j);
				//j = cur;//退出两重循环 
				break;
			}
		}
		if(bw < ans){//最优性剪枝 
			vis[i] = true;
			dfs(cur+1,bw);
			vis[i] = false;
		} 
		bw = tmp;//同一层的选择之间互不影响 
	}
}
int main(){
	//std::ios::sync_with_stdio(false);
	while(~scanf("%s",str) && str[0] != '#'){
		memset(vis,false,sizeof(vis));
		memset(mp,0,sizeof(mp));
		ans = 20;
		set<int> st;
		//if(strcmp(str,"#") == 0){
		//	break;
		//}
		int size = strlen(str);
		per(j,0,size-1){
			if(isalpha(str[j])){
				st.insert(str[j] - 'A');
			}
		}
		int cnt = 0;
		set<int>::iterator it = st.begin();
		for(it = it;it != st.end();++it){//映射，一直WA的原因是题目所给的字母不一定是相邻的，所以字母范围不是A-H
		//有可能是A和Z两个字母 
			id[*it] = cnt;//压缩，减少mp的空间 
			back[cnt++] = *it;//还原答案 
		} 
		int i = 0;
		while(i < size){
			int node = str[i] - 'A';
			i += 2;
			while(i < size && str[i] != ';'){
				mp[id[str[i] - 'A']][id[node]] = 1;
				mp[id[node]][id[str[i] - 'A']] = 1;
				++i;
			}
			++i;
		}
	
		n = st.size();
		dfs(0,0);
		per(j,0,n-1){
			printf("%c ",'A' + back[sy[j]]);
		}
		printf("-> %d\n",ans);
	}
	
	return 0;
}

