#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<set>
using namespace std;//统计文本中不同单词的个数 
const int maxn = 1e4 + 10;//指针操作迷得一批，不过弄对了，说明你掌握了指针这个难点的原理 

struct node{
	int cnt;//cnt可以表示一个字典树到此有多少相同前缀的数目，这里根据需要应当学会自由变化
	node* nex[26];//next是表示每层有多少种类的数，如果只是小写字母，则26即可，
	//若改为大小写字母，则是52，若再加上数字，则是62了，这里根
	bool used;
	node(){//类似于构造函数 
		cnt = 0;
		memset(nex,0,sizeof(nex));
		used = false;//标记是否用过 
	}

}; 
node *root = new node;//新建立一个空间，并把地址给root，作为根结点 
 
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
		if(i == len -1){//最后一个要特判 
			
			for(int j = 0;j < 26;++j){//遍历他的子节点，如果还有子节点，说明只是前缀，还要++ans 
				if(p->nex[j] && p->used == false){//用来处理前缀，比如ji,j 
					p->used = true;//used的标记是为了看前缀出现的次数，出现了的不能再计算 
					return 0;
				}
			}
		}
	}
	return p->cnt;//
}
void del(node* root){
	/*
	for(int i = 0;i < 10;++i){//这个操作是失败的 
		if(root->nex[i]){
			del(root->nex[i]);
		}
	}
		del(root);
	*/
	//delete root;//原来只是释放了根结点的空间，其他的没有释放 
	if(root == NULL){//释放所有空间，防止内存泄露 
		return ;
	}else{
		for(int i = 0;i < 26;++i){//这个操作是失败的 
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
				if(search(str) == 0){//原来不存在 
					insert(str);
					++ans;
				}
			}
			//cout << "f: " << ans << endl;
		}
		cout << ans << endl;
		
		del(root);//记得销毁前面的，因为根结点是用一个指针表示的，所以只要销毁指针即可 
		root = new node;//记得还要新建一个，与后面的连续 
	}
	
	
	return 0;
}
