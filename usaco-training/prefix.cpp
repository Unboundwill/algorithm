/*
ID:selfcon2
LANG:C++
PROG:prefix
*/
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
ifstream fin("prefix.in");
ofstream fout("prefix.out");
static string dict[200];
static char s[200005];
static bool f[200005];
int main()
{
	string ts;
	char ch;
	int dictn,tot,i,j;
	fin>>ts;dictn=0;
	while(ts!=".")
	{
		dict[dictn]=ts;
		dictn++;
		fin>>ts;	
	}
	tot=1;memset(f,false,sizeof(f));f[0]=true;
	while(fin>>ch)
	{
		s[tot]=ch;
		for(i=0;i<dictn;i++)
			if(tot>=dict[i].length())
			{
				int flag=1;
				for(j=dict[i].length()-1;j>=0;j--)if(s[tot-dict[i].length()+j+1]!=dict[i][j]){flag=0;break;}
				if(flag){f[tot]=f[tot-dict[i].length()]||f[tot];if(f[tot])break;}
			}	
		tot++;
	}
	tot--;
	//for(i=1;i<=tot;i++)fout<<f[i]<<endl;
	//for(i=1;i<=tot;i++)fout<<s[i];
	while(!f[tot])tot--;
	fout<<tot<<endl;
	//for(i=0;i<dictn;i++)fout<<dict[i]<<endl;
	return 0;
}


