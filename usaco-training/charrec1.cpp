/*
ID:selfcon2
LANG:C++
PROG:charrec
*/
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
ifstream dictin("font.in");
ifstream fin("charrec.in");
ofstream fout("charrec.out");
const string ans=" abcdefghijklmnopqrstuvwxyz";
static string dict[27][20],todo[22];
static int f1[22],f2[22];
static int dictn,n;
int main()
{
	dictin>>dictn;
	dictn/=20;
	for(int i=0;i<dictn;i++)
		for(int j=0;j<20;j++)dictin>>dict[i][j];
	fin>>n;
	for(int i=0;i<n;i++)fin>>todo[i];
	if(n==20)
	{	
		int flag=0,ansn=1000000;
		for(int i=0;i<dictn;i++)
		{
			int t=0;
			for(int j=0;j<n;j++)
				for(int k=0;k<20;k++)
					if(todo[j][k]!=dict[i][j][k])t++;
			if(t<ansn){flag=i;ansn=t;}
		}
		fout<<ans[flag]<<endl;
	}
	else if(n==19)
	{
		int flag=0,ansn=1000000;
		for(int i=0;i<dictn;i++)
		{
			memset(f1,0,sizeof(f1));memset(f2,0,sizeof(f2));
			for(int j=0;j<n;j++)
				for(int k=0;k<19;k++)
				{	
					if(todo[j][k]!=dict[i][j][k])f1[j]++;
					if(todo[j][k]!=dict[i][j+1][k])f2[j]++;
				}
			for(int j=0;j<20;j++)
			{
				int t=0;				
				for(int k=0;k<j;k++)t+=f1[k];
				for(int k=j;k<n;k++)t+=f2[k];
				if(t<ansn){flag=i;ansn=t;}
			}
		}
		fout<<ans[flag]<<endl;
	}	
	else if(n==21)
	{
		int flag=0,ansn=1000000;
		for(int i=0;i<dictn;i++)
		{
			memset(f1,0,sizeof(f1));memset(f2,0,sizeof(f2));
			for(int j=0;j<n;j++)
				for(int k=0;k<20;k++)
				{	
					if(todo[j][k]!=dict[i][j][k])f1[j]++;
					if(todo[j+1][k]!=dict[i][j][k])f2[j]++;
				}
			for(int j=0;j<20;j++)
			{
				int t=0;				
				for(int k=0;k<=j;k++)t+=f1[k];
				for(int k=j+2;k<n;k++)t+=f2[k];
				if(t<ansn){flag=i;ansn=t;}
			}
		}
		fout<<ans[flag]<<endl;
	}
	return 0;
}
