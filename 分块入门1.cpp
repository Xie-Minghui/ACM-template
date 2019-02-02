#include<map>
#include<set>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define mod 998244353
#define pi acos(-1)
#define inf 0x7fffffff
#define ll long long
using namespace std;
ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,blo;
int v[50005],bl[50005],atag[50005];
void add(int a,int b,int c)
{
    for(int i=a;i<=min(bl[a]*blo,b);i++)
        v[i]+=c;
    if(bl[a]!=bl[b])
        for(int i=(bl[b]-1)*blo+1;i<=b;i++)
            v[i]+=c;
    for(int i=bl[a]+1;i<=bl[b]-1;i++)
        atag[i]+=c;
}
int main()
{
    n=read();blo=sqrt(n);
    for(int i=1;i<=n;i++)v[i]=read();
    for(int i=1;i<=n;i++)bl[i]=(i-1)/blo+1;
    for(int i=1;i<=n;i++)
    {
        int f=read(),a=read(),b=read(),c=read();
        if(f==0)add(a,b,c);
        if(f==1)printf("%d\n",v[b]+atag[bl[b]]);
    }
    return 0;
}
