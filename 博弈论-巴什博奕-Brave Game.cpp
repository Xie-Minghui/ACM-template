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
const int maxn = 3e5;
int n = 0,m = 0;
/*
���n=m+1,��Ϊ���ȡm�����������õ����ö��ٸ������õ�����ȫ���ߡ�
�ɴ˿����ܽ�� ȡʤ�ؼ��� n=(m+1)*r+s ?(rΪ������Ȼ����sΪС�ڵ���m����
��ô��ȡ������s����Ʒ�������ȡ������K����m��������ô��ȡ�߿϶���ʤ��
��֮��Ҫ���ָ��������£�m+1���ı�������������ʤ��
���ǣ������ⷨ�ͳ����ˣ�ֻҪ�ж� n%(m+1)�Ƿ���ڵ���0��
����0����������ôȡ����󶼻�ʣ��<=m������˺�ȡ�߽����ʤ��
*/
int main(){
	
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		if((n % (m+1)) != 0){
			printf("first\n");
		}else{
			printf("second\n");
		}
	}
	
	return 0;
}

