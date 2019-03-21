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
const int maxn = 1e4;
int n = 0;
int a[maxn+10],pre[maxn+10];
int mod[maxn+10];
/*
�볲ԭ�������: 
��ǰ׺�ͣ�pre%n��n�п��ܣ����mod == 0����ô1->i��������Ҫ�Ľ����
����%n��������1->n-1���ų�����Ϊ0����������й�n-1��״̬������n�����������Ա�Ȼ������������ȣ���ô������ȵ�
�����������Ǵ𰸡� 
*/
int main(){

	while(~scanf("%d",&n)){
		memset(pre,0,sizeof(pre));	memset(mod,0,sizeof(mod));
		bool flag = false;
		per(i,1,n){
			scanf("%d",&a[i]);
			if(flag == true){//�Ѿ�����˴𰸣�ֻҪ��ȡ���ݾͿ����� 
				continue;
			}
			pre[i] = pre[i-1] + a[i];
			if(pre[i] % n == 0){
				flag = true;
				printf("%d\n",i);
				per(j,1,i){
					printf("%d\n",a[j]);
				}
			}else{
				if(mod[pre[i] % n] != 0){
					flag = true;
					printf("%d\n",i - mod[pre[i] % n]);
					per(j,mod[pre[i]%n]+1,i){
						printf("%d\n",a[j]);
					}
				}else{
					mod[pre[i] % n] = i;
				}
			}
		}
	}
	
	return 0;
}

