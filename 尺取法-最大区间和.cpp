#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string> 
#include<cstring>
#include<set>
#define INF 0x7fffffff
using namespace std;
const int maxn = 100000 + 10;
int a[maxn];
int main(){
	int T = 0,n = 0;
	cin >> T;
	int kase = 0;
	while(T--){
		cin >> n;
		for(int i = 1;i <=n;++i){
			cin >> a[i];
		}
		
		int start = 1,end = 1;//���մ� 
		int s = 1,e = 1;//��¼��ǰλ��
//start��ʼλ�ã�end��βλ��,sumΪ�������ֵĺͣ�sΪ��ʼλ�ñ�����
//��start�йأ�eΪ��βλ�ñ���,maxΪ��������ֵ
		int max = a[1],sum = 0; 
		for(int j = 1;j <= n;++j){
			sum += a[j];
			e = j;		//��¼���㵽��λ�ã�Ҳ��ĩλ��
			if(sum > max){		//�������ֵ 
				max = sum;
				start = s,end = e;
			}
			if(sum < 0){		//��Ŀǰ�ĺ�С��0ʱ������һλ���¿�ʼ 
				s = j + 1;		//��¼���������ʼλ��
				sum = 0;
			}
		}
		if(kase > 0){
			cout << endl;
		}
		cout << "Case " << ++kase << ":" << endl;
		cout  << max << " " << start << " " << end << endl;
	
		
	}
	
	
	
	
	return 0;
}
