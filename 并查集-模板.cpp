#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#define INF  1e5
using namespace std;
const int maxn = 10000 + 10;

int par[maxn];//���� 
int rak[maxn];//���ĸ߶� 
int n = 0;
//��ʼ��n��Ԫ�� 
void init(){
	for(int i = 1;i <= n;++i){
		par[i] = i;
		rak[i] = 0;
	}
}

//��ѯ���ĸ� 
int find(int x){
	if(par[x] == x){
		return x;
	}else{
		return par[x] = find(par[x]);
	}
}

//�ϲ�x��y�����ļ��� 
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

//�ж�x��y�Ƿ�����ͬһ������ 
bool same(int x,int y){
	return find(x) == find(y);
}

int main(){
	
	
	
	
	return 0;
}
