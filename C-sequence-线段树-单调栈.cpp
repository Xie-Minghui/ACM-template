#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 3e6 + 10;
const LL mod = (1e9 + 7);
int n = 0,m = 0,k = 0;
int a[maxn],b[maxn];
int sk[maxn];
LL pre[maxn];
struct STree{
    LL mi,ma;
    int l,r;
}st[maxn*5];
int al[maxn],ar[maxn];
void build(int root,int l,int r){
    st[root].l = l; st[root].r = r;
    if(l == r){
        st[root].mi = st[root].ma = pre[l];
    }else{
        int mid = (l + r) >> 1;
        build(root*2+1,l,mid);
        build(root*2+2,mid+1,r);    
        st[root].mi = min(st[root*2+1].mi,st[root*2+2].mi);
        st[root].ma = max(st[root*2+1].ma,st[root*2+2].ma);
    }   
}
LL query_min(int root,int l,int r){
    if(l > r){
        return INF;
    }
    int mid = (st[root].r + st[root].l) >> 1;
    // if(st[root].l > r || st[root].r < l){//这个和下面两个if判断同时注释掉
    //     return INF;//会段错误，另外这个部注释掉会WA，不能直接返回INF
    // }else //因为可能一次调用就直接返回了solve函数，此时会计算INF
    if(l <= st[root].l && st[root].r <= r){
        return st[root].mi;
    }else if(r <= mid){//二分，这边是<=，因为左孩子记录的是[l,mid]的信息
        return query_min(root*2+1,l,r);
    }else if(l > mid){
        return query_min(root*2+2,l,r);
    }else{
        return min(query_min(root*2+1,l,r),query_min(root*2+2,l,r));
    }
}
LL query_max(int root,int l,int r){
    if(l > r){
        return -INF;
    }
    int mid = (st[root].r + st[root].l) >> 1;
    // if(st[root].l > r || st[root].r < l){
    //     return -INF;
    // }else 
    if(l <= st[root].l && st[root].r <= r){
        return st[root].ma;
    }else if(r <= mid){//这两个if判断没有，会出现段错误
        return query_max(root*2+1,l,r);
    }else if(l > mid){
        return query_max(root*2+2,l,r);
    }else{
        return max(query_max(root*2+1,l,r),query_max(root*2+2,l,r));
    }
}
// void solve(){//下面是错误的算法
//     LL ans = -INF;
//     int head = 1,tail = 0;
//     sk[0] = 1;
//     per(i,1,n){
//         al[i] = ar[i] = i;
//         while(head <= tail && a[i] < a[sk[tail]]){
//             al[i] = al[sk[tail]];
//             ar[sk[tail]] = i-1;//记录弹出元素的右边缘
//             if(a[sk[tail]] >= 0){
//                 LL sum = query_max(0,sk[tail],ar[sk[tail]]) - query_min(0,al[sk[tail]]-1,sk[tail]-1);
//                 ans = max(ans,a[sk[tail]]*1ll * sum);
//                 // cout << "q1 " << ans << endl;
//             }else{
//                 LL sum = query_min(0,sk[tail],ar[sk[tail]]) - query_max(0,al[sk[tail]]-1,sk[tail]-1);
//                 ans = max(ans,a[sk[tail]]*1ll * sum);
//                 // cout << "q2 " << ans << endl;
//             }
//             --tail;
//         }
//         sk[++tail] = i;
//     }
//     while(head <= tail){
//         int now = a[sk[tail]],pos = sk[tail];
//         --tail;
//         // al[pos] = (tail != 0 ? sk[tail]+1 : 1);
//         al[pos] = sk[tail] + 1;
//          if(now >= 0){
//             LL sum = query_max(0,pos,n) - query_min(0,al[pos]-1,pos-1);
//             ans = max(ans,now*1ll * sum);
//             // cout << "q3 " << ans << endl;
//         }else{
//             LL sum = query_min(0,pos,n) - query_max(0,al[pos]-1,pos-1);
//             ans = max(ans,now*1ll * sum);
//             // cout << "q4 " << ans << endl;
//         }
//     }
//     printf("%lld\n",ans);
// }
void pre_solve(){
    /*
    还是要从顺序，逆序个跑一遍单调栈，分别确定右边界和左边界。
    注释掉的代码，算法是错诶的，因为对于相同的元素，你不能弹出，他们
    */
    int head = 1,tail = 0;
    per(i,1,n){//统计每个值（它可以作为min)的右边边界
        ar[i] = n;
        while(head <= tail && a[i] < a[sk[tail]]){
            ar[sk[tail]] = i-1;
            --tail;
        }
        sk[++tail] = i;
    }
    head = 1,tail = 0;
    rep(i,n,1){//统计每个值（它可以作为min)的左边边界
        al[i] = 1;
        while(head <= tail && a[i] < a[sk[tail]]){
            al[sk[tail]] = i+1;
            --tail;
        } 
        sk[++tail] = i;
    }

}
void solve(){
    LL ans = 0;
    per(i,1,n){
        if(a[i] >= 0){
            LL sum = query_max(0,i,ar[i]) - query_min(0,al[i]-1,i-1);
            ans = max(ans,a[i]*1ll * sum);
        }else{
            LL sum = query_min(0,i,ar[i]) - query_max(0,al[i]-1,i-1);
            ans = max(ans,a[i]*1ll * sum);
        }
    }
    printf("%lld\n",ans);
}
int main(){
    while(~scanf("%d",&n)){
        // init();
        per(i,1,n){
          scanf("%d",&a[i]);
        }
        per(i,1,n){
          scanf("%d",&b[i]);
          pre[i] = pre[i-1] + b[i];
        }
        pre_solve();
        build(0,1,n);
        solve();
    }

  return 0;
}