#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#define INF  1e5
using namespace std;
const int maxn = 10000 + 10;

int par[maxn];//父亲 
int rak[maxn];//树的高度 
int n = 0;
//初始化n个元素 
void init(){
	for(int i = 1;i <= n;++i){
		par[i] = i;
		rak[i] = 0;
	}
}

//查询树的根 
int find(int x){
	if(par[x] == x){
		return x;
	}else{
		return par[x] = find(par[x]);
	}
}

//合并x和y所属的集合 
void unite(int x,int y){
	x = find(x),y = find(y);
	if(x == y){
		return ;
	}
	if(rak[x] < rak[y]){
		par[x] = y;
	}else{
		par[y] = x;
		if(rak[x] == rak[y]){
			++rak[x];
		}
	}
}

//判断x和y是否属于同一个集合 
bool same(int x,int y){
	return find(x) == find(y);
}

int main(){
	
	
	
	
	return 0;
}
