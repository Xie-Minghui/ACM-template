#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

vector<int> G;//存储间隔 
long long cnt;
int A[1000000];
void insertionSort(int *A,int n,int g)
{
	for(int  i = g;i < n;i++){
		int j = i - g;
		int v = A[i];
		while(j >= 0 && A[j] > v){
			A[j+g] = A[j];
			j -= g;
			cnt++;
		}
		A[j+g]  = v;
	}
}
void shellSort(int *A,int n)
{
	for(int h = 1;;){
		if(h > n){
			break;
		}
		G.push_back(h);
		h = 3*h + 1;
	}
	for(int i = G.size() - 1;i >= 0;i--){
		insertionSort(A,n,G[i]);//从间距最大开始插入，希尔排序 
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		scanf("%d",&A[i]);
	}
	shellSort(A,n);
	printf("%lld\n",G.size());
	for(int i = G.size() - 1;i >= 0;i--){
		printf("%d",G[i]);
		if( i > 0)
			printf(" ");
	}
	printf("\n");
	printf("%lld\n",cnt);
	for(int i = 0;i < n;i++){
		printf("%d\n",A[i]);
	}
	return 0;
}
