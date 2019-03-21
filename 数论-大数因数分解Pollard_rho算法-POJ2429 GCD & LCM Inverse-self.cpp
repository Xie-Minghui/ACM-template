#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
//#define INF 0x3f3f3f//使用这个INF会WA 
using namespace std;
typedef long long int;
const int INF=(int)1<<61;
const int maxn = 2e5;
const int times = 100;
map<int,int> mp;
int cnt = 0;
int gc = 0,lc = 0,c = 234237,k = 0;
int minv = INF;
int resa = 0,resb = 0;
int gcd(int a,int b){
	return b == 0 ? a : gcd(b,a%b);
}

int q_mul(int a,int b,int mod){
	int res = 0;
	while(b > 0){
		if(b & 1){
			res = (res + a) % mod;
		}
		a = (a + a) % mod;
		b >>= 1;
	}
	return res;
}

int q_pow(int a,int b,int mod){
	int res = 1;
	while(b > 0){
		if(b & 1){
			res = q_mul(res,a,mod);
		}
		a = q_mul(a,a,mod);
		b >>= 1;
	}
	return res;
}

bool witness(int a,int n){
	int temp = n - 1;
	int j = 0;
	while(temp % 2 == 0){
		temp /= 2;
		j++;
	}
	//a^r ≡ 1 mod n或者对某个j (0 ≤ j≤ s-1, j∈Z) 与 a^(2jr) ≡ 1 mod n
	int x = q_pow(a,temp,n);
	if(x == n-1 || x == 1){//条件1是否满足 
		return true;
	}
	while(j--){//条件2是否满足 
		x = q_mul(x,x,n);
		if(x == n-1){
			return true;
		}
	}
	return false;
}
bool Miller_rabin(int n){
	if(n == 2){
		return true;
	}
	if(n < 2 || (n % 2 == 0  && n != 2)){
		return false;
	}
	for(int i = 0;i < times;++i){
		int r = rand() % (n - 2) + 1;//n-1和n-2都可以 
		if(witness(r,n) == false){
			return false;
		}
 	}
	return true;
}

int pollard_rho(int n,int c){
	int i = 1,k = 2;
	int x = rand() % (n-1) + 1;
	int y = x;
	while(true){
		i++;
		x = (q_mul(x,x,n) + c) % n;
		int d = gcd(y - x,n);
		if(1 < d && d < n){
			return d;
		}
		if(y == x){
			return n;
		}
		if(i == k){
			y = x;
			k <<= 1;
		}
	}
}
void find(int n,int c){
	if(n == 1){
		return ;
	}
	if(Miller_rabin(n) == true){
		mp[n]++;
		return ;
	}
	int p = n;
	while(p >= n){
		p = pollard_rho(p,c--);
	}
	find(p,c);find(n/p,c);
}
void dfs(int depth,int a){
	if(depth == cnt){
		int b = k / a;
		if(gcd(a,b) == 1){
			if(a + b < minv){
				minv = a + b;
				resa = a;resb = b;
			}
		}
		return ;
	}
	map<int,int>::iterator it = mp.begin();
	for(int i = 0;i < depth;++i){
		it++;
	}
	//cout << "hah " << it->first << " " << it->second << endl;
	int temp = q_pow(it->first,it->second,INF);
	//cout << temp << endl;
	if(a * temp < minv){
		dfs(depth + 1,a * temp);
	}
	if(a < minv){
		dfs(depth + 1,a);
	}
}
void solve(int n,int c){
	find(k,c);
	cnt = mp.size();
	/*
	map<int,int>::iterator it = mp.begin();
	for(it = mp.begin();it != mp.end();it++){
		cout << "em " << it->first << " " << it->second << endl;
	}
	*/
	dfs(0,1); 
	if(resa > resb){
		swap(resa,resb);
	}
	printf("%I64d %I64d\n",resa * gc,resb * gc);
}
int main(){

	while(~scanf("%I64d %I64d",&gc,&lc)){
		minv = INF;
		c = 2137342; 
		mp.clear();
		k = lc / gc;
		solve(k,c);
	}
	return 0;
}
