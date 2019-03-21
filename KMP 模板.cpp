#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;
const int maxn = 1020;
string str1,str2;
int nex[maxn];

void make_next(){
	nex[0] = -1;
	int j = 0,k = -1;
	while(j < str2.size()){
		if(k == -1 || str2[k] == str2[j]){
			if(str2[k+1] == str2[j+1]){ //�������ַ����ʱҪ����
				nex[j+1] = nex[k+1];	//��Ϊ���˵�kʱ����Ϊ��ȣ����Ƕ���� 
				++j,++k;
			}else{
				nex[j+1] = k+1;//�����ʱ����1 
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
