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
const int ma = 2e5;
const int mod = 1e8 + 7;
int n = 0,m = 0;
LL a[300+10];
LL dp[2][2*ma+1000];
/*
dp[i][j]��ǰ���iֻ��0,1����ȡֵ��ʹ���˹������飬�����˵�ǰ״̬������һ��״̬
j��ʾ��ǰ�ķ�����
����Ҫ���������������ԭ��������[-ma,ma]���[0,2*ma],�������������ӳ�䵽[0,ma]��ôj-a[i]��
���ܻ���ָ��������԰�ԭ��������ӳ�䵽[ma,2*ma],�����ʹ����˸�������� 
*/
int main(){
	while(~scanf("%d",&n)){
		per(i,1,n){
			scanf("%lld",&a[i]);
		}
		memset(dp,0,sizeof(dp));
		dp[0][ma] = 1;
		per(i,1,n){
			int num = i&1;
			memset(dp[num],0,sizeof(dp[num]));
			per(j,2000,2*ma){
				if(j ==  ma + 666){
					dp[num][j] = 0;
				}else{
					dp[num][j] = (dp[num^1][2*ma-j] +dp[num^1][j-a[i]]) % mod;	
				}
			}
			
		}
		printf("%lld\n",dp[n&1][ma-666]);
	}
	return 0;
}

