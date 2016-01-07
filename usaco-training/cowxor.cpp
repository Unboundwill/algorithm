/*
ID:selfcon2
LANG:C++
PROG:cowxor
*/
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("cowxor.in");
ofstream fout("cowxor.out");
static int a[100005],b[100005];
static bool hash[8000000];
int n,ans=-1,ansn;
int main()
{
	fin>>n;
	if(n==1){fout<<"0 1 1"<<endl;return 0;}
	for(int i=1;i<=n;i++)
	{
		fin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	ans=b[1];ansn=1;
	for(int i=1;i<=n;i++)
	{	
		for(int j=20;j>=0;j--)
			hash[(b[i]>>j)+(1<<(21-j))]=true;
		int now=0;
		for(int j=20;j>=0;j--)
		{
			now+=(1<<j);
			if(hash[((now^b[i])>>j)+(1<<(21-j))])
			{
				if(now>ans)//||(now==ans&&a[i]>a[ansn]))
				{
					ans=now;ansn=i;
				}
			}
			else now-=(1<<j);
		}	
	}	
	fout<<ans;
	int i=ansn;
	while(i>=1&&(b[ansn]^b[i])!=ans)i--;
	fout<<" "<<i+1;
	fout<<" "<<ansn<<endl;
	return 0;
}
