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
int x1[maxn],x2[maxn],y1[maxn],y2[maxn];//�洢���� 
//��x1,x2����������ɢ������������ɢ����Ŀ��
bool fld[3*maxn][3*maxn]; 
int compress(int* x1,int* x2,int width){
	vector<int> xs;
	per(i,0,n-1){
		per(d,-1,1){
			int tx1 = x1[i] + d,tx2 = x2[i] + d;
			if(1 <= tx1 && tx1 <= width ){//����tx1>=0,����>=1,��Ϊ�����Ǵ�1��ʼ�ģ�
			//1�ǲ��е�,1������ı߽� 
				xs.push_back(tx1);
			}
			if(1 <= tx2 && tx2 <= width){
				xs.push_back(tx2);
			}
		}
	}
	
	sort(xs.begin(),xs.end());
	xs.erase(unique(xs.begin(),xs.end()),xs.end());//ɾ��ȥ�����еĺ������ж���Ԫ��
	//��Ϊunique��û��ɾ���ظ�Ԫ�أ�ֻ���ú���Ĳ��ظ�Ԫ������ظ�Ԫ��
	per(i,0,n-1){	//ֱ������ѹ�� 
	//	x1[i] = find(xs.begin(),xs.end(),x1[i]) - xs.begin();
		//x2[i] = find(xs.begin(),xs.end(),x2[i]) - xs.begin();
		x1[i] = lower_bound(xs.begin(),xs.end(),x1[i]) - xs.begin();
		x2[i] = lower_bound(xs.begin(),xs.end(),x2[i]) - xs.begin();
		//�����0�����ֵ����xs.size()-1 
	} 
	return xs.size();
}
void solve(){
	w = compress(x1,x2,w);
	h = compress(y1,y2,h);
	//cout << "mama " << h << " " << w << endl;
	//fill(fld[0],fld[0]+9*maxn*maxn,false);
	mem(fld,false);
	per(i,0,n-1){//����ǽ ,��Ϊѹ�������0���֣��������lower_bound()���� 
		per(x,x1[i],x2[i]){
			per(y,y1[i],y2[i]){
				//per(x,x1[i],x2[i]){
				fld[x][y] = true;
			}
		}
	}
 
	int ans = 0;
	per(x,0,w-1){//����1ѹ��ʱ ,lower_boundӰ��߽磬����ѹ��ǰ��ı߽�Ƚ��ǲ�ͬ�� 
		per(y,0,h-1){//֮ǰ�����ټ���1���½����27��������6 
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
				//cout << "nima\n";
				per(i,0,3){
					int tx = sx + dx[i],ty = sy + dy[i];
					if(0 <= tx && tx < w && 0 <= ty && ty < h && fld[tx][ty] != true){
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
		per(i,0,n-1){
			scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]);
		} 
		solve();
	}
	
	return 0; 
}
