#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;
const int maxn = 1020;
string str1,str2;
int nex[maxn];//nex[i]表示nex[i]（除了本身）这个数的前面i个数
//既是前缀又是后缀（注意不是回文）的最长字符串的长度（也就是该前缀
//字符串的后一个位置，因为是s[i]匹配失败后，前nex[i]个字符已经知道可以直接
//匹配好的，所以下一个比较的位置就是该前缀字符串的后一个位置

void make_next(){
	nex[0] = -1;
	int j = 0,k = -1;
	while(j < str2.size()){
		if(k == -1 || str2[k] == str2[j]){
			if(str2[k+1] == str2[j+1]){ //当两个字符相等时要跳过
				nex[j+1] = nex[k+1];	//因为回退到k时，因为相等，就是多余的 
				++j,++k;
			}else{
				nex[j+1] = k+1;//不相等时，加1 
				++j,++k;
			}
		}else{
			k = nex[k];
		}
	}
}

int kmp(){
	
	int i = 0,j = 0;
	while(i < str1.size() && j < str2.size()){
		if( j == -1 || str1[i] == str2[j] ){
			++i;
			++j;
		}else{
			j = nex[j];
		}
	}
	if(j == str2.size()){
		return i - j;
	}else{
		return -1;
	}	
}
int main(){
	
	make_next();
	
	
	
	
	
	return 0;
} 
