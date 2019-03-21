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
int xx1[maxn],xx2[maxn],yy1[maxn],yy2[maxn];//�洢���� 
//��x1,x2����������ɢ������������ɢ����Ŀ��
bool fld[3*maxn][3*maxn];  
int compress(int* xx1,int* xx2,int w){
	vector<int> xs;
	per(i,0,n-1){
		per(d,-1,1){
			int tx1 = xx1[i] + d,tx2 = xx2[i] + d;
			if(1 <= tx1 && tx1 <= w ){//����tx1>=0,����>=1,��Ϊ�����Ǵ�1��ʼ�ģ�
			//1�ǲ��е�,1������ı߽� 
				xs.push_back(tx1);
			}
			if(1 <= tx2 && tx2 <= w){
				xs.push_back(tx2);
			}
		}
	}
	
	sort(xs.begin(),xs.end());
	xs.erase(unique(xs.begin(),xs.end()),xs.end());//ɾ��ȥ�����еĺ������ж���Ԫ��
	//��Ϊunique��û��ɾ���ظ�Ԫ�أ�ֻ���ú���Ĳ��ظ�Ԫ������ظ�Ԫ��
	per(i,0,n-1){	//ֱ������ѹ�� 
		xx1[i] = find(xs.begin(),xs.end(),xx1[i]) - xs.begin() + 1;
		xx2[i] = find(xs.begin(),xs.end(),xx2[i]) - xs.begin() + 1;
	} 
	return xs.size();
}
//ѹ��ǰ�ı߽���1-w��ѹ������0-w-1������+1�����1-w-1(������1-w),����������һ
//֮�����ı߽�Ҫ��һ��ģ�������Ƿ�������꣬��������ǵ�����꣬������ҪһЩСת�� 
void solve(){
	w = compress(xx1,xx2,w);
	h = compress(yy1,yy2,h);
	//fill(fld[0],fld[0]+9*maxn*maxn,false);
	mem(fld,false);
	per(i,0,n-1){//����ǽ 
		per(x,xx1[i],xx2[i]-1){
			per(y,yy1[i],yy2[i]-1){
				fld[x][y] = true;
			}
		}
	}
	int ans = 0;
	per(x,1,w-1){
		per(y,1,h-1){//֮ǰ�����ټ���1���½����27��������6 
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
		w++;h++;//ȫ������һ 
		per(i,0,n-1){
			scanf("%d %d %d %d",&xx1[i],&yy1[i],&xx2[i],&yy2[i]);
			xx1[i]++;xx2[i]++;yy1[i]++;yy2[i]++;//ȫ������һ 
		} 
		solve();
	}
	
	return 0; 
}
