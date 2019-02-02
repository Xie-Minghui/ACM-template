#include<iostream>
#include<string>
#include<vector>
#include<cstring> 
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 10;
int data[maxn],p[2*maxn];
int len = 0;
void Manacher(){
	int t[maxn*2];
	t[0] = 0,t[1] = -1;
	for(int i = 1;i <= len;++i){
		t[2*i] = data[i];
		t[2*i+1] = -1;
	}
	t[2*len+2] = -2;//小心，之前都忘记加了，因为字符串以\0结尾所以可以不加，但数组头尾加不一样的标记
	 
	int mx = 0,id = 0;
	memset(p,0,sizeof(p));
	int size = 2 * len + 1;
	for(int i = 1;i <= size;++i){
		p[i] = mx > i? min(p[2*id-i] , mx - i) : 1;
		while(t[i + p[i] ] == t[ i - p[i]]){
			++p[i];
		}
		if(i + p[i] > mx){
			mx = i + p[i];
			id = i; 
		}
	}
}
int main(){
	int T = 0,kase = 0;
	//cin >> T;
	scanf("%d",&T);
	while(T--){
		//cin >> len;
		scanf("%d",&len);
		for(int i = 1;i <= len;++i ){
			//cin >> data[i];
			scanf("%d",&data[i]);
		}
		Manacher();
		/*
		for(int i = 1;i <= len*2+1;++i){
			cout << " " << p[i] - 1;
		} 
		cout << endl;
		 */
		int ans = 0;
		for(int i = 1;i <= 2*len+1;i += 2){//要从1开始，因为回文串长度可能是偶数 
		//添加修饰就是化偶数为奇数 ，还有一个隐含条件就是，所求的回文串都是偶数，
		//所以只需要在标记上做文章就行了 
			//cout << "em " << p[i] - 1 << endl;
			for(int j =  i+ p[i] - 1;j - i > ans;j -= 2){
			//从最远处遍历，因为可能两个回文串只有一部分重叠，比如2212122 122
			//2212122 与22122，第一个回文串只贡献了22，实际上它的一半有4个，
			//第二个22 ，这就是解题报告中所说的 
				if(j - i + 1 <= p[j]){//共有长度小于第二个的回文串长度 
					ans = max( ans , j - i);
					break;
				}
			}
			
		}
		//cout << "Case #" << ++kase << ": " << ans / 2 * 3 << endl;
		printf("Case #%d: %d\n",++kase,ans / 2 * 3);//答案是原来的3/2 
	}
	
	return 0;
}
