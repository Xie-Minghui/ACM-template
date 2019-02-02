#include <vector>
#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

int Manacher(string s){
    // Insert '#'
    string t = "$#";//开始处，加一个$ 
    for (int i = 0; i < s.size(); ++i){//预处理 
        t += s[i];
        t += "#";
    }
    // Process t
    vector<int> p(t.size(), 0);
    int mx = 0, id = 0, resLen = 0, resCenter = 0;
    
    for (int i = 1; i < t.size(); ++i) {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;//关键代码 
        while (t[i + p[i]] == t[i - p[i]]) ++p[i];//不断遍历，更新p[i] 
        if (mx < i + p[i]){  //更新右边的最大值 
            mx = i + p[i];
            id = i;			//更新中点值 
        }
        if (resLen < p[i]) {//更新字符串长度 
            resLen = p[i];
            resCenter = i;	//更新中点值 
        }
    }
    //return s.substr((resCenter - resLen) / 2, resLen - 1);
	//从第(resCenter-resLen)开始截取resLen-1长度的字符串
    return resLen - 1 ;//resLen是以中心为原点，向两边拓展的值，其中中心算了两次，
	//所以resLen-1就是回文串的长度 
}

int main(){
	string str;
    while(cin >> str){
    	cout << Manacher(str) << endl;
	}
    return 0; 
}
