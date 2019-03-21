#include<iostream>
#include<string>
#include<vector>
#include<cstring> 
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 10;
int n = 0;
string str;

int min_rep(){
	int i = 1,j = 0,k = 0;
	while(i < n && j < n){
		k = 0;
		while(str[(i+k) % n] == str[(j+k) % n] && k < n){
			++k;
		}
		if(k == n){
			return i;
		}
		if(str[i+k] > str[j+k]){
			if(i +k +1 > j){
				i = i+k+1;	
			}else{
				i = j+1;
			}
			//i = max(i+k+1 ,j + 1);
		}else{
			if(j+k+1 > i){
				j = j+k+1;	
			}else{
				j = i+1;
			}
			//j = max(j+k+1, i+1);
		}
	}
	return i < j? i :j; 
}
int main(){
	int T = 0;
	//scanf("%d",&T);
	cin >> T;
	while(T--){
		//scanf("%d",&n);
		//scanf("%d",&)
		cin >> n;
		cin >> str;
		cout << min_rep() << endl;
		//cout << Mini() << endl;
	}
	
	return 0;
}
