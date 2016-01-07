/*
ID:selfcon2
LANG:C++
PROG:runround
*/
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("runround.in");
ofstream fout("runround.out");
static int m;
static bool hash[20],vis[20];
int check()
{
	int t=m,tot=0,i,a[20],b[20];
	memset(hash,false,sizeof(hash));
	while(t){b[tot]=t%10;tot++;if(hash[t%10])return 0;hash[t%10]=true;t/=10;}
	for(i=0;i<tot;i++)a[i]=b[tot-i-1];
	//for(i=0;i<tot;i++)fout<<a[i];
	memset(vis,false,sizeof(vis));
	int pre=a[0],pos=0;
	for(i=0;i<tot;i++)
	{
		pos=(pos+pre)%tot;if(vis[pos])return 0;vis[pos]=true;
		pre=a[pos];
	}
	if(pos!=0)return 0;
	return 1;
}
int main()
{
	fin>>m;m++;
	while(!check())m++;
	fout<<m<<endl;
	return 0;	
}

