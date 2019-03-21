#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int maxn = 1e5 + 10;
int tree[maxn];
int n = 0;
//输入的是对区间的操作，如果最终要求的是单点的值，
//那么updata区间1 - m更新操作 - 从上往下，单点求和操作 - 从下往上。
int lowbit(int x){
	return x & (-x);
} 
void add(int loc,int val){//在1 - loc位置增加val 

	while(loc > 0){  
		tree[loc] += val;
		loc -= lowbit(loc);	
	}
	
}
int getsum(int num){
	int sum = 0;
	while(num <= n){
		sum += tree[num];
		num += lowbit(num);
	}
	return sum;
}
/* 
void add(int loc,int val){//在loc位置增加val 
	if(loc < 1){
		return ;
	}
	for(int i = loc;i <= n;i += lowbit(i)){//单点更新，从叶子节点向上更新tree[]数组，是查询的逆过程 
		tree[i] += val;
	}
	
}
*/
/*
int getsum(int num){//从上到下 
	int ans = 0;
	for(int i = num;i > 0;i -= lowbit(i)){
		ans += tree[i];
	}
	return ans;
}
*/
int main(){
	
	std::ios::sync_with_stdio(false);
	int a = 0,b = 0;
	while(cin >> n && n){
	//while(scanf("%d",&n) != EOF && n){
		memset(tree,0,sizeof(tree));
		for(int i = 0;i < n;++i){
			cin >> a >> b;
			add(b,1);
			add(a - 1,-1);
			for(int j = 1;j <= n;++j){
				if(j > 1){
					cout << " ";
				}
				cout << tree[j] ;//<< endl;
			}
			cout << endl;
		}
		for(int j = 1;j <= n;++j){
			if(j != 1){
				cout << " "; 
			}
			cout << getsum(j);
		}
		cout << endl;
		
	}

	return 0;
}
