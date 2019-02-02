#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<algorithm>
#define INF 100000 
using namespace std;
const int maxn = 20000;
int ans = 0;
int L[maxn/2],R[maxn/2];
int A[maxn];
void merge(int l,int mid,int r){
	int n1 = mid - l;
	int n2 = r - mid;
	for(int i = 0;i < n1;++i){
		L[i] = A[l + i];
	}
	for(int i = 0;i < n2;++i){
		R[i] = A[mid + i];
	}
	L[n1] = R[n2] = INF;
	int i = 0,j = 0;
	for(int k = l;k < r;++k){
		if(L[i] <= R[j]){
			A[k] = L[i++];
		}else{
			ans++;
			A[k] = R[j++];
		}
	}
	
}
void merge_sort(int l,int r){
	if(l + 1 < r){
		int mid = (r - l)/2 + l;
		merge_sort(l,mid);
		merge_sort(mid,r);
		merge(l,mid,r);
	}
}

int main(){
	int size = 0;
	while(cin >> size && size){
	ans = 0;
	memset(A,0,sizeof(A));
	for(int i = 0;i < size;++i){
		cin >> A[i];
	}
	
	merge_sort(0,size);
	//cout << "After sorted:\n";
	//for(int i = 0;i < size;++i){
	//	cout << A[i] << " ";
	//}
	cout << ans << endl;
	cout << "\n";
	}
	return 0;
}
