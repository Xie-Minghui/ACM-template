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
int a[maxn+10];
int s[maxn+10];
int sm[maxn+10];//��¼��1-j����С��s���±�i,s[j] - s[i-1]��󣬹̶� s[j],�൱��ʹs[i-1]��С
//Ȼ��ɨ��һ�����飬ά��Ŀǰ����������СS
//���Ӷ�O(n) 

int main(){
	while(~scanf("%d",&n)){
		int l = 0,r = 0;//��¼��������Ķ˵�ֵ 
		memset(s,0,sizeof(s));
		 
		per(i,1,n){
			scanf("%d",&a[i]);
			s[i] = s[i-1] + a[i];
		}
		int mins = 0,min_id = 0;
		sm[1] = 0;
		per(i,2,n){//¼��1-i����С��sj���±�j ,s[j] - s[i-1]��󣬹̶� 
			if(s[i-1] < mins){//ȡ��ȡ�Ⱥţ�Ҫ����ʵ������� 
				mins = s[i-1];
				sm[i] = min_id = i-1;
			}else{
				sm[i] = min_id;
			}
		}
		int maxv = -INF;
		per(i,1,n){
			if(s[i] - s[sm[i]] > maxv){
				l = sm[i] + 1;r = i;
				maxv = s[i] - s[sm[i]];
			}
		}
		
		printf("%d %d : %d\n",l,r,maxv);
	}
	
	
	return 0;
}

