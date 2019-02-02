#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
void Maxmin(int *A,int l,int r,int &Max,int &Min)
{
	int x1,x2,y1,y2;
	int m;
	if(r - l <= 1){
		Min = min(A[l],A[r]);
		Max = max(A[l],A[r]);
	}
	else {
		m = (r - l)/2 + l;
		Maxmin(A,l,m,x1,y1);
		Maxmin(A,m,r,x2,y2);
		Max = max(x1,x2);
		//max = x1 >x2?x1:x2;
		Min = min(y1,y2);
	}
	
}
int main()
{
	freopen("maxmin.txt","r",stdin);
	int A[10];
	int max = 0,min = 0;
	for(int i = 0;i < 10;i++){
		scanf("%d",&A[i]);
	}
	Maxmin(A,0,9,max,min);
	printf("%d %d\n",max,min);
	
	
	return 0;
 } 
