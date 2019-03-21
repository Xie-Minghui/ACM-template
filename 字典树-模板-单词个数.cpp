#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<set>
using namespace std;//ͳ���ı��в�ͬ���ʵĸ��� 
const int maxn = 1e4 + 10;//ָ������Ե�һ��������Ū���ˣ�˵����������ָ������ѵ��ԭ�� 

struct node{
	int cnt;//cnt���Ա�ʾһ���ֵ��������ж�����ͬǰ׺����Ŀ�����������ҪӦ��ѧ�����ɱ仯
	node* nex[26];//next�Ǳ�ʾÿ���ж���������������ֻ��Сд��ĸ����26���ɣ�
	//����Ϊ��Сд��ĸ������52�����ټ������֣�����62�ˣ������
	bool used;
	node(){//�����ڹ��캯�� 
		cnt = 0;
		memset(nex,0,sizeof(nex));
		used = false;//����Ƿ��ù� 
	}

}; 
node *root = new node;//�½���һ���ռ䣬���ѵ�ַ��root����Ϊ����� 
 
void insert(string s){
	node* p = root;
	int len = s.size();
	for(int i = 0;i < len;++i){
		if(p->nex[s[i] - 'a'] == NULL){
			//cout << "qq: " << s << endl;
			node* temp = new node;
			p->nex[s[i] - 'a'] = temp;
		}
		p = p->nex[s[i] - 'a'];
		++p->cnt;
	}
}

int search(string s){
	node* p = root;
	//int len = strlen(s);
	int len = s.size();
	for(int i = 0;i < len;++i){
	//	cout << "pp: " << s << endl;
		if(p->nex[s[i] - 'a'] == NULL){
			return 0;
		}
		p = p->nex[s[i] - 'a'];
		if(i == len -1){//���һ��Ҫ���� 
			
			for(int j = 0;j < 26;++j){//���������ӽڵ㣬��������ӽڵ㣬˵��ֻ��ǰ׺����Ҫ++ans 
				if(p->nex[j] && p->used == false){//��������ǰ׺������ji,j 
					p->used = true;//used�ı����Ϊ�˿�ǰ׺���ֵĴ����������˵Ĳ����ټ��� 
					return 0;
				}
			}
		}
	}
	return p->cnt;//
}
void del(node* root){
	/*
	for(int i = 0;i < 10;++i){//���������ʧ�ܵ� 
		if(root->nex[i]){
			del(root->nex[i]);
		}
	}
		del(root);
	*/
	//delete root;//ԭ��ֻ���ͷ��˸����Ŀռ䣬������û���ͷ� 
	if(root == NULL){//�ͷ����пռ䣬��ֹ�ڴ�й¶ 
		return ;
	}else{
		for(int i = 0;i < 26;++i){//���������ʧ�ܵ� 
			if(root->nex[i]){
				del(root->nex[i]);
			}
		}
	}
	delete root;
}
int main(){
	
	string s,str;
	int flag = 0;
	while(getline(cin , s)){
		if(s == "#"){
			break;
		}
		int ans = 0;
		for(int i = 0;i < s.size();++i){
			str = "";
			flag = 0;
			while(s[i] >= 'a' && s[i] <= 'z'){
				str += s[i];
				flag = 1;
				++i;
			}
			//cout << "em " << str << endl;
			if(flag == 1){
				
				if(ans == 0){
					insert(str);
					//first = 0;
					++ans;
				}else 
				if(search(str) == 0){//ԭ�������� 
					insert(str);
					++ans;
				}
			}
			//cout << "f: " << ans << endl;
		}
		cout << ans << endl;
		
		del(root);//�ǵ�����ǰ��ģ���Ϊ���������һ��ָ���ʾ�ģ�����ֻҪ����ָ�뼴�� 
		root = new node;//�ǵû�Ҫ�½�һ�������������� 
	}
	
	
	return 0;
}
