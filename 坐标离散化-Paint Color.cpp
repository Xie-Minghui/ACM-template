#include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<fstream>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define pii pair<int, int>
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define fil(a,b) fill(a,a+sizeof(a),b)
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define PER(i,x) for(auto i=x.begin();i!=x.end();i++)
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
typedef long long LL;
const double eps=1.0e-5;
const int maxn=500 + 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int cnt1=0,cnt2=0,cnt3=0,tmp = 0,a[maxn],b[maxn],c[maxn],ma=-inf,flag;
int n = 0,w = 0,h = 0; 
int xx1[maxn],xx2[maxn],yy1[maxn],yy2[maxn];//存储坐标 
//对x1,x2进行坐标离散化，并返回离散化后的宽度
bool fld[3*maxn][3*maxn];  
int compress(int* xx1,int* xx2,int w){
	vector<int> xs;
	per(i,0,n-1){
		per(d,-1,1){
			int tx1 = xx1[i] + d,tx2 = xx2[i] + d;
			if(1 <= tx1 && tx1 <= w ){//不是tx1>=0,而是>=1,因为坐标是从1开始的，
			//1是不行的,1是坐标的边界 
				xs.push_back(tx1);
			}
			if(1 <= tx2 && tx2 <= w){
				xs.push_back(tx2);
			}
		}
	}
	
	sort(xs.begin(),xs.end());
	xs.erase(unique(xs.begin(),xs.end()),xs.end());//删除去重数列的后面所有多余元素
	//因为unique并没有删除重复元素，只是用后面的不重复元素填充重复元素
	per(i,0,n-1){	//直线坐标压缩 
		xx1[i] = find(xs.begin(),xs.end(),xx1[i]) - xs.begin() + 1;
		xx2[i] = find(xs.begin(),xs.end(),xx2[i]) - xs.begin() + 1;
	} 
	return xs.size();
}
//压缩前的边界是1-w，压缩后是0-w-1，但是+1后就是1-w-1(而不是1-w),由于这道题加一
//之后后面的边界要减一，模板的左边是方块的坐标，而这道题是点的坐标，所以需要一些小转化 
void solve(){
	w = compress(xx1,xx2,w);
	h = compress(yy1,yy2,h);
	//fill(fld[0],fld[0]+9*maxn*maxn,false);
	mem(fld,false);
	per(i,0,n-1){//设置墙 
		per(x,xx1[i],xx2[i]-1){
			per(y,yy1[i],yy2[i]-1){
				fld[x][y] = true;
			}
		}
	}
	int ans = 0;
	per(x,1,w-1){
		per(y,1,h-1){//之前这里少见了1导致结果是27，而答案是6 
			if(fld[x][y] == true){
				continue;
			}
 			ans++;
			queue<pair<int,int> > que;
			que.push(make_pair(x,y));
			fld[x][y] = true;
			while(!que.empty()){
				int sx = que.front().first,sy = que.front().second;
				que.pop();
				per(i,0,3){
					int tx = sx + dx[i],ty = sy + dy[i];
					if(1 <= tx && tx < w && 1 <= ty && ty < h && fld[tx][ty] != true){
						que.push(make_pair(tx,ty));
						fld[tx][ty] = true;
					}
				}
			}
		}
	} 
	printf("%d\n",ans);
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("a.txt","r",stdin);
	#endif
	while(~scanf("%d %d",&w,&h) && (w != 0 ||  h != 0)){
		scanf("%d",&n);
		w++;h++;//全部增加一 
		per(i,0,n-1){
			scanf("%d %d %d %d",&xx1[i],&yy1[i],&xx2[i],&yy2[i]);
			xx1[i]++;xx2[i]++;yy1[i]++;yy2[i]++;//全部增加一 
		} 
		solve();
	}
	
	return 0; 
}
