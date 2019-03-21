
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
int f[101];//���鼯�õĲ�������
int u[10000];//�ߵĶ���
int v[10000];//�ߵĶ���
int w[10000];//�ߵ�Ȩֵ
int r[10000];//�ߵ����
int flag[10000];//�������
//��ѯ���ĸ� 
int find(int i)//���鼯�ṹ
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
    sort(r + 1, r + m + 1, cmp);//����Ȩֵ��С��������
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
            flag[e] = 1;//��ǵ�һ��Ѱ����С�������õ��ı�
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
        if(e == hehe) continue;//����ǲ����ǵı߾�����
        int rx = find(u[e]);
        int ry = find(v[e]);
        if(rx != ry)			//�ж����������Ƿ�����ͬһ������ 
        {
            f[rx] = ry;
            ans += w[e];
        }
    }
    return ans;
}
 
bool Full()//���Ƿ��ܹ�����С������
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
       for(int i = 1; i <= n; i++)//��ʼ��
       {
           f[i] = i;
       }
       for(int i = 1; i <= m; i++)
       {
           scanf("%d %d %d",&u[i],&v[i],&w[i]);
           r[i] = i;//��ʼ��
           flag[i] = 0;
       }
       int tmp = 0;
       int ans1 = Kruskal();
       for(int i = 1; i <= m; i++)
       {
           if(flag[i] == 0)
               continue;
           for(int j = 1; j <= n; j++)//����ÿ�ζ���Ҫ���³�ʼ�� f ����
           {
               f[j] = j;
           }
           int ans2 = Kruskal2(i);//Ѱ�Ҳ��õ��� i ����С������
           if(ans1 == ans2 && Full())//��Ҫ�����޷��γ���С������(��û�н����еĵ�������)
		   //��ȴ�պ��з���ֵ��ȵ����(һ���ֵ����ı�Ȩֵ��)
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

