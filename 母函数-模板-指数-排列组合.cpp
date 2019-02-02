#include <iostream>
#include<stdio.h>
#include<memory.h>
using namespace std;
int f(int n){//½×³Ë 
    int i,s=1;
	for(i=1; i<=n; i++)
        s=s*i;
    return s;
}
int main(){
    int n,m,i,j,k,num[12];
    double c1[12],c2[12];
    while(cin>>n>>m){
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(i=0; i<n; i++){
			 cin>>num[i];
		}
        for(i=0; i<=num[0]; i++)//¸³³õÖµ
			c1[i]=1.0/f(i);
		for(i=1; i<n; i++){
            for(j=0; j<=n; j++)
                for(k=0; k<=num[i]&&k+j<=n;k++)
                    c2[k+j]+=c1[j]/f(k);
            for(j=0; j<=n; j++){
			    c1[j]=c2[j];
                c2[j]=0;
            }
        }
       printf("%.llf\n",c1[m]*f(m));
	}

    return 0;

}
