//3824运算游戏 
/*此题的启发： 
	结构化编程思想，将一个大功能分成多个功能不同的小模块
	首先是拆分功能，然后是找共性，转化与化归，将看似复杂的问题转化为一个简单的问题，
	找到问题中的不变量 
*/ 
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<stdexcept>
using namespace std;

string trans_flag(int flag){//符号翻译
	 switch (flag) {
             case 0:
                    return "+";
             case 1:
                    return "-";
             case 2:
                    return "*";
             case 3:
                    return "/";
             case 4:
                    return "倒-";
             case 5:
                   return "倒/";
    }
    throw invalid_argument("无符合条件的运算符号");
     
}

double oneComputer(double d1,double d2,int flag){//两个数之间的运算
	switch(flag){
		case 0:
			return d1 + d2;
		case 1:
			return d1 - d2;
		case 2:
			return d1 * d2;
		case 3:
			if(d2 == 0){
				throw invalid_argument("出现0除异常");
			}else
				return d1 / d2;
		case 4:
			return d2 - d1;	
		case 5:
			if(d1 == 0){
				throw invalid_argument("出现0除异常");
			}else
				return d2 / d1;
		
	}
	throw invalid_argument("无符合条件的运算符号");
}

void one_serial1(int a,int b,int c,int d){//固定排列下结构1算法的6*6*6进行穷举运算
	for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 6; k++) {
            	try{
            		double t1 = oneComputer(a,b,i);
            		double t2 = oneComputer(c,d,k);
            		double results = oneComputer(t1,t2,j);
            		if(results == 24){
            		//	printf("("  a  trans_flag(i)  b ")"  transFlag(j) "(" c + 
					//	+ transFlag(k) + d")");
					cout << "("  <<  a << trans_flag(i) << b << ")" 
					<<  trans_flag(j) << "(" << c << trans_flag(k) << d << ")" 
					<< " =  24" << endl;
					//	+ transFlag(k) + d")");
					}
				}catch(invalid_argument &e){
					cout <<	e.what() << endl;//
				}
				
            }
        }
    }
}
void one_serial2(int a,int b,int c,int d){//固定排列下结构2算法的6*6*6进行穷举运算
	for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 6; k++) {
            	try{
            		double t1 = oneComputer(a,b,i);
            		double t2 = oneComputer(t1,c,k);
            		double results = oneComputer(t2,d,j);
            		if(results == 24){
            			//printf("((" + a + transFlag(i) + b ")" + transFlag(j) + c + ")"
						//+ transFlag(k) + d);
					cout <<"((" << a << trans_flag(i) << b <<")" << trans_flag(j) <<
					 c << ")" << trans_flag(k) << d << " =  24" << endl; 
						//+ transFlag(k) + d);
					}
				}catch(invalid_argument &e){
					cout << e.what()<< endl;//
				}
				
            }
        }
    }
}



void all_serial(int data[]){// 4个数的所有排列组合4*3*2进行穷举运算
	for(int i = 0;i < 4;i++){
		for(int j = 0;j < 4;j++){
			for(int k = 0;k < 4;k++){
				for(int h = 0;h < 4;h++){
					if(i != j && i != k && i != h && j != k && j != h && k != h) {// 满足一个有效排列)
						one_serial1(data[i], data[j], data[k], data[h]);
                        one_serial2(data[i], data[j], data[k], data[h]);
					}
				}
			}
		}
	}
} 
int main(){
	void all_serial(int data[]);
	void one_serial1(int a,int b,int c,int d);
	void one_serial2(int a,int b,int c,int d);
	double oneComputer(double d1,double d2,int flag);
	string trans_flag(int flag);
	int data[4];
	for(int i = 0;i < 4;i++){
		cin >> data[i];
	} 
	try{
		all_serial(data);
	}
	catch(invalid_argument e){
		cout << e.what() << endl;
	}

	
	return 0;
}
/*
	Name: 
	Copyright: 
	Author: 
	Date: 15/07/18 17:58
	Description: 
*/
