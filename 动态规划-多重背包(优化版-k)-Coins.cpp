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
const int maxn = 1e5;
int n = 0,m = 0;
struct node{
	int val,num;
};
node coin[maxn+10];
bool dp[maxn+10];//�����ö�ά���飬������MLE,Ҫ������ά
int cnt[maxn+10]; 
bool cmp(node a,node b){
	return a.val != b.val ? a.val < b.val : a.num < b.num;
}
void solve(){
	fill(dp,dp+(maxn+10),false);
	dp[0] = true;
	per(i,1,n){
		fill(cnt,cnt+maxn+10,0);
		per(j,0,m){//������Ϊ�ǴӸ��º��״̬�˳������j��״̬�� 
			if(dp[j] == true){//��Ҫ����������cnt��+1,���¹���ѡ���i�ֿ������������� 
				continue;//Ϊ�˱�֤ʹ�����ٵĵ�i�ֿ����ճ�j 
			}
			if(j >= coin[i].val && dp[j-coin[i].val] && 
			cnt[j - coin[i].val] < coin[i].num){
				dp[j] = dp[j - coin[i].val];
				cnt[j] = cnt[j-coin[i].val] + 1;
			} 
		}
	}
	int ans = 0;
	per(i,1,m){
		ans += dp[i] ? 1 : 0; 
	}
	printf("%d\n",ans);
}
int main(){
	while(~scanf("%d %d",&n,&m) && ( m +n )){
		per(i,1,n){
			scanf("%d",&coin[i].val);
		}
		per(i,1,n){
			scanf("%d",&coin[i].num);
		}
		//sort(coin+1,coin+1+n,cmp);//�����Ƕ���� 
		solve();
	}
	return 0;
}

