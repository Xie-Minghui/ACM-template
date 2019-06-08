#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
struct node{
    int v,id;
};
vector<node> g[N+10];
int dfn[N+10],dfs_clock,cntCut;
int n,m,i,a,b,t;
int dfs(int u, int id){
    int lowu = dfn[u] = ++dfs_clock;
    int lowv,i,v;
    for(i=0; i<g[u].size();++i){
        v = g[u][i].v;
        if(!dfn[v]){
            lowv = dfs(v,g[u][i].id);
            lowu = min(lowu,lowv);
            if(lowv > dfn[u])
                cntCut++;
        }
        else if(id/2 != g[u][i].id/2 &&dfn[v]<lowu)//如果刚才走过来的边的id/2和这个边的id/2不相等，那么说明这两条有向边不是从一条边分离出来的
            lowu = dfn[v];
    }
    return lowu;
}
void init(){
    for(int i = 1;i <= n;++i){
        g[i].clear();
    }
    memset(dfn,0,sizeof(dfn)); dfs_clock = 0;cntCut = 0;
}
int main(){
    
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        init();
       
        for(i=0; i<m; ++i){
            scanf("%d%d",&a,&b);
            node t;
            t.v = a;
            t.id = i * 2;//给边编号
            g[b].push_back(t);
            t.v = b;
            t.id = i * 2 + 1;
            g[a].push_back(t);
        }
        for(int i = 1;i <= n;++i){
            if(dfn[i] == 0){
                dfs(i,-2);
            }
        }
        printf("%d\n",cntCut);
    }
    return 0;
}