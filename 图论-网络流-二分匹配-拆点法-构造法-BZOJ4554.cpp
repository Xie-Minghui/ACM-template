#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#define N 2500

using namespace std;

int n,m,cnt,cntx,cnty,Ans;
int G[N],match[N],vis[N];
int x[55][55],y[55][55];
char A[55][55];
struct edge{
  int t,nx;
}E[N<<1];

inline void add(int x,int y){
  E[++cnt].t=y; E[cnt].nx=G[x]; G[x]=cnt;
}

bool check(int x){
  for(int i=G[x];i;i=E[i].nx)
    if(!vis[E[i].t]){
      vis[E[i].t]=1;
      if(!match[E[i].t]||check(match[E[i].t])){
    match[E[i].t]=x;
    return 1;
      }
    }
  return 0;
}

int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++){
    scanf("%s",A[i]+1); cntx++;
    for(int j=1;j<=m;j++){
      if(A[i][j]=='#') cntx++;
      x[i][j]=cntx;
    }
  }
  for(int i=1;i<=m;i++){
    cnty++;
    for(int j=1;j<=n;j++){
      if(A[j][i]=='#') cnty++;
      y[j][i]=cnty;
    }
  }
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      if(A[i][j]=='*') add(x[i][j],y[i][j]);
  for(int i=1;i<=cntx;i++){
    memset(vis,0,sizeof(vis));
    Ans+=check(i);
  }
  printf("%d\n",Ans);
}