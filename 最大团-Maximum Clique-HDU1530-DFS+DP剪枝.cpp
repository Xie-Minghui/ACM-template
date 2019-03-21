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
int clique[maxn+10];
int ans = 0;
int dp[maxn+10];//����dp�����͸��Ӷȣ����ǿ��ԴӺ���ǰö�ٵ㣬
//dp[i]��ʾ��i�������֮���������ɵ����ֵ����ô���һ�������dp[n]=1
//��Ϊֻ��һ���㣬
//Ȼ������㣬�øĵ������������п��Ƿ��ܼ���͸������ֵ�� 
bool is_clique(int end,int now){
	for(int i = 1;i < end;++i){
		if(mp[clique[i]][now] == 0){
			return false;
		}
	}
	return true;
}
void dfs(int depth,int now){
//	if(depth > ans){
	//	ans = depth;
	//}
	if(depth + dp[now] <= ans){//�ȺŲ���ȱ�٣�����TLE������ļ�֦Ҳ��һ���� 
		return ;
	}
	if(depth + (n - now) + 1 <= ans){//��֦���Ѿ�û�гɹ���ϣ���� 
		return ;
	}
	for(int i = now;i <= n;++i){//���յ�����˳���֦ 
		if(is_clique(depth+1,i)){//�ж��µ���ԭ���ĵ��Ƿ���ͨ 
			clique[depth+1] = i;//��������ż��� 
			dfs(depth + 1 , i); 
		}
	}

	if(depth > ans){
		ans = depth;
	}
	
}
int main(){
	while(~scanf("%d",&n) && n){
		//memset(mp,0,sizeof(mp));//������Բ���ʼ��������ĸ�ֵ���Զ����� 
		per(i,1,n){
			per(j,1,n){
				scanf("%d",&mp[i][j]);
			}
		}
		memset(dp,0,sizeof(dp));
		ans = 1;//��ʼֵΪ1 
		dp[n] = 1;
		for(int i = n-1;i >= 1;--i){
			clique[1] = i;//���ֵ�һ�����Ѿ�ȷ���ģ�����ֱ��д�������Ż�һ�� 
			dfs(1,i+1);
			//dfs(0,i+1);//��ǰ����ע�͵��������л�WA 
			dp[i] = ans;
		}
		//dfs(0,1);
		printf("%d\n",ans);
	}
	
	return 0;
}

