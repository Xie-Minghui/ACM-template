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
int id[30],back[maxn+10];//id���ڴ�Ҫ�� 
void dfs(int cur,int bw){
	if(cur == n){
		//if(bw != 0 && bw < ans){//������жϣ��ܽ��뵽��һ�㣬һ����������Щ�������ܽ�����һ��ع�������� 
		memcpy(sy,s,sizeof(s));
		ans = bw; 
		//}
		return ;
	}
	
	for(int i = 0;i < n;++i){
		if(vis[i]){
			continue;
		}
		int tmp = bw;//bwҲҪ�ڲ�ͬ��ѡ��ԭ 
		s[cur] = i;
		//�����뻯��֦
		 
		per(j,0,cur-1){
			if(mp[i][s[j]] == 1 || mp[s[j]][i] == 1){
				bw = max(bw,cur-j);
				//j = cur;//�˳�����ѭ�� 
				break;
			}
		}
		if(bw < ans){//�����Լ�֦ 
			vis[i] = true;
			dfs(cur+1,bw);
			vis[i] = false;
		} 
		bw = tmp;//ͬһ���ѡ��֮�以��Ӱ�� 
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
		for(it = it;it != st.end();++it){//ӳ�䣬һֱWA��ԭ������Ŀ��������ĸ��һ�������ڵģ�������ĸ��Χ����A-H
		//�п�����A��Z������ĸ 
			id[*it] = cnt;//ѹ��������mp�Ŀռ� 
			back[cnt++] = *it;//��ԭ�� 
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

