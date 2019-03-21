#include <iostream> 
#include <cstdio> 
#include <algorithm>  
#include <cmath>  
#include <cstring>  
#include <map>  
using namespace std;
 
const int times = 20;
int number = 0;
 
map<long long, int>m;
long long Random( long long n )			//生成[ 0 , n ]的随机数
{
	return ((double)rand( ) / RAND_MAX*n + 0.5);
}
 
long long q_mul( long long a, long long b, long long mod ) //快速计算 (a*b) % mod
{
	long long ans = 0;
	while(b)
	{
		if(b & 1)
		{
			//b--;
			ans =(ans+ a)%mod;
		}
		b /= 2;
		a = (a + a) % mod;
 
	}
	return ans;
}
 
long long q_pow( long long a, long long b, long long mod ) //快速计算 (a^b) % mod
{
	long long ans = 1;
	while(b)
	{
		if(b & 1)
		{
			ans = q_mul( ans, a, mod );
		}
		b /= 2;
		a = q_mul( a, a, mod );
	}
	return ans;
}
 
bool witness( long long a, long long n )//miller_rabin算法的精华
{//用检验算子a来检验n是不是素数
	long long tem = n - 1;
	int j = 0;
	while(tem % 2 == 0)
	{
		tem /= 2;
		j++;
	}
	//将n-1拆分为a^r * s
 
	long long x = q_pow( a, tem, n ); //得到a^r mod n
	if(x == 1 || x == n - 1) return true;	//余数为1则为素数
	while(j--) //否则试验条件2看是否有满足的 j
	{
		x = q_mul( x, x, n );
		if(x == n - 1) return true;
	}
	return false;
}
 
bool miller_rabin( long long n )  //检验n是否是素数
{
 
	if(n == 2)
		return true;
	if(n < 2 || n % 2 == 0)
		return false;				//如果是2则是素数，如果<2或者是>2的偶数则不是素数
 
	for(int i = 1; i <= times; i++)  //做times次随机检验
	{
		long long a = Random( n - 2 ) + 1; //得到随机检验算子 a
		if(!witness( a, n ))						//用a检验n是否是素数
			return false;
	}
	return true;
}
 
 
int main( )
{
	long long tar;
	while(cin >> tar)
	{
		if(miller_rabin( tar ))	//检验tar是不是素数
			cout << "Yes, Prime!" << endl;
		else
			cout << "No, not prime.." << endl;
	}
	return 0;
}

