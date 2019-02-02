#include <vector>
#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

int Manacher(string s){
    // Insert '#'
    string t = "$#";//��ʼ������һ��$ 
    for (int i = 0; i < s.size(); ++i){//Ԥ���� 
        t += s[i];
        t += "#";
    }
    // Process t
    vector<int> p(t.size(), 0);
    int mx = 0, id = 0, resLen = 0, resCenter = 0;
    
    for (int i = 1; i < t.size(); ++i) {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;//�ؼ����� 
        while (t[i + p[i]] == t[i - p[i]]) ++p[i];//���ϱ���������p[i] 
        if (mx < i + p[i]){  //�����ұߵ����ֵ 
            mx = i + p[i];
            id = i;			//�����е�ֵ 
        }
        if (resLen < p[i]) {//�����ַ������� 
            resLen = p[i];
            resCenter = i;	//�����е�ֵ 
        }
    }
    //return s.substr((resCenter - resLen) / 2, resLen - 1);
	//�ӵ�(resCenter-resLen)��ʼ��ȡresLen-1���ȵ��ַ���
    return resLen - 1 ;//resLen��������Ϊԭ�㣬��������չ��ֵ�����������������Σ�
	//����resLen-1���ǻ��Ĵ��ĳ��� 
}

int main(){
	string str;
    while(cin >> str){
    	cout << Manacher(str) << endl;
	}
    return 0; 
}
