/*
ID:selfcon2
LANG:C++
PROG:fence8
*/
#include <fstream>
#include <cstdlib>
using namespace std;
ifstream fin("fence8.in");
ofstream fout("fence8.out");
static int barn[100],barn2[100],rail[1025],l,mid,rig,n,r;
static int sumbarn,sumrail[1025],sumleft,sumtodo,ans;
int cmp(const void * x,const void * y){return *(int *)x-*(int *)y;}
int dfs(int left,int deep,int step)
{
	int nleft,ni;
	if(deep==-1)return 1;
	//if(sumleft<sumtodo)return 0;
	for(int i=step;i<n;i++)
		if(barn[i]>=rail[deep])
		{
			barn[i]-=rail[deep];//sumleft-=rail[deep];sumtodo-=rail[deep];
			if(barn[i]<rail[0])
			{	
				nleft=left+barn[i];
				if(nleft+sumrail[ans]>sumbarn)
				{
					barn[i]+=rail[deep];
					continue;
				}
			}
			else nleft=left;
			if(deep>=1&&rail[deep]==rail[deep-1])ni=i;
			else ni=0;
			if(dfs(nleft,deep-1,ni))return 1;
			barn[i]+=rail[deep];//sumleft+=rail[deep];sumtodo+=rail[deep];
		}
	return 0;
}
int main()
{
	//init
	fin>>n;
	for(int i=0;i<n;i++)fin>>barn[i];
	qsort(barn,n,sizeof(barn[0]),cmp);
	for(int i=0;i<n;i++)
		if(i)sumbarn=sumbarn+barn[i];else sumbarn=barn[i];
	for(int i=0;i<n;i++)barn2[i]=barn[i];
		
	fin>>r;
	for(int i=0;i<r;i++)fin>>rail[i];
	qsort(rail,r,sizeof(rail[0]),cmp);
	for(int i=0;i<r;i++)
		if(i)sumrail[i]=sumrail[i-1]+rail[i];else sumrail[i]=rail[i];
	//work
	while(sumrail[r-1]>sumbarn)r--;
	for(ans=r-1;ans>=0;ans--)
	{
		//sumbarn[n-1];sumtodo=sumrail[i];
		for(int j=0;j<n;j++)barn[j]=barn2[j];
		if(dfs(0,ans,0)){fout<<ans+1<<endl;return 0;}
	}
	fout<<0<<endl;
	return 0;
}
/*
1.裸搜 第四个点TLE
2.有长度相同的木板
3,先切大的再切小的
*/

