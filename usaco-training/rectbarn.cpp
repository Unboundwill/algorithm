/*
ID:selfcon2
LANG:C++
PROG:rectbarn
*/
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("rectbarn.in");
ofstream fout("rectbarn.out");
const int INF=1<<25;
int ans,n,m,p;
bool a[3005][3005];
int h1[3005],h2[3005],l1[3005],l2[3005];
int r1[3005],r2[3005],tl1[3005],tl2[3005],tr1[3005],tr2[3005];
int main()
{
	fin>>n>>m>>p;
	for(int i=0;i<p;i++)
	{
		int t1,t2;
		fin>>t1>>t2;
		a[t1][t2]=true;
	}	
	for(int i=1;i<=m;i++)
	{
		l1[i]=INF;r1[i]=INF;		
	}	
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
				if(!a[i][j])tl2[j]=tl2[j-1]+1;
				else tl2[j]=0;
			for(int j=m;j>=1;j--)
				if(!a[i][j])tr2[j]=tr2[j+1]+1;
				else tr2[j]=0;
			for(int j=1;j<=m;j++)	
			{	
				if(!a[i][j])
				{
					h2[j]=h1[j]+1;
					l2[j]=min(l1[j],tl2[j]);
					r2[j]=min(r1[j],tr2[j]);
				}	
				else 
				{
					h2[j]=0;l2[j]=INF;r2[j]=INF;
				}
				ans=max(ans,h2[j]*(l2[j]+r2[j]-1));
			}
		}
		else
		{
			for(int j=1;j<=m;j++)
				if(!a[i][j])tl1[j]=tl1[j-1]+1;
				else tl1[j]=0;
			for(int j=m;j>=1;j--)
				if(!a[i][j])tr1[j]=tr1[j+1]+1;
				else tr1[j]=0;
			for(int j=1;j<=m;j++)	
			{
				if(!a[i][j])
				{
					h1[j]=h2[j]+1;
					l1[j]=min(l2[j],tl1[j]);
					r1[j]=min(r2[j],tr1[j]);
				}	
				else 
				{
					h1[j]=0;l1[j]=INF;r1[j]=INF;
				}
				ans=max(ans,h1[j]*(l1[j]+r1[j]-1));
			}
		}	
	}
	fout<<ans<<endl;
	return 0;	
}
