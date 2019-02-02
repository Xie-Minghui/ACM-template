#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct Node{
	int v, id;
};
Node a[N];
int rec[N];
set <Node> s;
bool operator <(Node x, Node y){
	if (x.v == y.v) return x.id < y.id;
	return x.v < y.v;
}
bool cmp(const Node& x, const Node& y){
	return x.v < y.v;
}
int main(){
	int n, m, d, cnt;
	set <Node>::iterator it;
	Node ntemp;
	scanf("%d %d %d",&n,&m,&d);
	for (int i = 1; i <= n; i++){
		scanf("%d",&a[i].v);
		a[i].id = i;
	}
	sort(a + 1, a + n + 1, cmp);
	cnt = 0;
	for (int i = 1; i <= n; i++){
		ntemp.v = a[i].v;
		ntemp.id = 0;
		it = s.upper_bound(ntemp);
		if (it == s.begin()){
			ntemp.v = a[i].v + d;
			ntemp.id = ++cnt;
			s.insert(ntemp);
			rec[a[i].id] = cnt;
		}
		else{
			it--;
			ntemp = *it;			
			rec[a[i].id] = ntemp.id;
			ntemp.v = a[i].v + d;
			s.erase(it);
			s.insert(ntemp);
		}
	}
	printf("%d\n",cnt);
	for (int i = 1; i <= n; i++) printf("%d ",rec[i]);
	printf("\n");
	return 0;
}
