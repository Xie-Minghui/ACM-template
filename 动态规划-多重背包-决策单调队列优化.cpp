#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 2e4 + 10;

int dp[maxn];
int que[maxn],used[maxn];
int head = 0,tail = 0;
int n = 0,m = 0;
int main(){
	scanf("%d %d",&n,&m);
	int val = 0,w = 0,num = 0;
	per(k,1,n){
		scanf("%d %d %d",&w,&val,&num);
		if(w * num >= m){//相当于第k种物品的使用没有限制，相当于完全背包
			per(j,w,m){
				dp[j] = max(dp[j],dp[j-w] + val);
			}
		}else{
			//因为质量为j的状态都是有与jmod w同余的质量转化过来的，所以只计算mod w同余的质量之间的转移
			per(i,0,w-1){//将质量根据mod w同余划分为等价类
				//然后从每个等价类中维护一个效应递减的单调队列
				//比如当前第k种物品质量为5，枚举的质量i为2，那么dp[2],dp[7],dp[12],dp[17]
				//等等都对应了一个dp[2],然后维护这个dp[2]效用递减的单调队列，同时记录每个
				//质量下对应的数量，来对第k中物品只有num个进行限制。
				head = tail = 0;
				for(int rest = 0;rest <= (m-i)/w;++rest){
					int now = dp[i + rest*w] - rest*val;
					while(head < tail && que[tail-1] <= now){
						--tail;
					}
					//如果是下面注释这种写法，也就是tail表示队列尾部元素位置，这时
					//队头head表示队头元素位置-1，所以要在下面所有的head+1，上面的que[tail-1]
					// que[++tail] = now; 
					// used[tail] = rest;
					//如过是下面这种写法，那么就是tail表示队尾元素位置+1,所以上面que[tail-1],
					//此时head表示的就是队头元素的位置
					used[tail] = rest;//记录这个重量下用了多少第k中物品
					que[tail++] = now;//记录使用了第k种物品rest个对应的dp[i]
					if(used[head] + num < rest){//如果当前最优的dp[i]对应的重量

					//为i+used[head]（此时第k种物品还一个都没有使用），然后加上第k种物品
					//的所有数量都小于当前i+rest*w那么表示没有那么多第k种物品
						++head;
					}
					dp[i + rest*w] = que[head] + rest * val;
				}
			}
		}
	}
	printf("%d\n",dp[m]);

	return 0;
}
