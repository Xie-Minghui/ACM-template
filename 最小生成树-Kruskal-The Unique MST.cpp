#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#define INF  1e5
using namespace std;
const int maxn = 10000 + 10;//1e4���Թ���1e3RE 
//ע�⣬n<100,����������ȫͼ99*98���ߣ��ٿ�������ı߽� 
typedef long long LL;
struct MGraph{
	//char vertex[maxn];//�����   
	int edges[maxn][maxn];//�ڽӾ���,�ɿ����߱� 
	int n,e;//ͼ�е�ǰ�Ķ������ͱ���     
};
MGraph G;

struct Edge{
	int u;//�ߵ���ʼ����   
	int v; //�ߵ���ֹ����   
	int w;//�ߵ�Ȩֵ   
	bool flag ;
};
bool cmp(Edge a,Edge b){
	return a.w < b.w;
}
int e_size = 0; //�ߵ����� 
Edge E[maxn]; //������еı�  
int vset[maxn];//�������飬�ж����������Ƿ���ͨ 
void init(){
	int k = 1;//E������±��1��ʼ   
	for(int i = 1;i < G.n;++i){
		for(int j =i+1;j <= G.n;++j){
			if(G.edges[i][j] != INF){
				E[k].u = i,E[k].v = j,E[k].w = G.edges[i][j];
				E[k].flag = false;
				++k;
			}
		}
	}
	e_size = k - 1;
	//heapsort(E,k,sizeof(E[0])); 	
} 
int kruskal1(){//����С������ 
	int i,j,sn1,sn2,k;	
	for(i = 1;i <= G.n;++i){//��ʼ����������   
		vset[i] = i;
	}
	k = 1,j = 1;
	int res = 0;
	
	while(k < G.n){//���ɵı��������Ҫ�պ�Ϊ�ܱ���   
		sn1 = vset[E[j].u],sn2 = vset[E[j].v];//�õ����������ڵļ��ϱ��   
		if(sn1 != sn2){		//����ͬһ���ϱ���ڵĻ����ѱ߼�����С������   
			res += E[j].w;
			E[j].flag = true;//����Ѿ��ù� 
			++k;
			for(int i = 1;i <= G.n;++i){
				if(vset[i] == sn2){
					vset[i] = sn1;
				}
			}	
		}
		++j;
	}
	return res;
}
int kruskal2(int not_used){
	int i,j,sn1,sn2,k;

	for(i = 1;i <= G.n;++i){//��ʼ����������   
		vset[i] = i;
	}
	k = 1,j = 1;
	int res = 0;
	
	while(k < G.n){//���ɵı��������Ҫ�պ�Ϊ�ܱ���   
		if(j == not_used){			//�������õ� 
			++j;
			continue;
		}
		//vset[]����ʵ���ǲ��鼯�еĸ������� 
		sn1 = vset[E[j].u],sn2 = vset[E[j].v];//�õ����������ڵļ��ϱ��   
		if(sn1 != sn2){		//����ͬһ���ϱ���ڵĻ����ѱ߼�����С������  
		//�൱�ڲ��鼯����Ѱ���ĸ� 
			res += E[j].w;
			//E[j].flag = true;//����Ѿ��ù� 
			++k;
			for(int i = 1;i <= G.n;++i){
				if(vset[i] == sn2 ){
					vset[i] = sn1;
				}
			}	
		}
		++j;
	}
	return res;
}
bool full(){
	for(int i = 2;i <= G.n;++i){
		if(vset[i] != vset[1]){
			return false;
		}
	}
	return true;
}
int main(){
	int x = 0,y= 0,wt = 0;
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&G.n,&G.e);
		for(int i = 0;i <= G.n;++i){
			for(int j = 0;j <= G.n;++j){
				G.edges[i][j] = INF;
			}
		}
		for(int i = 1;i <= G.e;++i){
			scanf("%d %d %d",&x,&y,&wt);
			G.edges[x][y] = G.edges[y][x] = wt;
		}
		init();	
		sort(E+1,E+e_size+1,cmp);	
		LL ans1 = kruskal1();
		LL ans2 = 0,fg = 0;
		for(int i = 1;i <= e_size;++i){
			if(E[i].flag == true){
			/* 
				int temp = E[i].w;
				E[i].w = INF;
				sort(E+1,E+e_size+1,cmp);
				E[e_size].w = temp;
				sort(E+1,E+e_size+1,cmp);//���Ҫ��һ���򣬸�ԭ (֮ǰһֱWA��ԭ����ܾ������
				//����һ�ֱ�Ƿ�ʽ������ 
			*/
				ans2 = kruskal2(i);//Ѱ�Ҳ��õ��� i ����С������
				if(ans2 == ans1 && full()){//�����ҵ�д�������full�жϿ��п��� 
		//��Ҫ�����޷��γ���С������(��û�н����еĵ�������)
		//��ȴ�պ��з���ֵ��ȵ����(һ���ֵ����ı�Ȩֵ��)
					fg = 1;
					printf("Not Unique!\n");
					break;
				}
			}	
		}
		if(fg == 0){
			printf("%lld\n",ans1);
		}
		
	}
		
	return 0;
}
