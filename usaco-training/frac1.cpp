/*
ID:selfcon2
LANG:C++
PROG:frac1
*/
#include <fstream>
#include <cstdlib>
using namespace std;
ifstream fin("frac1.in");
ofstream fout("frac1.out");
struct node{int a,b;};
node ans[1000000];
int cmp(const void * x,const void * y){return ((*(node *)x).a*(*(node *)y).b-(*(node *)x).b*(*(node *)y).a);}
int gcd(int x,int y)
{
	if(x==0)return y;
	if(y==0)return x;	
	if(x<y)return gcd(x,y%x);
	else return gcd(y,x%y);
}
int main()
{
	int n,i,j,tot=0;
	fin>>n;
	ans[tot].a=0;ans[tot].b=1;tot++;
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
			if(gcd(i,j)==1){ans[tot].a=i;ans[tot].b=j;tot++;}
	qsort(ans,tot,sizeof(ans[0]),cmp);
	for(i=0;i<tot;i++)fout<<ans[i].a<<"/"<<ans[i].b<<endl;
	return 0;
}


