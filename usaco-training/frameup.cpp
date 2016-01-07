/*
ID:selfcon2
LANG:C++
PROG:frameup
*/
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;
ifstream fin("frameup.in");
ofstream fout("frameup.out");
struct node{string str;}ans[10000];
static int n,m,num,tot;
static int d[50],a[50][50],b[50][50],c[50][50];
static int x1[50],x2[50],y1[50],y2[50],index1[50];
static char index2[50];
static bool vis[50];
int cmp(const void * x,const void * y)
{
	return (*(node *)x).str.compare((*(node *)y).str);
}
void topsort(int x,string s)
{
	vis[x]=true;
	s.push_back(index2[x]);
	int flag=1;
	for(int i=1;i<=num;i++)
	{
		d[i]-=c[x][i];
		c[x][i]=0;
	}
	for(int i=1;i<=num;i++)
		if(d[i]==0&&!vis[i])
		{
			flag=0;
			topsort(i,s);			
		}	
	if(flag)
	{
		string s2;
		for(int i=0;i<s.length();i++)s2.push_back(s[s.length()-i-1]);
		ans[tot].str=s2;
		tot++;	
	}	
	for(int i=1;i<=num;i++)
	{
		d[i]+=b[x][i];
		c[x][i]=b[x][i];
	}
	vis[x]=false;
}
int main()
{
	fin>>n>>m;
	for(int i=1;i<=26;i++)
	{
		x1[i]=m-1;
		x2[i]=0;
		y1[i]=0;
		y2[i]=n-1;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			char ch;
			fin>>ch;
			if(ch!='.')
			{	
				if(index1[ch-'A'+1]==0)
				{
					num++;
					index1[ch-'A'+1]=num;
					index2[num]=ch;
				}
				a[i][j]=index1[ch-'A'+1];
				x1[index1[ch-'A'+1]]=min(x1[index1[ch-'A'+1]],j);
				x2[index1[ch-'A'+1]]=max(x2[index1[ch-'A'+1]],j);
				y1[index1[ch-'A'+1]]=max(y1[index1[ch-'A'+1]],i);
				y2[index1[ch-'A'+1]]=min(y2[index1[ch-'A'+1]],i);
			}
		}
	//for(int i=0;i<n;i++)
	//{
	//	for(int j=0;j<m;j++)fout<<a[i][j];
	//	fout<<endl;
	//}	
	for(int i=1;i<=num;i++)
	{
		for(int j=y2[i];j<=y1[i];j++)
		{
			if(a[j][x1[i]]!=i)b[a[j][x1[i]]][i]=1;
			if(a[j][x2[i]]!=i)b[a[j][x2[i]]][i]=1;
		}
		for(int j=x1[i];j<=x2[i];j++)
		{
			if(a[y2[i]][j]!=i)b[a[y2[i]][j]][i]=1;
			if(a[y1[i]][j]!=i)b[a[y1[i]][j]][i]=1;
		}
	}	
	for(int i=1;i<=num;i++)
	{
		for(int j=1;j<=num;j++)
		{
			c[i][j]=b[i][j];//fout<<b[i][j];
			if(c[i][j])d[j]++;
		}
		//fout<<endl;
	}
	//for(int i=1;i<=num;i++)fout<<d[i]<<endl;
	//for(int i=1;i<=num;i++)fout<<x1[i]<<" "<<y1[i]<<" "<<x2[i]<<" "<<y2[i]<<endl;
	for(int i=1;i<=num;i++)
		if(d[i]==0)topsort(i,"");
	qsort(ans,tot,sizeof(ans[0]),cmp);
	for(int i=0;i<tot;i++)
		fout<<ans[i].str<<endl;
	return 0;
}


