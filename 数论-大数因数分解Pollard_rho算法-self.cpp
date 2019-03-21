#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define per(i,a,b) for(int i=a;i<=b;i++)

typedef long long int;

const int times = 20;
map<int,int> mp;
int number = 0;

int Random(int n){
	return ((double)rand() / RAND_MAX * n + 0.5);
}
int q_mul(int a,int b,int mod){//快速乘法,a*b 
	int ans = 0;
	while(b > 0){
		if(b & 1){
			ans = (ans + a) % mod;
		}
		b >>= 1;
		//b /= 2;
		a = (a + a) % mod;
	}
	return ans;
}
int q_pow(int a,int b,int mod){
	int ans = 1;
	while(b > 0){
		if(b & 1){
			ans = q_mul(ans,a,mod);
		}
		b >>= 1;
		//b /= 2;
		a = q_mul(a,a,mod);
	}
	return ans;
}
int gcd(int a,int b){
	return (b == 0) ? a : gcd(b,a % b);
}
bool witness(int a,int n){//Miller_rbin()算法的精华所在 
	
	int temp = n - 1;//是n-1 
	int j = 0;
	while(temp % 2 == 0){
		temp /= 2;
		j++;	
	}
	int x = q_pow(a,temp,n);//计算a^r
	if(x == 1 || x == n-1 ){
		return true;
	} 
	while(j--){
		x = q_mul(x,x,n);
		if(x == n-1){
			return true;
		}
	}
	return false;
}
bool Miller_rbin(int n){//验证一个质因数 
	
	if(n == 2){//这两个顺序不能变 ，因为这个条件，会被包含在第二个判断里面但是要先判断 
		return true;
	}
	if(n < 2 || n % 2 == 0){//这个判断必须在后面，想哭 
		return false;
	}
	per(i,1,times){
		int a = Random(n - 2) + 1;
		if(witness(a,n) == false){//进行times验证之后，如果还是符合的，
		//就认为他是质因数 
			return false;
		}
	}
	
	return true;
}
int pollard_rho(int n,int c){//生成一个质因数 
	int i = 1,k = 2;
	int x = Random(n-1) + 1;
	int y = x;
	
	while(true){
		i++;
		x = (q_mul(x,x,n) + c) % n ;
		int d = gcd(y-x,n);
		if(1 < d && d < n){
			return d;
		}
		if(y == x){
			return n;
		}
		if(i == k){//一种不清楚的优化 
			y = x;
			k <<= 1;
		}
	}
} 
void find(int n,int c){//c是随机因子 
	if(n == 1){
		return ;
	}
	if(Miller_rbin(n) == true){//验证它是否是质因数 
		number++;
		mp[n]++;
		return ;
	}
	
	int p = n;
	while(p >= n){
		p = pollard_rho(p,c--);//找到一个质因数 
	}
	find(p,c);	
	find(n/p,c);
} 
int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	int n = 0; 
	while(~scanf("%I64d",&n)){
		number = 0;
		mp.clear();
		int mi = 2137342;
		find(n, mi);
		printf("%I64d = ",n);
		if(mp.empty()){
			printf("%I64d\n",n);
		}
		map<int,int>::iterator it ;
		for(it = mp.begin();it != mp.end();){
			printf("%I64d^%d",it->first,it->second);
			if((++it) != mp.end()){
				printf(" * ");
			}
		}
		printf("\n");
	}
	
	return 0; 
}
