#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int M  = 1000010 ; 
const int L = 14;
char H[M][L];

//���ַ�ת��Ϊ��ֵ
int getChar(char ch)
{
	if(ch == 'A')	return 1;
	else if(ch == 'C') return 2;
	else if(ch == 'G') return 3;
	else if(ch == 'T') return 4;
	else return 0;
 } 
 //���ַ���ת��Ϊ��ֵ������key
 long long getKey(char str[])
 {
 	long long sum = 0, p = 1;
 	for(size_t i = 0;i < strlen(str);i++){
 		sum = p*(getChar(str[i]));
 		p *= 5;
	 }
	 return sum;
} 
int h1(long long key)
{
	return key % M;
}

int h2(long long key)
{
	return 1 + (key % (M-1));
}

int hf(long long key,int i)//���ŵ�ַ�� 
{
	return ( h1(key) + i * h2(key)) % M;
}

int find(char str[])
{
	long long key, i ,h;
	key = getKey(str);
	for(i = 0; ;i++){
		h = hf(key,i);
		if(strcmp(H[h] , str) == 0) return 1;
		else if(strlen(H[h]) == 0) 	return 0;
	}
	return 0;
}

int insert(char str[])
{
	long long key,i,h;
	key = getKey(str);
	for(i = 0; ; i++){
		h = hf(key,i);
		if(strcmp(H[h],str) == 0)	return 1;//ԭ�����и�Ԫ�� 
		else if (strlen(H[h]) == 0){	//�ҵ��µĿ�λ�� 
			strcpy(H[h],str);
			return 0;
		}
	}
	return 0;
}

int main()
{
	int n;
	char str[L],com[9];
	for(int i = 0;i < M;i++){
		H[i][0] = '\0';			//��ʼ������� 
	}
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		scanf("%s %s",com,str);
	
		if(com[0] == 'i'){
			insert(str);
		}
		else{
			if(find(str)){
				printf("yes\n");
			}
			else{
				printf("no\n");
			}
		} 
	}
	return 0;
}






