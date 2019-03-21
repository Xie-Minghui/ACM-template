#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6 + 100;
bool is_prime[maxn];
bool is_prime_small[maxn];
LL prime[maxn];

int segment_sieve(LL a,LL b){
	for(int i = 0;(LL)i * i < b;++i){
		is_prime_small[i] = true;
	}
	for(int i = 0;i < b - a;++i){//����ҿ����� 
		is_prime[i] = true;
	}
	for(int i = 2;(LL)i * i <= b;++i){
		if(is_prime_small[i]){
			for(int j = 2 * i;(LL)j	*j <= b;j += i){//ɸѡ(0,����b)������ 
				is_prime_small[j] = false;
			}
			for(LL j = max(2LL , ((a + i - 1)/i) * i);j < b;j += i){//ɸѡ[a,b)������ 
				if(j == i){//����ѱ���Ҳ 
					continue;
				}  
				is_prime[j-a] = false;
			}
		}
	}
	int cnt = 0;
	for(int i = 0;i < b-a;++i){
		if(is_prime[i] == true){
			cnt++;
			//cout << "em " << i << endl;
		}
	}
	return cnt; 
}

int main(){
	LL a = 0,b = 0;
	while(cin >> a >> b){
		cout << segment_sieve(a,b) << endl;
	}
	
	return 0;
}
