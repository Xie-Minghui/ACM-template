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
		
		int start = 1,end = 1;//最终答案 
		int s = 1,e = 1;//记录当前位置
//start起始位置，end结尾位置,sum为连续数字的和，s为起始位置变量，
//和start有关，e为结尾位置变量,max为所求的最大值
		int max = a[1],sum = 0; 
		for(int j = 1;j <= n;++j){
			sum += a[j];
			e = j;		//记录运算到的位置，也是末位置
			if(sum > max){		//更新最大值 
				max = sum;
				start = s,end = e;
			}
			if(sum < 0){		//当目前的和小于0时，从下一位重新开始 
				s = j + 1;		//记录新运算的起始位置
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
