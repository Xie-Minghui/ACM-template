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
int q_mul(int a,int b,int mod){//���ٳ˷�,a*b 
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
bool witness(int a,int n){//Miller_rbin()�㷨�ľ������� 
	
	int temp = n - 1;//��n-1 
	int j = 0;
	while(temp % 2 == 0){
		temp /= 2;
		j++;	
	}
	int x = q_pow(a,temp,n);//����a^r
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
bool Miller_rbin(int n){//��֤һ�������� 
	
	if(n == 2){//������˳���ܱ� ����Ϊ����������ᱻ�����ڵڶ����ж����浫��Ҫ���ж� 
		return true;
	}
	if(n < 2 || n % 2 == 0){//����жϱ����ں��棬��� 
		return false;
	}
	per(i,1,times){
		int a = Random(n - 2) + 1;
		if(witness(a,n) == false){//����times��֤֮��������Ƿ��ϵģ�
		//����Ϊ���������� 
			return false;
		}
	}
	
	return true;
}
int pollard_rho(int n,int c){//����һ�������� 
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
		if(i == k){//һ�ֲ�������Ż� 
			y = x;
			k <<= 1;
		}
	}
} 
void find(int n,int c){//c��������� 
	if(n == 1){
		return ;
	}
	if(Miller_rbin(n) == true){//��֤���Ƿ��������� 
		number++;
		mp[n]++;
		return ;
	}
	
	int p = n;
	while(p >= n){
		p = pollard_rho(p,c--);//�ҵ�һ�������� 
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
