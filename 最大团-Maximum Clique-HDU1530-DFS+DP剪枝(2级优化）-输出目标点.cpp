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
const int maxn = 50;
int n = 0,m = 0;
int mp[maxn+10][maxn+10];
int dp[maxn+10];
int clique[maxn+10],cli[maxn+10],tmp[maxn+10];//clique�洢���ս����cli�洢��ǰԪ�������е�Ĺ�ϵ 
int ans = 0;
/*
����Ż���α�֤����ĵ���֮ǰ�ĵ㶼������
 
*/
void dfs(int depth,int now){
	if(depth + (n - now) + 1 <= ans || dp[now] + depth <= ans){
		return ;
	}
	int t_cli[maxn+10];
	int able = 0;//����ж��ٸ��㣨�����ڵĵ�ĸ����� 
	for(int i = now;i <= n;++i){
		t_cli[i] = cli[i];
		if(cli[i] == 1){
			++able;
		}
	}
	if(able + depth <= ans){
		return ;
	}
	for(int i = now;i <= n;++i){
		if(t_cli[i] == 0){//�ų�����Щ����֪�㲻���ڵĵ� ���൱��֮ǰģ���is_clique���� 
			continue;
		}
		for(int j = now;j <= n;++j){
			cli[j] = t_cli[j] & mp[i][j];//cli[j]��ʾ����ǰ�ڵ�now���ڵĽڵ����ڽڵ�
			//�����´εݹ����able��ֵ 
		}
		tmp[depth+1] = i;
		//cout << i << endl;
		dfs(depth+1,i);
	}
	if(depth > ans){
		ans = depth;
		memcpy(clique,tmp,sizeof(tmp));
	}
}
int max_tuan(){
	dp[n] = 1;ans = 1;
	for(int i = n-1;i >= 1;--i){
		for(int j = 1;j <= n;++j){
			cli[j] = mp[i][j];
		} 
		tmp[1] = i;
		dfs(1,i+1);
		dp[i] = ans;
	}
	return ans;
}
int main(){
	while(~scanf("%d",&n) && n){
		memset(dp,sizeof(dp),0);
		per(i,1,n){
			per(j,1,n){
				scanf("%d",&mp[i][j]);
			}
		} 
		printf("%d\n",max_tuan());
		
		int num = max_tuan();//�������ŵĵ� 
		per(i,1,num){
			printf("%d%c",clique[i],i == num ? '\n':' ');
		}
	}
	
	return 0;
}

