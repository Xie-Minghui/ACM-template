#include<iostream>
#include<string>
#include<vector>
#include<cstring> 
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 10;
int data[maxn],p[2*maxn];
int len = 0;
void Manacher(){
	int t[maxn*2];
	t[0] = 0,t[1] = -1;
	for(int i = 1;i <= len;++i){
		t[2*i] = data[i];
		t[2*i+1] = -1;
	}
	t[2*len+2] = -2;//С�ģ�֮ǰ�����Ǽ��ˣ���Ϊ�ַ�����\0��β���Կ��Բ��ӣ�������ͷβ�Ӳ�һ���ı��
	 
	int mx = 0,id = 0;
	memset(p,0,sizeof(p));
	int size = 2 * len + 1;
	for(int i = 1;i <= size;++i){
		p[i] = mx > i? min(p[2*id-i] , mx - i) : 1;
		while(t[i + p[i] ] == t[ i - p[i]]){
			++p[i];
		}
		if(i + p[i] > mx){
			mx = i + p[i];
			id = i; 
		}
	}
}
int main(){
	int T = 0,kase = 0;
	//cin >> T;
	scanf("%d",&T);
	while(T--){
		//cin >> len;
		scanf("%d",&len);
		for(int i = 1;i <= len;++i ){
			//cin >> data[i];
			scanf("%d",&data[i]);
		}
		Manacher();
		/*
		for(int i = 1;i <= len*2+1;++i){
			cout << " " << p[i] - 1;
		} 
		cout << endl;
		 */
		int ans = 0;
		for(int i = 1;i <= 2*len+1;i += 2){//Ҫ��1��ʼ����Ϊ���Ĵ����ȿ�����ż�� 
		//������ξ��ǻ�ż��Ϊ���� ������һ�������������ǣ�����Ļ��Ĵ�����ż����
		//����ֻ��Ҫ�ڱ���������¾����� 
			//cout << "em " << p[i] - 1 << endl;
			for(int j =  i+ p[i] - 1;j - i > ans;j -= 2){
			//����Զ����������Ϊ�����������Ĵ�ֻ��һ�����ص�������2212122 122
			//2212122 ��22122����һ�����Ĵ�ֻ������22��ʵ��������һ����4����
			//�ڶ���22 ������ǽ��ⱨ������˵�� 
				if(j - i + 1 <= p[j]){//���г���С�ڵڶ����Ļ��Ĵ����� 
					ans = max( ans , j - i);
					break;
				}
			}
			
		}
		//cout << "Case #" << ++kase << ": " << ans / 2 * 3 << endl;
		printf("Case #%d: %d\n",++kase,ans / 2 * 3);//����ԭ����3/2 
	}
	
	return 0;
}
