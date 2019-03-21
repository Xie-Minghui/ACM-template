#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string> 
#include<cstring>
#include<set>
#define INF 0x7fffffff
using namespace std;
const int maxn = 1000 + 10;
//�߶����ʺϽ�������ڵ��������Ϣ���Ա��ϲ�����������Ĳ��������Ϣ��������
//����ĸ������0ʱ������ ��2*i+1,�к�����2*i+2 
//����ĸ������1ʱ������ ��2*i,�к�����2*i+1
struct SegTreeNode{
	int val;
	int add_mark;//�ӳٱ�� 
}seg_tree[maxn];//�����߶��� 
/* 
���ܣ������߶���
 root����ǰ�߶����ĸ��ڵ��±�
 arr: ���������߶���������
 istart���������ʼλ��
 iend������Ľ���λ��
*/
void build(int root,int arr[],int istart,int iend){ //�ݹ鹹���߶��� 
	seg_tree[root].add_mark = 0;//�����ӳٱ���� 
	
	if(istart == iend){		//Ҷ�ӽ�� 
		seg_tree[root].val = arr[istart];
	}else{
		int mid = (iend - istart)/2 + istart;
		build(root * 2 + 1,arr,istart,mid);//�ݹ鹹�������� 
		build(root * 2 + 2,arr,mid + 1,iend);//�ݹ鹹�������� 
		//������������������ֵ�����µ�ǰ���ڵ��ֵ 
		seg_tree[root].val = min(seg_tree[root*2+1].val,seg_tree[root*2+2].val);
		
	}
		
}
/*
 32 ���ܣ���ǰ�ڵ�ı�־�����ӽڵ㴫��
 33 root: ��ǰ�߶����ĸ��ڵ��±�
 34 */
void push_down(int root){
	if(seg_tree[root].add_mark != 0){
		//�������Һ��ӽڵ�ı�־����Ϊ���ӽڵ���ܱ�����ӳٱ����û�����´���
       //������ ��+=��
		seg_tree[root*2+1].add_mark += seg_tree[root].add_mark;
		seg_tree[root*2+2].add_mark += seg_tree[root].add_mark;
		//���ݱ�־�����ú��ӽڵ��ֵ����Ϊ��������������Сֵ����˵�������ÿ��Ԫ
        //�ؼ���һ��ֵʱ���������СֵҲ�������ֵ
		seg_tree[root*2+1].val += seg_tree[root].add_mark;
		seg_tree[root*2+2].val += seg_tree[root].add_mark;
		//���ݺ󣬵�ǰ�ڵ��������
		seg_tree[root].add_mark = 0;
	}
}

/*
2 ���ܣ��߶����������ѯ
3 root����ǰ�߶����ĸ��ڵ��±�
4 [nstart, nend]: ��ǰ�ڵ�����ʾ������
5 [qstart, qend]: �˴β�ѯ������
6 */
 
int query(int root,int nstart,int nend,int qstart,int qend){//�߶����������ѯ 
	
	//��ѯ�����뵱ǰ����û�н���ʱ 
	if(nend < qstart || nstart > qend){
		return INF;
	//��ǰ��������ڲ�ѯ������ 
	}else if(nstart >= qstart && nend <= qend){
		return seg_tree[root].val;
	//��ǰ���䲿�ְ����ڲ�ѯ������ 
	}else{
		push_down(root); //----�ӳٱ�־�����´���
		
		int mid = (nend - nstart)/2 + nstart;
		//�ֱ������������������ѯ���������߲�ѯ����Ľ�Сֵ 
		return min( query(root*2+1,nstart,mid,qstart,qend),
		query(root*2+2,mid+1,nend,qstart,qend) );
	}
	
}
/*
 2 ���ܣ������߶�����ĳ��Ҷ�ӽڵ��ֵ
 3 root����ǰ�߶����ĸ��ڵ��±�
 4 [nstart, nend]: ��ǰ�ڵ�����ʾ������
 5 index: �����½ڵ���ԭʼ����arr�е��±�
 6 addVal: ���µ�ֵ��ԭ����ֵ����addVal��
 7 */
void update_one(int root,int nstart,int nend,int index,int add_val){
	
	//if(nstart== nend && nstart == index){//���󣬵ݹ���ֹ����ֻ��ǰ�ߣ�
	//����ֻ�Ǹ��²���������,�⽫�������޵ݹ� 
	 
	if(nstart == nend){		//�ݹ���ֹ���� ������ 
		
		if(nstart == index){//�������������ҵĵ� 
			seg_tree[root].val += add_val;	
		}
		
		return ; 
	}
	
	int mid  = (nend - nstart)/2 + nstart;
	//�������� 
	if(index <= mid){
		//������������ 
		update_one(root*2+1,nstart,mid,index,add_val);
	}else{
		//������������ 
		update_one(root*2+2,mid+1,nend,index,add_val);
	}
	//���������������������ݸ��µ�ǰ�ڵ��ֵ 
	seg_tree[root].val = min(seg_tree[root*2+1].val,seg_tree[root*2+2].val);
}

/*
 75 ���ܣ������߶�����ĳ��������Ҷ�ӽڵ��ֵ
 76 root����ǰ�߶����ĸ��ڵ��±�
 77 [nstart, nend]: ��ǰ�ڵ�����ʾ������
 78 [ustart, uend]: �����µ�����
 79 addVal: ���µ�ֵ��ԭ����ֵ����addVal��
 80 */

void update(int root,int nstart,int nend,int ustart,int uend,int add_val){
	
	//��������͵�ǰ�ڵ�����û�н���
	if(nend < ustart || nstart > uend){
		return ;
	//��ǰ�ڵ���������ڸ���������	
	}else if(nstart >= ustart && nend <= uend){
		
		seg_tree[root].add_mark += add_val;//ע���������ʱ��add_mark �� +=,val �� +=  
		seg_tree[root].val += add_val;
		return ;
	}else{
		
		push_down(root);//�ӳٱ�����´���
		int mid = (nend - nstart)/2 + nstart;
		//�������Һ��ӽڵ�
		update(root*2+1,nstart,mid,ustart,uend,add_val);
		update(root*2+2,mid+1,nend,ustart,uend,add_val);
		 //��������������ֵ���ݸ��µ�ǰ�ڵ��ֵ
		seg_tree[root].val = min(seg_tree[root*2+1].val,seg_tree[root*2+2].val);
	}
		
}

int main(){
	
	
	
	
	
	
	
	return 0;
}
