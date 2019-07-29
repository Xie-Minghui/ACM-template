#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string> 
#include<cstring>
#include<set>
#define INF 0x7fffffff
using namespace std;
const int maxn = 1000 + 10;
//线段树适合解决“相邻的区间的信息可以被合并成两个区间的并区间的信息”的问题
//当你的根结点是0时，左孩子 是2*i+1,有孩子是2*i+2 
//当你的根结点是1时，左孩子 是2*i,有孩子是2*i+1
struct SegTreeNode{
	int val;
	int add_mark;//延迟标记 
	//可以每个节点记录记录它记录区间的左边界和右边界
}seg_tree[maxn];//定义线段树 
/* 
功能：构建线段树
 root：当前线段树的根节点下标
 arr: 用来构造线段树的数组
 istart：数组的起始位置
 iend：数组的结束位置
*/
void build(int root,int arr[],int istart,int iend){ //递归构建线段树 
	seg_tree[root].add_mark = 0;//设置延迟标记域 
	
	if(istart == iend){		//叶子结点 
		seg_tree[root].val = arr[istart];
	}else{
		int mid = (iend - istart)/2 + istart;
		build(root * 2 + 1,arr,istart,mid);//递归构造左子树 
		build(root * 2 + 2,arr,mid + 1,iend);//递归构造右子树 
		//根据左右子树根结点的值，更新当前根节点的值 
		seg_tree[root].val = min(seg_tree[root*2+1].val,seg_tree[root*2+2].val);
		
	}
		
}
/*
 32 功能：当前节点的标志域向孩子节点传#
 33 root: 当前线段树的根节点下标
 34 */
void push_down(int root){
	if(seg_tree[root].add_mark != 0){
		//设置左右孩子节点的标志域，因为孩子节点可能被多次延迟标记又没有向下传递
       //所以是 “+=”
		seg_tree[root*2+1].add_mark += seg_tree[root].add_mark;
		seg_tree[root*2+2].add_mark += seg_tree[root].add_mark;
		//根据标志域设置孩子节点的值。因为我们是求区间最小值，因此当区间内每个元
        //素加上一个值时，区间的最小值也加上这个值
		seg_tree[root*2+1].val += seg_tree[root].add_mark;
		seg_tree[root*2+2].val += seg_tree[root].add_mark;
		//传递后，当前节点标记域清空
		seg_tree[root].add_mark = 0;
	}
}

/*
2 功能：线段树的区间查询
3 root：当前线段树的根节点下标
4 [nstart, nend]: 当前节点所表示的区间
5 [qstart, qend]: 此次查询的区间
6 */
 
int query(int root,int nstart,int nend,int qstart,int qend){//线段树的区间查询 
	int mid = (nend + nstart) >> 1;
	//查询区间与当前区间没有交集时 
	if(nend < qstart || nstart > qend){
		//这个和下面两个if判断同时注释掉,会段错误，另外这个部注释掉会WA，不能直接返回INF
		return INF;//根据实际情况决定这个if判断是否需要，因为有时候直接返回INF，导致运算错误
	//当前区间包含在查询区间内 
	}else if(nstart >= qstart && nend <= qend){
		push_down(root); //----延迟标志域向下传递，这个不知道正不正确
		return seg_tree[root].val;
	//当前区间部分包含在查询区间内 
	}else if(qend <= mid){//二分，这边是<=，因为左孩子记录的是[l,mid]的信息
		//--------------下面没有这样类似二分的函数，记得加上，这里就不加了
		return query(root*2+1,l,mid,qstart,qend);
	}else if(qstart > mid){//二分
		push_down(root); //----延迟标志域向下传递，这个不知道正不正确
		return query(root*2+2,mid+1,nend,qstart,qend);
	}else{
		push_down(root); //----延迟标志域向下传递
		
		
		//分别从左子树和右子树查询，返回两者查询结果的较小值 
		return min( query(root*2+1,nstart,mid,qstart,qend),
		query(root*2+2,mid+1,nend,qstart,qend) );
	}
	
}
/*
 2 功能：更新线段树中某个叶子节点的值
 3 root：当前线段树的根节点下标
 4 [nstart, nend]: 当前节点所表示的区间
 5 index: 待更新节点在原始数组arr中的下标
 6 addVal: 更新的值（原来的值加上addVal）
 7 */
void update_one(int root,int nstart,int nend,int index,int add_val){
	
	//if(nstart== nend && nstart == index){//错误，递归终止条件只是前者，
	//后者只是更新操作的条件,这将导致无限递归 
	 
	if(nstart == nend){		//递归终止条件 ，单点 
		
		if(nstart == index){//单点若等于所找的点 
			seg_tree[root].val += add_val;	
		}
		
		return ; 
	}
	
	int mid  = (nend - nstart)/2 + nstart;
	//二分搜索 
	if(index <= mid){
		//在左子树更新 
		update_one(root*2+1,nstart,mid,index,add_val);
	}else{
		//在右子树更新 
		update_one(root*2+2,mid+1,nend,index,add_val);
	}
	//根据左子树和右子树回溯更新当前节点的值 
	seg_tree[root].val = min(seg_tree[root*2+1].val,seg_tree[root*2+2].val);
}

/*
 75 功能：更新线段树中某个区间内叶子节点的值
 76 root：当前线段树的根节点下标
 77 [nstart, nend]: 当前节点所表示的区间
 78 [ustart, uend]: 待更新的区间
 79 addVal: 更新的值（原来的值加上addVal）
 80 */

void update(int root,int nstart,int nend,int ustart,int uend,int add_val){
	
	//更新区间和当前节点区间没有交集
	if(nend < ustart || nstart > uend){
		return ;
	//当前节点区间包含在更新区间内	
	}else if(nstart >= ustart && nend <= uend){
		
		seg_tree[root].add_mark += add_val;//注意区间更新时，add_mark 是 +=,val 是 +=  
		seg_tree[root].val += add_val;
		return ;
	}else{
		
		push_down(root);//延迟标记向下传递
		int mid = (nend - nstart)/2 + nstart;
		//更新左右孩子节点
		update(root*2+1,nstart,mid,ustart,uend,add_val);
		update(root*2+2,mid+1,nend,ustart,uend,add_val);
		 //根据左右子树的值回溯更新当前节点的值
		seg_tree[root].val = min(seg_tree[root*2+1].val,seg_tree[root*2+2].val);
	}
		
}

int main(){
	
	
	
	
	
	
	
	return 0;
}
