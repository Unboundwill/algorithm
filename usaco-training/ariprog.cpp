/*
ID:selfcon2
LANG:C++
PROB:ariprog
*/
#include <fstream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;
ifstream fin("ariprog.in");
ofstream fout("ariprog.out");
struct node{int a,b;};
node ans[10000];
int i,j,k,num,tot,n,m,B,c[30000];
bool a[280000],b[280000],flag;
int cmp(const void * x,const void * y)
{
	if((*(node *)x).b==(*(node *)y).b)return ((*(node *)x).a-(*(node *)y).a);
	else return ((*(node *)x).b-(*(node *)y).b);
}
int main()
{
	fin>>n>>m;memset(a,false,sizeof(a));memset(b,false,sizeof(b));
	for(i=0;i<=m;i++)a[i*i]=true;
	for(i=0;i<=m;i++)
		for(j=i*i;j<=2*m*m;j++)b[j]=a[j-i*i]||b[
			j];
	j=0;
	for(i=0;i<=2*m*m;i++)
		if(b[i]){c[j]=i;j++;}
	//for(i=0;i<j;i++)fout<<c[i]<<endl;	
	num=j;tot=0;
	for(i=0;i<num;i++)
		for(j=i+1;j<num;j++)
		{
			flag=true;
			B=c[j]-c[i];
			if(c[i]+B*(n-1)>2*m*m)flag=false;
			if(flag)
				for(k=2;k<=n-1;k++)if(!b[c[i]+k*B]){flag=false;break;}
			if(flag){ans[tot].a=c[i];ans[tot].b=B;tot++;}
		}
	qsort(ans,tot,sizeof(ans[0]),cmp);	
	for(i=0;i<tot;i++)fout<<ans[i].a<<" "<<ans[i].b<<endl;
	if(!tot)fout<<"NONE"<<endl;
	return 0;
}
