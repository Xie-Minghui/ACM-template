
/*
 * Author: Gatevin
 * Created Time:  2014/4/23 22:26:58
 * File Name: the_unique_MST.cpp
 */
//MST, disjoint set, enumeration
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
using namespace std;
const double eps(1e-8);
typedef long long lint;
#define clr(x) memset( x , 0 , sizeof(x) )
#define sz(v) ((int)(v).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rise(i, a, b) for (int i = (a); i <= (b); i++)
#define fall(i, a, b) for (int i = (a); i >= (b); i--)
#define clrs( x , y ) memset( x , y , sizeof(x) )
 
int t,n,m;
int f[101];//并查集用的查找数组
int u[10000];//边的顶点
int v[10000];//边的顶点
int w[10000];//边的权值
int r[10000];//边的序号
int flag[10000];//标记数组
//查询树的根 
int find(int i)//并查集结构
{
    if(i != f[i])
    {
        f[i] = find(f[i]);
    }
    return f[i];
}
 
bool cmp(const int& i, const int& j)
{
    return w[i] < w[j];
}
 
int Kruskal()
{
    sort(r + 1, r + m + 1, cmp);//按边权值从小到大排序
    int ans = 0;
    for(int i = 1; i <= m; i++)
    {
        int e = r[i];
        int rx = find(u[e]);
        int ry = find(v[e]);
        if(rx != ry)
        {
            f[rx] = ry;
            ans += w[e];
            flag[e] = 1;//标记第一次寻找最小生成树用到的边
        }
    }
    return ans;
}
 
int Kruskal2(int hehe)
{
    int ans = 0;
    for(int i = 1; i <= m; i++)
    {
        int e = r[i];
        if(e == hehe) continue;//如果是不考虑的边就跳过
        int rx = find(u[e]);
        int ry = find(v[e]);
        if(rx != ry)			//判断两个顶点是否属于同一个集合 
        {
            f[rx] = ry;
            ans += w[e];
        }
    }
    return ans;
}
 
bool Full()//看是否能构成最小生成树
{
    for(int i = 1; i <= n; i++)
    {
        if(find(i) != find(1))
            return false;
    }
    return true;
}
 
int main()
{
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d %d",&n,&m);
       for(int i = 1; i <= n; i++)//初始化
       {
           f[i] = i;
       }
       for(int i = 1; i <= m; i++)
       {
           scanf("%d %d %d",&u[i],&v[i],&w[i]);
           r[i] = i;//初始化
           flag[i] = 0;
       }
       int tmp = 0;
       int ans1 = Kruskal();
       for(int i = 1; i <= m; i++)
       {
           if(flag[i] == 0)
               continue;
           for(int j = 1; j <= n; j++)//这里每次都需要重新初始化 f 数组
           {
               f[j] = j;
           }
           int ans2 = Kruskal2(i);//寻找不用到边 i 的最小生成树
           if(ans1 == ans2 && Full())//需要考虑无法形成最小生成树(既没有将所有的点连起来)
		   //但却刚好有返回值相等的情况(一部分的树的边权值和)
           {
               tmp = 1;
               break;
           }
       }
       if(tmp){
           printf("Not Unique!\n");
       }
       else{
           printf("%d\n",ans1);
       }
   }
   return 0;
}

