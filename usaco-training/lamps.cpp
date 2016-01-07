/*
ID:selfcon2
LANG:C++
PROG:lamps
*/
#include <fstream>
#include <cstring>
#include <cctype>
#include <string>
#include <cstdlib>
using namespace std;
ifstream fin("lamps.in");
ofstream fout("lamps.out");
struct node{string str;};
static int n,c,a[200],b[200],tot=0;
static node ans[1000];
static bool s[200];
int cmp(const void * x,const void * y)
{
	return ((*(node *)x).str).compare((*(node *)y).str);
}
void check(int x)
{
	int i;
	if((c%2!=x%2)||(x>c))return;
	for(i=1;i<=a[0];i++)if(!s[a[i]])return;
	for(i=1;i<=b[0];i++)if(s[b[i]])return;
	for(i=1;i<=n;i++)if(s[i])ans[tot].str.push_back('1');else ans[tot].str.push_back('0');
	tot++;
}
void dfs(int x,int y)
{
	int i;
	if(x==5){check(y);return;}
	dfs(x+1,y);
	if(x==1)
	{
		for(i=1;i<=n;i++)s[i]=!s[i];
		dfs(x+1,y+1);
		for(i=1;i<=n;i++)s[i]=!s[i];
	}
	else if(x==2)
	{
		for(i=1;i<=n;i++)if(i%2)s[i]=!s[i];
		dfs(x+1,y+1);
		for(i=1;i<=n;i++)if(i%2)s[i]=!s[i];	
	}
	else if(x==3)
	{
		for(i=1;i<=n;i++)if(i%2==0)s[i]=!s[i];
		dfs(x+1,y+1);
		for(i=1;i<=n;i++)if(i%2==0)s[i]=!s[i];	
	}
	else
	{
		for(i=1;i<=n;i++)if(i%3==1)s[i]=!s[i];
		dfs(x+1,y+1);
		for(i=1;i<=n;i++)if(i%3==1)s[i]=!s[i];	
	}
}
int main()
{
	int t,i;
	memset(s,true,sizeof(s));memset(a,0,sizeof(a));memset(b,0,sizeof(b));
	fin>>n>>c;
	fin>>t;
	while(t!=-1)
	{
		a[0]++;
		a[a[0]]=t;
		fin>>t;
	}
	fin>>t;
	while(t!=-1)
	{
		b[0]++;
		b[b[0]]=t;
		fin>>t;
	}
	dfs(1,0);
	qsort(ans,tot,sizeof(ans[0]),cmp);
	for(i=0;i<tot;i++)fout<<ans[i].str<<endl;
	if(!tot)fout<<"IMPOSSIBLE\n";
	return 0;
}





