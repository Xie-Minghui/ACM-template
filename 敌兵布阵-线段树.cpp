#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string> 
#include<cstring>
#include<set>
#define INF 0x7fffffff
using namespace std;
const int maxn = 50000 + 10;
int n = 0;
char str[10];
struct SegTree{
	int l,r;		//��¼ÿ���ڵ������ʾ������ 
	int sum;		//�ڵ�����ʾ����ĺ� 
}stree[4 * maxn];
int arr[maxn];

void build(int root,int is,int ie){
	stree[root].l = is;
	stree[root].r = ie;
	
	if(is == ie){			//Ҷ�ӽ�� 
		stree[root].sum = arr[is];
		return ;
	}else{
		//if(root == 2){
		//	cout << ie << " " << is << endl;
		//}
		int mid = (ie - is)/2 + is;
		build(root*2,is,mid);
		build(root*2+1,mid + 1,ie); 
		stree[root].sum = stree[root*2].sum + stree[root*2+1].sum;
	}
	
}

void update_one(int root,int index,int add_val){
	
	if(stree[root].l == stree[root].r){
		if(stree[root].l == index){
			//if(root == 8){
			//	cout << stree[root].l << " " << stree[root].r << endl;
		//	}
			stree[root].sum += add_val;
		}
		return ;
	}
	int mid = (stree[root].r - stree[root].l)/2 + stree[root].l;
	//stree[index].sum += add_val;
	if(index <= mid){
		update_one(root*2,index,add_val);
	}else{
		update_one(root*2+1,index,add_val);
	}
	
	stree[root].sum = stree[root*2].sum + stree[root*2+1].sum;
}

int query(int root,int qs,int qe){
	
	//if(stree[root].l == stree[root].r && stree[root].l >= qs && stree[root].l <= qe){
		//���㣬���Ҹõ����������ҵ����䣬�򷵻�ֵ�����򲻷��أ�֮ǰ������������� 
	//	return stree[root].sum;
	///}else 
	if(stree[root].l > qe || stree[root].r < qs){
		//��ѯ�����뵱ǰ����û�н���ʱ  
		return 0;
	//}else if(stree[root].l == qs && stree[root].r == qe){
		//��ѯ�����뵱ǰ������ȫ�غ�ʱ 
	//	return stree[root].sum;
	}else if(qs <= stree[root].l && stree[root].r <= qe){
		//��ǰ��������ڲ�ѯ������ 
		return stree[root].sum;
	}else{	//��ǰ���䲿�ְ����ڲ�ѯ������ 
		//int mid = (stree[root].r - stree[root].l)/2 + stree[root].l;
		
		//return query(root*2,stree[root].l,mid) + query(root*2+1,mid+1,stree[root].r);
		return query(root*2,qs,qe) + query(root*2+1,qs,qe);
	}
	
	/*
	int mid = (stree[root].r - stree[root].l)/2 + stree[root].l;
	if(stree[root].l == qs && stree[root].r == qe){
		return stree[root].sum;
	}
	if(qs <= mid){
		query(root*2,qs,qe);
	}else if(mid > mid){
		query(root*2+1,qs,qe);
	}else{
		return query(root*2,stree[root].l,mid) + query(root*2+1,mid+1,stree[root].r);
	}
	
	*/
}
int main(){
	
	int T = 0,kase = 0,num = 0,loc = 0;
	scanf("%d",&T);
	while(T--){
		
		scanf("%d",&n);
		for(int i = 1;i <= n;++i){
			scanf("%d",&arr[i]);
		}
		build(1,1,n);
		printf("Case %d:\n",++kase);
		
		//for(int i = 0;i < 20;++i){
		//	cout << stree[i].sum << " ";
	//	}
	//	cout << endl;
		while(true){
			scanf("%s",str);//
			if(str[0] == 'E'){
				break;
			}else{
				
				scanf("%d %d",&loc,&num);
				
				if(str[0] == 'Q'){
					printf("%d\n",query(1,loc,num));
				}else if(str[0] == 'A' ){
					update_one(1,loc,num);
					/*
					for(int i = 0;i < 20;++i){
						cout << stree[i].sum << " ";
					}
					cout << endl;
					*/
				}else if(str[0] == 'S'){
					update_one(1,loc,-num);
				}
					
			}
		}	
	}
	
	return 0;
}

