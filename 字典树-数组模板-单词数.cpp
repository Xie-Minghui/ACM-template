#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<set>
using namespace std; 
const int maxn = 2e5,num = 26;
struct Trie{
	int ch[maxn][num];
	int val[maxn];//
	int id;
	Trie(){
		memset(ch,0,sizeof(ch));
		val[0] = 0;
	}
	
	int idx(char c){
		return c - 'a';
	}
	void insert(string s){
		int u = 0,len = s.size();
		for(int i = 0;i < len;++i){
			if(ch[u][idx(s[i])] == 0){//没有这个儿子 
				memset(ch[id],0,sizeof(ch[id]));
				ch[u][idx(s[i])] = id++;
			}
			u = ch[u][idx(s[i])];
			++val[u];
		}
	}
	
	int search(string s){
		int u = 0,len = s.size();
		for(int i = 0;i < len;++i){
			if(ch[u][idx(s[i])] == 0){
				//return false;
				return 0;
			}
			u = ch[u][idx(s[i])];
		}
		//return true;
		return val[u];
	}
};

int main(){
	
	
	string s,str;
	int flag = 0;
	while(getline(cin , s)){
		Trie t;
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
					t.insert(str);
					//first = 0;
					++ans;
				}else 
				if(t.search(str) == 0){//原来不存在 
					t.insert(str);
					++ans;
				}
			}
			//cout << "f: " << ans << endl;
		}
		cout << ans << endl;
		
		//del(root);//记得销毁前面的，因为根结点是用一个指针表示的，所以只要销毁指针即可 
		//root = new node;//记得还要新建一个，与后面的连续 
	}
	 
	
	
	return 0;
} 
